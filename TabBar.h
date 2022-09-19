#pragma once
#ifndef  TABBAR_H
#define  TABBAR_H

#include <Windows.h>
#include <vector>
#include <string>
#include "WebController.h"

class  TabBar
{
public:
	//Default method
	TabBar() = delete; //Initialize
	TabBar(HWND hWnd);
	~TabBar(); //Destroy
	TabBar& operator =(const TabBar&) = delete;
	TabBar(const TabBar&) = delete;

	//Method
	bool			ProcessMesage();

	//public Instance
private:
	HINSTANCE			m_hInstance;
	HWND				m_hWnd;
	WebController*		m_webController;
};
#endif // ! TOOLBAR_H
