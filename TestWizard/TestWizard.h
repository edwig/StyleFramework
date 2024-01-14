// TestWizard.h : main header file for the PROJECT_NAME application
//
#pragma once
#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif
#include "resource.h"		// main symbols

#include "TestPage1.h"
#include "TestPage2.h"
#include "TestPage3.h"
#include "TestPage4.h"

// TestWizardApp:
// See TestWizard.cpp for the implementation of this class
//
class TestWizardApp : public CWinApp
{
public:
	TestWizardApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()

private:
  TestPage1 m_page1;
  TestPage2 m_page2;
  TestPage3 m_page3;
  TestPage4 m_page4;
};

extern TestWizardApp theApp;
