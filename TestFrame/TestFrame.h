// TestFrame.h : main header file for the TestFrame application
//
#pragma once
#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif
#include "resource.h"       // main symbols
#include "WinToastLib.h"
#include "ToastHandler.h"

using namespace WinToastLib;

#define PROGRAM_NAME _T("TestFrame")

// CTestFrameApp:
// See TestFrame.cpp for the implementation of this class
//

#define BaseWinApp CWinAppEx // CWinAppEx

class CTestFrameApp : public BaseWinApp
{
public:
	CTestFrameApp();


// Overrides
public:
	virtual int  Run() override;
	virtual BOOL InitInstance() override;
	virtual BOOL PumpMessage() override;

  // Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()

private:
	void InitToast();
	void ShowStartToast();
  void SendToast(WinToastTemplate& templ);

	WinToastHandler m_handler;
};

extern CTestFrameApp theApp;
