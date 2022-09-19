#include "ContentField.h"

#define CONTENTFIEKD_CLASS "ContentField"

HINSTANCE ContentField::ms_hInst = NULL;
UINT ContentField::ms_nRegister = 0;

ContentField::MessageMap ContentField::ms_MSgMap[MSGMAP_SIZE];
UINT ContentField::ms_nMsgCount;


ContentField::ContentField() 
{

}

ContentField::~ContentField()
{

}

LRESULT CALLBACK ContentField::WndProc(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam)
{
	ContentField* pWnd = FindWindow(hWnd);
	if (nullptr != pWnd) 
	{
		pWnd->WndClassProc(hWnd, nMsg, wParam, lParam);
	}
	return DefWindowProc(hWnd, nMsg, wParam, lParam);
}


ContentField* ContentField::FindWindow(HWND hWnd)
{
	for (int i = 0; i < ms_nWndCount; ++i)
	{
		if (hWnd == ms_pWnd[i]->m_hWnd) 
		{
			return ms_pWnd[i];
		}
	}

	return nullptr;
}

void ContentField::ReleaseWindow(ContentField* hWnd) {

}

void ContentField::WndClassProc(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam)
{
	for (int i = 0; i < ms_nMsgCount; ++i)
	{
		if (nMsg == ms_MSgMap[i].nMSGID)
		{
			(this->*ms_MSgMap[i].pfgHander)(hWnd, wParam, lParam);
			return;
		}
	}
}