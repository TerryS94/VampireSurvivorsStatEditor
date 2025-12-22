#include "pch.h"
#include "dx11stuff.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include "icons.h"

namespace DX11
{
    ID3D11Device* g_Device = nullptr;
    ID3D11DeviceContext* g_Context = nullptr;
    IDXGISwapChain* g_Swapchain = nullptr;
    ID3D11RenderTargetView* g_RTV = nullptr;
    float clearColor[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
    HWND g_Window = nullptr;
    static std::map<ETextureID, ID3D11ShaderResourceView*> textures;

    ID3D11ShaderResourceView* GetTextureByName(ETextureID id)
    {
        if (DX11::textures.contains(id))
            return DX11::textures[id];
        return nullptr;
    }
    ID3D11ShaderResourceView* LoadTextureFromMemoryDX11(const void* data, size_t size)
    {
        if (!data || size == 0) return nullptr;
        int width = 0;
        int height = 0;
        int channels = 0;
        unsigned char* pixels = stbi_load_from_memory((const unsigned char*)data, (int)size, &width, &height, &channels, 4);
        if (!pixels) return nullptr;
        D3D11_TEXTURE2D_DESC texDesc{};
        texDesc.Width = (UINT)width;
        texDesc.Height = (UINT)height;
        texDesc.MipLevels = 1;
        texDesc.ArraySize = 1;
        texDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        texDesc.SampleDesc.Count = 1;
        texDesc.Usage = D3D11_USAGE_DEFAULT;
        texDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
        D3D11_SUBRESOURCE_DATA sub{};
        sub.pSysMem = pixels;
        sub.SysMemPitch = (UINT)(width * 4);
        ID3D11Texture2D* tex = nullptr;
        HRESULT hr = g_Device->CreateTexture2D(&texDesc, &sub, &tex);
        stbi_image_free(pixels);
        if (FAILED(hr) || !tex) return nullptr;
        ID3D11ShaderResourceView* srv = nullptr;
        hr = g_Device->CreateShaderResourceView(tex, nullptr, &srv);
        tex->Release();
        if (FAILED(hr) || !srv) return nullptr;
        return srv;
    }
    void InitTextures()
    {
        if (!g_Device)
        {
            MessageBox(nullptr, "InitTextures failed: g_Device was nullptr", "F", MB_OK);
            ExitProcess(1);
        }
        using enum ETextureID;
        textures[ICON_WRENCH] = DX11::LoadTextureFromMemoryDX11(PNGS::icon_wrench, sizeof(PNGS::icon_wrench));
        textures[ICON_PENCIL] = DX11::LoadTextureFromMemoryDX11(PNGS::icon_pencil, sizeof(PNGS::icon_pencil));
        textures[ICON_SETTINGS] = DX11::LoadTextureFromMemoryDX11(PNGS::icon_settings, sizeof(PNGS::icon_settings));
        textures[ICON_MOREINFO] = DX11::LoadTextureFromMemoryDX11(PNGS::icon_moreinfo, sizeof(PNGS::icon_moreinfo));
        textures[ICON_TIMEPAST] = DX11::LoadTextureFromMemoryDX11(PNGS::icon_timepast, sizeof(PNGS::icon_timepast));
        textures[ICON_TIMEFORWARD] = DX11::LoadTextureFromMemoryDX11(PNGS::icon_timeforward, sizeof(PNGS::icon_timeforward));
        textures[ICON_SETTINGSLIDERS] = DX11::LoadTextureFromMemoryDX11(PNGS::icon_settings_sliders, sizeof(PNGS::icon_settings_sliders));
        textures[ICON_MENUBURGER] = DX11::LoadTextureFromMemoryDX11(PNGS::icon_menu_burger, sizeof(PNGS::icon_menu_burger));
        textures[ICON_CIRCLE_QUESTIONMARK] = DX11::LoadTextureFromMemoryDX11(PNGS::icon_circle_questionmark, sizeof(PNGS::icon_circle_questionmark));
    }
    static void FreeAllTextures()
    {
        for (auto& [name, texture] : DX11::textures)
        {
            if (texture)
            {
                texture->Release();
                texture = nullptr;
            }
        }
        DX11::textures.clear();
    }
    void CreateRenderTarget()
    {
        ID3D11Texture2D* backBuffer = nullptr;
        if (SUCCEEDED(g_Swapchain->GetBuffer(0, IID_PPV_ARGS(&backBuffer))) && backBuffer)
        {
            g_Device->CreateRenderTargetView(backBuffer, nullptr, &g_RTV);
            backBuffer->Release();
        }
    }
    //i dont allow users to do this but eh.. for completeness
    void OnResize()
    {
        if (g_RTV)
        {
            g_RTV->Release();
            g_RTV = nullptr;
        }
    }
    bool Init()
    {
        DXGI_SWAP_CHAIN_DESC sd{};
        sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        sd.SampleDesc.Count = 1;
        sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        sd.BufferCount = 1;
        sd.OutputWindow = g_Window;
        sd.Windowed = TRUE;
        sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

        UINT flags = 0;
#ifdef _DEBUG
        flags |= D3D11_CREATE_DEVICE_DEBUG;
#endif
        D3D_FEATURE_LEVEL level;
        D3D_FEATURE_LEVEL levels[] = { D3D_FEATURE_LEVEL_11_0 };

        HRESULT hr = D3D11CreateDeviceAndSwapChain(
            nullptr,
            D3D_DRIVER_TYPE_HARDWARE,
            nullptr,
            flags,
            levels,
            1,
            D3D11_SDK_VERSION,
            &sd,
            &g_Swapchain,
            &g_Device,
            &level,
            &g_Context
        );
        if (FAILED(hr))
            return false;
        CreateRenderTarget();
        return true;
    }
    void Cleanup()
    {
        if (g_RTV)
        {
            g_RTV->Release();
            g_RTV = nullptr;
        }
        if (DX11::g_Swapchain)
        {
            DX11::g_Swapchain->Release();
            DX11::g_Swapchain = nullptr;
        }
        if (DX11::g_Context)
        {
            DX11::g_Context->Release();
            DX11::g_Context = nullptr;
        }
        if (DX11::g_Device)
        {
            DX11::g_Device->Release();
            DX11::g_Device = nullptr;
        }
        FreeAllTextures();
    }
    void BeginFrame()
    {
        ImGui_ImplDX11_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();
    }
    void EndFrame()
    {
        ImGui::Render();
        DX11::g_Context->OMSetRenderTargets(1, &DX11::g_RTV, nullptr);
        DX11::g_Context->ClearRenderTargetView(DX11::g_RTV, DX11::clearColor);
        ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
        DX11::g_Swapchain->Present(0, DXGI_PRESENT_DO_NOT_WAIT);//(0, DXGI_PRESENT_DO_NOT_WAIT) is important or else the game will more or less half our fps
    }
}