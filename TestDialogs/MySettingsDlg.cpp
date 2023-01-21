// MySettingsDlg.cpp : implementation file
//
#include "stdafx.h"
#include "MyFrame.h"
#include "MySettingsDlg.h"
#include "MyFrameDlg1.h"
#include "afxdialogex.h"
#include "StyleMessageBox.h"
#include "StyleColors.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

MySettingsDlg::MySettingsDlg(CWnd* pParent /*=NULL*/)
               :StyleDialog(IDD, pParent,true,true)
{
}

void MySettingsDlg::DoDataExchange(CDataExchange* pDX)
{
  StyleDialog::DoDataExchange(pDX);

  DDX_Control(pDX, IDC_TAB_1, m_tab);
  DDX_Control(pDX, IDOK,      m_buttonOK);
  DDX_Control(pDX, IDCANCEL,  m_buttonCancel);
}

BEGIN_MESSAGE_MAP(MySettingsDlg, StyleDialog)
  ON_WM_CREATE()
  ON_WM_SYSCOMMAND()
END_MESSAGE_MAP()

int
MySettingsDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
  m_grayWindow.CreateEx(0, AfxRegisterWndClass(0), "", WS_POPUP, CRect(0, 0, 0, 0), this, 0);
  return 0;
}

void
MySettingsDlg::OnDestroy()
{
  m_grayWindow.DestroyWindow();
}

// CMyFrameDlg message handlers

BOOL MySettingsDlg::OnInitDialog()
{
  StyleDialog::OnInitDialog();
  SetWindowText("My Settings dialog");
  SetAboutBoxAndIcon(IDM_ABOUTBOX,IDS_ABOUTBOX);

  m_tab.InsertItem(0, nullptr, "First");
  m_tab.InsertItem(1, nullptr, "Second tab");
  m_tab.InsertItem(2, nullptr, "Third");
  m_tab.InsertItem(3, nullptr, "Fourth");
  m_tab.InsertItem(4, nullptr, "Fifth");

  m_tab.SetImages(IDB_TABICONS);
  m_tab.SetTabImage(0, 0);
  m_tab.SetTabImage(1, 1);
  m_tab.SetTabImage(2, 2);
  m_tab.SetTabImage(3, 3);
  m_tab.SetTabImage(4, 4);

  m_tab.SetErrorState(2, 14);
  m_tab.SetUseTabNotch(true);
  m_tab.SetTabActive(4,false);

  // Add extra initialization here
  m_buttonOK.SetDefaultButton(true);

  return TRUE;  // return TRUE  unless you set the focus to a control
}

void MySettingsDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
  if ((nID & 0xFFF0) == IDM_ABOUTBOX)
  {
    CAboutDlg dlgAbout;
    dlgAbout.DoModal();
  }
  else
  {
    StyleDialog::OnSysCommand(nID, lParam);
  }
}

