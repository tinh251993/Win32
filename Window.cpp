#include "Window.h"
#include "LeftSideBar.h"

#include <iostream>
#include <tchar.h>

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
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


Window::Window()
	: m_hInstance(GetModuleHandle(nullptr))	
{
	const wchar_t* CLASS_NAME = L"Window";
	WNDCLASS wndClass = {};
	wndClass.lpszClassName = CLASS_NAME;
	wndClass.hInstance = m_hInstance;
	wndClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.lpfnWndProc = WindowProc;

	RegisterClass(&wndClass);


	DWORD style = WS_BORDER | WS_MAXIMIZEBOX | WS_SYSMENU;
	int width = 1900;
	int height = 1000;
	RECT rect;
	rect.left = 60;
	rect.top = 30;
	rect.right = rect.left + width - 60;
	rect.bottom = rect.top + height - 30;
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
		NULL,
		NULL,
		m_hInstance,
		NULL
	);

	ShowWindow(m_hWnd, SW_SHOW);
	m_leftsidebar = new LeftSideBar(m_hWnd);
	m_rightsidebar = new RightSideBar(m_hWnd);
	m_toolbar = new ToolBar(m_hWnd);
}

Window::~Window() {
	const wchar_t* CLASS_NAME = L"Window";
	UnregisterClass(CLASS_NAME, m_hInstance);

	m_hMenu = nullptr;
}

bool Window::ProcessMesage()
{
	MSG msg = {};

	while (PeekMessage(&msg, nullptr, 0u, 0u, PM_REMOVE))
	{
		if (WM_QUIT == msg.message)
		{
			return false;
		}

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return true;
}

bool Window::showWindow(HWND hWnd)
{
	ShowWindow(hWnd, SW_SHOW);
}

bool Window::hideWindow(HWND hWnd) {
	ShowWindow(hWnd, SW_HIDE);
}
