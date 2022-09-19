
#pragma once
#ifndef  RIGHT_SIDE_BAR_H
#define	 RIGHT_SIDE_BAR_H


#include <Windows.h>
#include <vector>
#include <string>

class  RightSideBar
{
public:
	//Default method
	RightSideBar() = delete; //Initialize
	RightSideBar(HWND hWnd);
	~RightSideBar(); //Destroy
	RightSideBar& operator =(const RightSideBar&) = delete;
	RightSideBar(const RightSideBar&) = delete;

	bool			ProcessMesage();

	//public Instance
private:
	void				AddMenu(HWND);
	HINSTANCE			m_hInstance;
	HWND				m_hWnd;
};
#endif // ! RIGHT_SIDE_BAR_H
