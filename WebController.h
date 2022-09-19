#pragma once
#ifndef WEB_CONTROLL_H 
#define WEB_CONTROLL_H

#include <Windows.h>
#include <vector>
#include <string>

class  WebController
{
public:
	//Default method
	WebController() = delete; //Initialize
	WebController(HWND hWnd);
	~WebController(); //Destroy
	WebController& operator =(const WebController&) = delete;
	WebController(const WebController&) = delete;

	//Method
	bool			ProcessMesage();

	//public Instance
private:
	HINSTANCE			m_hInstance;
	HWND				m_hWnd;
};
#endif // 
