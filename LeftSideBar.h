#pragma once
#ifndef  LEFT_SIDE_BAR_H
#define	 LEFT_SIDE_BAR_H



#include <Windows.h>
#include <vector>
#include <string>

class  LeftSideBar
{
public:
	//Default method
	LeftSideBar() = delete; //Initialize
	LeftSideBar(HWND hWnd);
	~LeftSideBar(); //Destroy
	LeftSideBar& operator =(const LeftSideBar&) = delete;
	LeftSideBar(const LeftSideBar&) = delete;

	//Method
	bool			ProcessMesage();

	//public Instance
private:
	void				AddMenu(HWND);
	HINSTANCE			m_hInstance;
	HWND				m_hWnd;
};
#endif // ! LEFT_SIDE_BAR_H
