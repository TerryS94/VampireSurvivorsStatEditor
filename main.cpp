#include "main.h"
#include "masm_globals.h"

static HMODULE g_hModule = nullptr;
static const char* windowTitleAndClassname = "VS | Terry";
bool isRunning = true;

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

static void Shutdown()
{
    isRunning = false;

    Sleep(250);

    game::OnShutdown();

    if (ImGui::GetCurrentContext())
        ImGui::GetIO().Fonts->Clear();

    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();
    DX11::Cleanup();

    if (DX11::g_Window)
    {
        DestroyWindow(DX11::g_Window);
        DX11::g_Window = nullptr;
    }
    UnregisterClass(windowTitleAndClassname, g_hModule);
}
static void MainLoop()
{
    constexpr float fps = 60.0f;
    const auto targetFrameDuration = std::chrono::duration<float>(1.0f / fps);

    MSG msg{};
    while (msg.message != WM_QUIT && isRunning)
    {
        const auto frameStart = std::chrono::steady_clock::now();
        while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        DX11::BeginFrame();

        ImGui::PushItemFlag(ImGuiItemFlags_NoTabStop, true);//don't allow tab key navigation
        ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
        ImGui::SetNextWindowSize(rendering::windowSize, ImGuiCond_Always);
        ImGui::SetNextWindowScroll(ImVec2(0, -1));
        ImGui::Begin("dll_overlay", nullptr,
            ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);
        {
            rendering::RenderVampireSurvivorsMenu();
            ImGui::End();
        }
        ImGui::PopItemFlag();//ImGuiItemFlags_NoTabStop

        DX11::EndFrame();

        const auto frameEnd = std::chrono::steady_clock::now();
        const auto frameDuration = std::chrono::duration<float>(frameEnd - frameStart);
        if (frameDuration < targetFrameDuration)
            std::this_thread::sleep_for(targetFrameDuration - frameDuration);
    }
}
static void SetTitleBarAndTextColor(HWND hwnd)
{
    if (!hwnd) return;
    const ImGuiStyle& ImStyle = ImGui::GetStyle();
    const ImVec4 bg = ImStyle.Colors[ImGuiCol_WindowBg];
    const ImVec4 txt = ImStyle.Colors[ImGuiCol_Text];
    const COLORREF captionColor = RGB(utils::FloatToByte(bg.x), utils::FloatToByte(bg.y), utils::FloatToByte(bg.z));
    const COLORREF textColor = RGB(utils::FloatToByte(txt.x), utils::FloatToByte(txt.y), utils::FloatToByte(txt.z));
    DwmSetWindowAttribute(hwnd, DWMWA_CAPTION_COLOR, &captionColor, sizeof(captionColor));
    DwmSetWindowAttribute(hwnd, DWMWA_TEXT_COLOR, &textColor, sizeof(textColor));
}
static DWORD WINAPI ThreadProc(LPVOID)
{
    {
        sig::SetupHooks();

        WNDCLASSEX wc{};
        wc.cbSize = sizeof(WNDCLASSEX);
        wc.style = CS_CLASSDC;
        wc.lpfnWndProc = WndProc;
        wc.cbClsExtra = 0;
        wc.cbWndExtra = 0;
        wc.hInstance = g_hModule;
        wc.hIcon = LoadIcon(g_hModule, MAKEINTRESOURCE(IDI_ICON1));
        wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
        wc.hbrBackground = nullptr;
        wc.lpszMenuName = nullptr;
        wc.lpszClassName = windowTitleAndClassname;
        wc.hIconSm = (HICON)LoadImage(g_hModule, MAKEINTRESOURCE(IDI_ICON1), IMAGE_ICON, GetSystemMetrics(SM_CXSMICON), GetSystemMetrics(SM_CYSMICON), 0);
        RegisterClassEx(&wc);

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        io.IniFilename = nullptr;

        const int clientW = (int)rendering::windowSize.x;
        const int clientH = (int)rendering::windowSize.y;

        DWORD exStyle = WS_EX_TOPMOST;
        DWORD style = WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;

        RECT rect = { 0, 0, clientW, clientH };
        AdjustWindowRectEx(&rect, style, FALSE, exStyle);

        int outerW = rect.right - rect.left;
        int outerH = rect.bottom - rect.top;

        RECT screen;
        GetWindowRect(GetDesktopWindow(), &screen);
        int screenW = screen.right;
        int screenH = screen.bottom;

        int posX = screenW - outerW;
        int posY = (screenH - outerH) / 2;

        DX11::g_Window = CreateWindowEx(
            exStyle,
            wc.lpszClassName,
            windowTitleAndClassname,
            style,
            posX, posY,
            outerW, outerH,
            nullptr, nullptr,
            wc.hInstance,
            nullptr
        );

        if (!DX11::g_Window)
            return 0;

        if (!DX11::Init())
        {
            DestroyWindow(DX11::g_Window);
            DX11::g_Window = nullptr;
            UnregisterClass(windowTitleAndClassname, g_hModule);
            return 0;
        }

        rendering::ApplyDarkThemeWithAccent(rendering::MenuColorAccent);
        ImGui_ImplWin32_Init(DX11::g_Window);
        ImGui_ImplDX11_Init(DX11::g_Device, DX11::g_Context);

        rendering::InitFonts();
        DX11::InitTextures();

        SetTitleBarAndTextColor(DX11::g_Window);
        ShowWindow(DX11::g_Window, SW_SHOW);
        UpdateWindow(DX11::g_Window);

        MainLoop();
        Shutdown();
    }
    FreeLibraryAndExitThread(g_hModule, 0);
    return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui::GetCurrentContext() && ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (DX11::g_Device && wParam != SIZE_MINIMIZED)
        {
            DX11::OnResize();
            DX11::g_Swapchain->ResizeBuffers(
                0,
                LOWORD(lParam),
                HIWORD(lParam),
                DXGI_FORMAT_UNKNOWN,
                0
            );
            DX11::CreateRenderTarget();
        }
        break;
    case WM_DESTROY:
        isRunning = false;
        PostQuitMessage(0);
        break;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID)
{
    if (reason == DLL_PROCESS_ATTACH)
    {
		g_hModule = hModule;
        DisableThreadLibraryCalls(hModule);
        CreateThread(nullptr, 0, ThreadProc, nullptr, 0, nullptr);
    }
    return TRUE;
}