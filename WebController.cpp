#include "WebController.h"


LRESULT CALLBACK ChildWebController(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_COMMAND:
		switch (wParam)
		{
		case 1: MessageBeep(MB_OK);
		default:
			break;
		}

		break;
	case WM_CREATE:
		break;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return  DefWindowProc(hWnd, uMsg, wParam, lParam);
}
WebController::WebController(HWND hWnd)
	: m_hInstance(GetModuleHandle(nullptr))
{
	const wchar_t* CLASS_NAME = L"WebController";
	WNDCLASS wndClass = {};
	wndClass.lpszClassName = CLASS_NAME;
	wndClass.hInstance = m_hInstance;
	wndClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.lpfnWndProc = ChildWebController;

	RegisterClass(&wndClass);


	DWORD style = WS_BORDER | WS_MAXIMIZEBOX | WS_SYSMENU | WS_CHILD;
	int width = 1200;
	int height = 30;
	RECT rect;
	rect.left = 0;
	rect.top = 0;
	rect.right = rect.left + width;
	rect.bottom = rect.top + height;
	AdjustWindowRect(&rect, style, true);

	m_hWnd = CreateWindowEx(
		0,
		CLASS_NAME,
		L"Title",
		style,
		rect.left,
		rect.top,
		rect.right - rect.left,
		rect.bottom - rect.top,
		hWnd,
		NULL,
		m_hInstance,
		NULL
	);

	ShowWindow(m_hWnd, SW_SHOW);
}

WebController::~WebController()
{
	const wchar_t* CLASS_NAME = L"WebController";
	UnregisterClass(CLASS_NAME, m_hInstance);
}