// TestPage1.cpp : implementation file
//
#include "pch.h"
#include "TestWizard.h"
#include "TestPage1.h"
#include "afxdialogex.h"

// TestPage1 dialog

IMPLEMENT_DYNAMIC(TestPage1,StyleTab)

TestPage1::TestPage1(CWnd* p_parent /*=nullptr*/)
	        :StyleTab(IDD_TESTPAGE1, p_parent)
{
}

TestPage1::~TestPage1()
{
}

void TestPage1::DoDataExchange(CDataExchange* pDX)
{
	StyleTab::DoDataExchange(pDX);
	DDX_Control(pDX,IDC_EDIT1,m_editTest1,m_test1);
	DDX_Control(pDX,IDC_EDIT2,m_editTest2,m_test2);
	DDX_Control(pDX,IDC_EDIT3,m_editTest3,m_test3);
	DDX_Control(pDX,IDC_EDIT4,m_editTest4,m_test4);
	DDX_Control(pDX,IDC_EDIT5,m_editTest5,m_test5);
	DDX_Control(pDX,IDC_EDIT6,m_editTest6,m_test6);
	DDX_Control(pDX,IDC_EDIT7,m_editTest7,m_test7);
	DDX_Control(pDX,IDC_EDIT8,m_editTest8,m_test8);
}

BEGIN_MESSAGE_MAP(TestPage1,StyleTab)
	ON_EN_KILLFOCUS(IDC_EDIT1,OnEnKillfocusEdit1)
	ON_EN_KILLFOCUS(IDC_EDIT2,OnEnKillfocusEdit2)
	ON_EN_KILLFOCUS(IDC_EDIT3,OnEnKillfocusEdit3)
	ON_EN_KILLFOCUS(IDC_EDIT4,OnEnKillfocusEdit4)
	ON_EN_KILLFOCUS(IDC_EDIT5,OnEnKillfocusEdit5)
	ON_EN_KILLFOCUS(IDC_EDIT6,OnEnKillfocusEdit6)
	ON_EN_KILLFOCUS(IDC_EDIT7,OnEnKillfocusEdit7)
	ON_EN_KILLFOCUS(IDC_EDIT8,OnEnKillfocusEdit8)
END_MESSAGE_MAP()

BOOL
TestPage1::OnInitDialog()
{
	StyleTab::OnInitDialog();


	return FALSE;
}

// TestPage1 message handlers

void 
TestPage1::OnEnKillfocusEdit1()
{
	UpdateData();
}

void 
TestPage1::OnEnKillfocusEdit2()
{
  UpdateData();
}

void 
TestPage1::OnEnKillfocusEdit3()
{
  UpdateData();
}

void 
TestPage1::OnEnKillfocusEdit4()
{
  UpdateData();
}

void 
TestPage1::OnEnKillfocusEdit5()
{
  UpdateData();
}

void 
TestPage1::OnEnKillfocusEdit6()
{
  UpdateData();
}

void 
TestPage1::OnEnKillfocusEdit7()
{
  UpdateData();
}

void 
TestPage1::OnEnKillfocusEdit8()
{
  UpdateData();
}
