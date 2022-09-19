#pragma once
#ifndef  CONTENT_FIELD_H
#define  CONTENT_FIELD_H

#include <Windows.h>

#define MSGMAP_SIZE 100
#define CONTENTDWND_MAX 10

class  ContentField
{
public:
	///////////////////////////////
	typedef void (ContentField::* MessageHandler)(HWND, WPARAM, LPARAM);
	typedef struct {
		UINT nMSGID;
		MessageHandler pfgHander;

	} MessageMap;
	////////////////////////////////
	ContentField();
	virtual ~ContentField();
	////////////////////////
	static HINSTANCE ms_hInst;

	static UINT ms_nMsgCount;


	static ContentField* ms_pWnd[CONTENTDWND_MAX];
	static UINT ms_nWndCount;

	static UINT ms_nRegister;
	static MessageMap ms_MSgMap[MSGMAP_SIZE];
	HWND getHWND() { return m_hWnd; }
	HWND m_hWnd;
private:




	static LRESULT CALLBACK WndProc(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam);
	static ContentField* FindWindow(HWND hWnd);
	static void ReleaseWindow(ContentField* pWnd);



	void WndClassProc(HWND, UINT, WPARAM, LPARAM);


};



#endif // ! CONTENT_FIELD_H
