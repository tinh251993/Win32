#pragma once
#ifndef  TOOLBAR_H
#define  TOOLBAR_H

#include <Windows.h>
#include <vector>
#include <string>
#include "WebController.h"

class  ToolBar
{
public:
	//Default method
	ToolBar() = delete; //Initialize
	ToolBar(HWND hWnd);
	~ToolBar(); //Destroy
	ToolBar& operator =(const ToolBar&) = delete;
	ToolBar(const ToolBar&) = delete;

	//Method
	bool			ProcessMesage();

	//public Instance
private:
	HINSTANCE			m_hInstance;
	HWND				m_hWnd;
	WebController*		m_webController;
};
#endif // ! TOOLBAR_H
