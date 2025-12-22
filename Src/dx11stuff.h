#pragma once

enum class ETextureID : int
{
	ICON_WRENCH,
	ICON_PENCIL,
	ICON_SETTINGS,
	ICON_MOREINFO,
	ICON_TIMEPAST,
	ICON_TIMEFORWARD,
	ICON_SETTINGSLIDERS,
	ICON_MENUBURGER,
	ICON_CIRCLE_QUESTIONMARK
};
namespace DX11
{
	extern ID3D11Device* g_Device;
	extern ID3D11DeviceContext* g_Context;
	extern IDXGISwapChain* g_Swapchain;
	extern ID3D11RenderTargetView* g_RTV;
	extern float clearColor[4];
	extern HWND g_Window;

	ID3D11ShaderResourceView* GetTextureByName(ETextureID id);
	ID3D11ShaderResourceView* LoadTextureFromMemoryDX11(const void* data, size_t size);
	void InitTextures();
	void CreateRenderTarget();
	void OnResize();
	bool Init();
	void Cleanup();
	void BeginFrame();
	void EndFrame();
}