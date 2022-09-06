// MyFrameDlg.cpp : implementation file
//
#include "stdafx.h"
#include "MyFrameDlg.h"
#include "MyFrameDlg1.h"
#include "MyFrameDlg2.h"
#include "MyFrameDlg3.h"
#include "MyFrameDlg4.h"
#include "MyFrameDlg5.h"
#include "MyFrameDlg6.h"
#include "MyFrameDlg7.h"
#include "MyGridDlg.h"
#include "MySettingsDlg.h"

MyFrameDlg::MyFrameDlg(CWnd* p_parent /*=nullptr*/)
           :StyleDialog(IDD,p_parent,true,true)
{
	m_text = "Select one of the following tests";
}

MyFrameDlg::~MyFrameDlg()
{
}

BEGIN_MESSAGE_MAP(MyFrameDlg,StyleDialog)
	ON_EN_CHANGE (IDC_TEXT,  &MyFrameDlg::OnEnChangeText)
	ON_BN_CLICKED(IDC_TEST1, &MyFrameDlg::OnBnClickedTest1)
	ON_BN_CLICKED(IDC_TEST2, &MyFrameDlg::OnBnClickedTest2)
	ON_BN_CLICKED(IDC_TEST3, &MyFrameDlg::OnBnClickedTest3)
	ON_BN_CLICKED(IDC_TEST4, &MyFrameDlg::OnBnClickedTest4)
	ON_BN_CLICKED(IDC_TEST5, &MyFrameDlg::OnBnClickedTest5)
	ON_BN_CLICKED(IDC_TEST6, &MyFrameDlg::OnBnClickedTest6)
	ON_BN_CLICKED(IDC_TEST7, &MyFrameDlg::OnBnClickedTest7)
	ON_BN_CLICKED(IDC_GRID,  &MyFrameDlg::OnBnClickedGrid)
	ON_BN_CLICKED(IDC_TABS,  &MyFrameDlg::OnBnClickedTabs)
	ON_BN_CLICKED(IDOK,			 &MyFrameDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL,  &MyFrameDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


void MyFrameDlg::DoDataExchange(CDataExchange* pDX)
{
  StyleDialog::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_TEXT,  m_editText, m_text);
	DDX_Control(pDX, IDC_TEST1, m_buttonTest1);
	DDX_Control(pDX, IDC_TEST2, m_buttonTest2);
	DDX_Control(pDX, IDC_TEST3, m_buttonTest3);
	DDX_Control(pDX, IDC_TEST4, m_buttonTest4);
	DDX_Control(pDX, IDC_TEST5, m_buttonTest5);
	DDX_Control(pDX, IDC_TEST6, m_buttonTest6);
	DDX_Control(pDX, IDC_TEST7, m_buttonTest7);
	DDX_Control(pDX, IDC_GRID,  m_buttonGrid);
	DDX_Control(pDX, IDC_TABS,  m_buttonTabs);

  DDX_Control(pDX, IDC_ST_ELEMEN,   m_staticElement);
  DDX_Control(pDX, IDC_ST_COMBO,    m_staticCombo);
  DDX_Control(pDX, IDC_ST_EDIT,     m_staticEdit);
  DDX_Control(pDX, IDC_ST_MULTI,    m_staticMulti);
  DDX_Control(pDX, IDC_ST_LIST,     m_staticList);
  DDX_Control(pDX, IDC_ST_TREE,     m_staticTree);
  DDX_Control(pDX, IDC_ST_PROGRESS, m_staticProgress);
  DDX_Control(pDX, IDC_ST_GRID,     m_staticGrid);
  DDX_Control(pDX, IDC_ST_TAB,      m_staticTab);


	DDX_Control(pDX, IDOK,      m_buttonOK);
	DDX_Control(pDX, IDCANCEL,  m_buttonCancel);
}

BOOL
MyFrameDlg::OnInitDialog()
{
  StyleDialog::OnInitDialog();
	SetWindowText("Select a test");
  return TRUE;
}

void 
MyFrameDlg::OnEnChangeText()
{
	UpdateData();
}

void 
MyFrameDlg::OnBnClickedTest1()
{
  MyFrameDlg1 dlg(this);
  dlg.DoModal();
}

void 
MyFrameDlg::OnBnClickedTest2()
{
  MyFrameDlg2 dlg(this);
  dlg.DoModal();
}

void 
MyFrameDlg::OnBnClickedTest3()
{
  MyFrameDlg3 dlg(this);
  dlg.DoModal();
}

void 
MyFrameDlg::OnBnClickedTest4()
{
  MyFrameDlg4 dlg(this);
  dlg.DoModal();
}

void 
MyFrameDlg::OnBnClickedTest5()
{
  MyFrameDlg5 dlg(this);
  dlg.DoModal();
}

void 
MyFrameDlg::OnBnClickedTest6()
{
  MyFrameDlg6 dlg(this);
  dlg.DoModal();
}

void 
MyFrameDlg::OnBnClickedTest7()
{
  MyFrameDlg7 dlg(this);
  dlg.DoModal();
}

void 
MyFrameDlg::OnBnClickedGrid()
{
  MyGridDlg dlg(this);
  dlg.DoModal();
}

void 
MyFrameDlg::OnBnClickedTabs()
{
  MySettingsDlg dlg(this);
  dlg.DoModal();
}

void 
MyFrameDlg::OnBnClickedOk()
{
	OnOK();
}

void 
MyFrameDlg::OnBnClickedCancel()
{
	OnCancel();
}
