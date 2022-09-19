#pragma once
#ifndef  WINDOW_H
#define  WINDOW_H


#include <Windows.h>
#include <vector>
#include <string>
#include "LeftSideBar.h"
#include "RightSideBar.h"
#include "ToolBar.h"
class  Window
{
public:
	//Default method
	Window(); //Initialize
	~Window(); //Destroy
	Window& operator =(const Window&) = delete;
	Window(const Window&) = delete;

	//Method
	bool			ProcessMesage();
	bool			hideWindow(HWND);
	bool			showWindow(HWND);

private:
	HINSTANCE			m_hInstance;
	HWND				m_hWnd;
	HMENU				m_hMenu;
	std::vector< HWND>	m_list_screen;
	LeftSideBar*		m_leftsidebar;
	RightSideBar*		m_rightsidebar;
	ToolBar*			m_toolbar;
};
#endif // ! WINDOW_H
