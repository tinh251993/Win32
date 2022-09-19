#include "ToolBar.h"


LRESULT CALLBACK ChildToolBar(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
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
ToolBar::ToolBar(HWND hWnd)
	: m_hInstance(GetModuleHandle(nullptr))
{
	const wchar_t* CLASS_NAME = L"ToolBar";
	WNDCLASS wndClass = {};
	wndClass.lpszClassName = CLASS_NAME;
	wndClass.hInstance = m_hInstance;
	wndClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.lpfnWndProc = ChildToolBar;

	RegisterClass(&wndClass);


	DWORD style = WS_BORDER | WS_MAXIMIZEBOX | WS_SYSMENU | WS_CHILD;
	int width = 1200;
	int height = 60;
	RECT rect;
	rect.left = 310;
	rect.top = 30;
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
	m_webController = new WebController(m_hWnd);
	ShowWindow(m_hWnd, SW_SHOW);
}

ToolBar::~ToolBar()
{
	const wchar_t* CLASS_NAME = L"ToolBar";
	UnregisterClass(CLASS_NAME, m_hInstance);
}