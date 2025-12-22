#include "pch.h"
#include "imgui_ext.h"

namespace imgui_ext
{
    ImColor ColorScale(const ImColor& color, float brightnessFactor)
    {
        ImVec4 col = color.Value;
        col.x = ImClamp(col.x * brightnessFactor, 0.0f, 1.0f);
        col.y = ImClamp(col.y * brightnessFactor, 0.0f, 1.0f);
        col.z = ImClamp(col.z * brightnessFactor, 0.0f, 1.0f);
        col.w = ImClamp(col.w, 0.0f, 1.0f);
        return ImColor(col);
    }
    void AddRectFilledMultiColorRounded(const ImVec2& p_min, const ImVec2& p_max, ImU32 col_upr_left, ImU32 col_upr_right, ImU32 col_bot_right, ImU32 col_bot_left, float rounding, bool filled, ImDrawFlags flags)
    {
        if (((col_upr_left | col_upr_right | col_bot_right | col_bot_left) & IM_COL32_A_MASK) == 0)
            return;

        ImDrawList* drawList = ImGui::GetWindowDrawList();
        if ((flags & ImDrawFlags_RoundCornersMask_) == 0)
            flags |= ImDrawFlags_RoundCornersAll;

        if (rounding > 0.0f)
        {
            const int size_before = drawList->VtxBuffer.Size;
            if (filled)
                drawList->AddRectFilled(p_min, p_max, IM_COL32_WHITE, rounding, flags);
            else
                drawList->AddRect(p_min, p_max, IM_COL32_WHITE, rounding, flags);
            const int size_after = drawList->VtxBuffer.Size;
            for (int i = size_before; i < size_after; i++)
            {
                ImDrawVert* vert = drawList->VtxBuffer.Data + i;
                ImVec4 upr_left = ImGui::ColorConvertU32ToFloat4(col_upr_left);
                ImVec4 bot_left = ImGui::ColorConvertU32ToFloat4(col_bot_left);
                ImVec4 up_right = ImGui::ColorConvertU32ToFloat4(col_upr_right);
                ImVec4 bot_right = ImGui::ColorConvertU32ToFloat4(col_bot_right);
                float X = ImClamp((vert->pos.x - p_min.x) / (p_max.x - p_min.x), 0.0f, 1.0f);
                float r1 = upr_left.x + (up_right.x - upr_left.x) * X;
                float r2 = bot_left.x + (bot_right.x - bot_left.x) * X;
                float g1 = upr_left.y + (up_right.y - upr_left.y) * X;
                float g2 = bot_left.y + (bot_right.y - bot_left.y) * X;
                float b1 = upr_left.z + (up_right.z - upr_left.z) * X;
                float b2 = bot_left.z + (bot_right.z - bot_left.z) * X;
                float a1 = upr_left.w + (up_right.w - upr_left.w) * X;
                float a2 = bot_left.w + (bot_right.w - bot_left.w) * X;
                float Y = ImClamp((vert->pos.y - p_min.y) / (p_max.y - p_min.y), 0.0f, 1.0f);
                float r = r1 + (r2 - r1) * Y;
                float g = g1 + (g2 - g1) * Y;
                float b = b1 + (b2 - b1) * Y;
                float a = a1 + (a2 - a1) * Y;
                ImVec4 RGBA(r, g, b, a);
                RGBA = RGBA * ImGui::ColorConvertU32ToFloat4(vert->col);
                vert->col = ImColor(RGBA);
            }
            return;
        }
        const ImVec2 uv = drawList->_Data->TexUvWhitePixel;
        drawList->PrimReserve(6, 4);
        drawList->PrimWriteIdx((ImDrawIdx)(drawList->_VtxCurrentIdx)); drawList->PrimWriteIdx((ImDrawIdx)(drawList->_VtxCurrentIdx + 1)); drawList->PrimWriteIdx((ImDrawIdx)(drawList->_VtxCurrentIdx + 2));
        drawList->PrimWriteIdx((ImDrawIdx)(drawList->_VtxCurrentIdx)); drawList->PrimWriteIdx((ImDrawIdx)(drawList->_VtxCurrentIdx + 2)); drawList->PrimWriteIdx((ImDrawIdx)(drawList->_VtxCurrentIdx + 3));
        drawList->PrimWriteVtx(p_min, uv, col_upr_left);
        drawList->PrimWriteVtx(ImVec2(p_max.x, p_min.y), uv, col_upr_right);
        drawList->PrimWriteVtx(p_max, uv, col_bot_right);
        drawList->PrimWriteVtx(ImVec2(p_min.x, p_max.y), uv, col_bot_left);
    }
    bool ButtonImage(const char* label, const ImVec2& size_arg, void* texture, bool hideBG, float minTextureAnimTint, ImGuiButtonFlags flags, ImVec2 padding, ImVec4 tintColor)
    {
        using namespace ImGui;
        ImGuiWindow* window = GetCurrentWindow();
        if (window->SkipItems) return false;
        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, padding);
        ImGuiContext& g = *GImGui;
        const ImGuiStyle& style = g.Style;
        const ImGuiID id = window->GetID(std::format("{}_{}", label, (uintptr_t)texture).c_str());
        const ImVec2 label_size = CalcTextSize(label, NULL, true);
        float globalAlpha = hideBG ? 0.0f : style.Alpha;
        ImVec2 pos = window->DC.CursorPos;
        if ((flags & ImGuiButtonFlags_AlignTextBaseLine) && style.FramePadding.y < window->DC.CurrLineTextBaseOffset)
            pos.y += window->DC.CurrLineTextBaseOffset - style.FramePadding.y;
        ImVec2 size = CalcItemSize(size_arg, label_size.x + style.FramePadding.x * 2.0f, label_size.y + style.FramePadding.y * 2.0f);
        if (texture)
        {
            if (size_arg.x == 0.0f && size_arg.y == 0.0f && (size.x - label_size.x) < label_size.y)
            {
                size.x += label_size.y;
                if (label_size.x > 0.0f)
                    size.x += style.ItemSpacing.x;
            }
        }
        const ImRect bb(pos, pos + size);
        ItemSize(size, style.FramePadding.y);
        if (!ItemAdd(bb, id))
        {
            ImGui::PopStyleVar();
            return false;
        }
        bool hovered, held;
        const bool pressed = ButtonBehavior(bb, id, &hovered, &held, flags);
        if (hovered)
            SetMouseCursor(ImGuiMouseCursor_Hand);
        const ImU32 col = GetColorU32((held && hovered) ? ImGuiCol_ButtonActive : hovered ? ImGuiCol_ButtonHovered : ImGuiCol_Button);
        ImVec4 darkCol = ColorScale(col, 0.85f);
        RenderNavCursor(bb, id);
        AddRectFilledMultiColorRounded(
            bb.Min,
            bb.Max,
            GetColorU32(col, globalAlpha),
            GetColorU32(col, globalAlpha),
            GetColorU32(ColorConvertFloat4ToU32(darkCol), globalAlpha),
            GetColorU32(ColorConvertFloat4ToU32(darkCol), globalAlpha),
            style.FrameRounding,
            true,
            ImDrawFlags_RoundCornersAll
        );
        if (g.LogEnabled)
            LogSetNextTextDecoration("[", "]");
        if (texture)
        {
            ImVec2 start = bb.Min + style.FramePadding;
            ImVec2 iconSize{ label_size.y, label_size.y };
            float animColorScale = hovered ? 1.0f : minTextureAnimTint;
            tintColor.x *= animColorScale;
            tintColor.y *= animColorScale;
            tintColor.z *= animColorScale;
            tintColor.w = style.Alpha;
            window->DrawList->AddImage(
                (ImTextureID)(intptr_t)texture,
                start,
                start + iconSize,
                ImVec2(0, 0),
                ImVec2(1, 1),
                GetColorU32(tintColor)
            );
            if (label_size.x > 0.0f)
            {
                RenderTextClipped(
                    start + ImVec2(iconSize.x + style.ItemSpacing.x, 0.0f),
                    bb.Max - style.FramePadding,
                    label,
                    NULL,
                    &label_size,
                    style.ButtonTextAlign,
                    &bb);
            }
        }
        else
        {
            RenderTextClipped(
                bb.Min + style.FramePadding,
                bb.Max - style.FramePadding,
                label,
                NULL,
                &label_size,
                style.ButtonTextAlign,
                &bb);
        }
        ImGui::PopStyleVar();
        IMGUI_TEST_ENGINE_ITEM_INFO(id, label, g.LastItemData.StatusFlags);
        return pressed;
    }
}