// MyFrameDlg4.cpp : implementation file
//
#include "stdafx.h"
#include "MyFrameDlg4.h"
#include "afxdialogex.h"
#include <SkinScrollWnd.h>
#include <StyleMessageBox.h>

// MyFrameDlg4 dialog

IMPLEMENT_DYNAMIC(MyFrameDlg4, StyleDialog)

MyFrameDlg4::MyFrameDlg4(CWnd* pParent /*=nullptr*/)
	          :StyleDialog(MyFrameDlg4::IDD, pParent,true,true,true)
{
  m_testResize = true;
}

MyFrameDlg4::~MyFrameDlg4()
{
}

void MyFrameDlg4::DoDataExchange(CDataExchange* pDX)
{
	StyleDialog::DoDataExchange(pDX);

  DDX_Control(pDX,IDC_EDIT1,m_edit1,m_info1);
  DDX_Control(pDX,IDC_EDIT2,m_edit2,m_info2);
  DDX_Control(pDX,IDC_EDIT3,m_edit3,m_info3);
  DDX_Control(pDX,IDC_EDIT4,m_edit4,m_info4);
  DDX_Control(pDX,IDC_ERROR,m_buttonError);
  DDX_Control(pDX,IDOK,     m_buttonOK);
  DDX_Control(pDX,IDCANCEL, m_buttonCancel);
}

BEGIN_MESSAGE_MAP(MyFrameDlg4,StyleDialog)
  ON_COMMAND     (ID_THEMA_LIME,      OnStyleLime)
  ON_COMMAND     (ID_THEMA_SKYBLUE,   OnStyleSkyblue)
  ON_COMMAND     (ID_THEMA_PURPLE,    OnStylePurple)
  ON_COMMAND     (ID_THEMA_MODERATE,  OnStyleModerateGray)
  ON_COMMAND     (ID_THEMA_PUREGRAY,  OnStylePureGray)
  ON_COMMAND     (ID_THEMA_BLACKWHITE,OnStyleBlackWhite)
  ON_EN_KILLFOCUS(IDC_EDIT1,          &MyFrameDlg4::OnEnChangeEdit1)
  ON_EN_KILLFOCUS(IDC_EDIT2,          &MyFrameDlg4::OnEnChangeEdit2)
  ON_EN_KILLFOCUS(IDC_EDIT3,          &MyFrameDlg4::OnEnChangeEdit3)
  ON_EN_KILLFOCUS(IDC_EDIT4,          &MyFrameDlg4::OnEnChangeEdit4)
  ON_BN_CLICKED  (IDC_ERROR,          &MyFrameDlg4::OnBnClickedError)
  ON_BN_CLICKED  (IDOK,               &MyFrameDlg4::OnBnClickedOk)
END_MESSAGE_MAP()

BOOL
MyFrameDlg4::OnInitDialog()
{
  StyleDialog::OnInitDialog();
  SetWindowText("Testing menus");
  
  ShowMinMaxButton();
  SetSysMenu(IDR_MENU4);
  SetAboutBoxAndIcon(IDM_ABOUTBOX,IDS_ABOUTBOX);

  m_buttonError .SetStyle("rem");
  m_buttonOK    .SetStyle("ok");
  m_buttonCancel.SetStyle("can");

  // And trigger SetupDynamicLayout method
  SetCanResize();

  SetStatusPanes();

  return TRUE;
}

// Triggered by SetCanResize
void
MyFrameDlg4::SetupDynamicLayout()
{
  // See to it that we get a manager;
  StyleDialog::SetupDynamicLayout();

  auto manager = GetDynamicLayout();
  if (manager != nullptr)
  {
    manager->AddItem(IDC_EDIT1,     CMFCDynamicLayout::MoveNone(),       CMFCDynamicLayout::SizeHorizontalAndVertical(100,50));
    manager->AddItem(IDC_EDIT2,     CMFCDynamicLayout::MoveVertical(50), CMFCDynamicLayout::SizeHorizontalAndVertical(100,50));
    manager->AddItem(IDC_EDIT3,     CMFCDynamicLayout::MoveVertical(100),CMFCDynamicLayout::SizeHorizontalAndVertical(100, 0));
    manager->AddItem(IDC_EDIT4,     CMFCDynamicLayout::MoveVertical(100),CMFCDynamicLayout::SizeHorizontalAndVertical(100, 0));
    manager->AddItem(m_buttonError, CMFCDynamicLayout::MoveHorizontalAndVertical(  0,100),CMFCDynamicLayout::SizeNone());
    manager->AddItem(m_buttonOK,    CMFCDynamicLayout::MoveHorizontalAndVertical(100,100),CMFCDynamicLayout::SizeNone());
    manager->AddItem(m_buttonCancel,CMFCDynamicLayout::MoveHorizontalAndVertical(100,100),CMFCDynamicLayout::SizeNone());
  }
}

void
MyFrameDlg4::SetStatusPanes()
{
  if(!m_hasStatus || m_statusBar.GetSafeHwnd() == nullptr)
  {
    return;
  }

  UINT indicators[] = { 0,0,0,0 };
  m_statusBar.SetIndicators(indicators, 4);
  m_statusBar.SetPaneInfo(0, 0, SBPS_NORMAL,  80);
  m_statusBar.SetPaneInfo(1, 0, SBPS_NORMAL, 120);
  m_statusBar.SetPaneInfo(2, 0, SBPS_STRETCH, 80);
  m_statusBar.SetPaneInfo(3, 0, SBPS_NORMAL , 80);

  m_statusBar.SetPaneText(0, "Pane One");
  m_statusBar.SetPaneText(1, "Pane Two");
  m_statusBar.SetPaneText(2, "Pane Three");
  m_statusBar.SetPaneText(3, "XX - YY");
}

// MyFrameDlg4 message handlers

void 
MyFrameDlg4::OnEnChangeEdit1()
{
  UpdateData();
}

void 
MyFrameDlg4::OnEnChangeEdit2()
{
  UpdateData();
}

void
MyFrameDlg4::OnEnChangeEdit3()
{
  UpdateData();
}

void
MyFrameDlg4::OnEnChangeEdit4()
{
  UpdateData();
}

void
MyFrameDlg4::OnBnClickedError()
{
  if(m_edit1.GetErrorState())
  {
    m_edit1.SetErrorState(false, "");
  }
  else
  {
    m_edit1.SetErrorState(true, "Not allowed");
  }
}

void 
MyFrameDlg4::OnBnClickedOk()
{
  StyleMessageBox(this,m_info1,"TEST");
  StyleDialog::OnOK();
}
