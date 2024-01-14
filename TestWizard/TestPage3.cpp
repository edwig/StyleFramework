// TestPage3.cpp : implementation file
//
#include "pch.h"
#include "TestWizard.h"
#include "TestPage3.h"
#include "afxdialogex.h"

// TestPage3 dialog

IMPLEMENT_DYNAMIC(TestPage3,StyleTab)

TestPage3::TestPage3(CWnd* p_parent /*=nullptr*/)
	        :StyleTab(IDD_TESTPAGE3, p_parent)
{
}

TestPage3::~TestPage3()
{
}

void TestPage3::DoDataExchange(CDataExchange* pDX)
{
	StyleTab::DoDataExchange(pDX);
	DDX_Control(pDX,IDC_EDIT17,m_editTest17,m_test17);
	DDX_Control(pDX,IDC_EDIT18,m_editTest18,m_test18);
	DDX_Control(pDX,IDC_EDIT19,m_editTest19,m_test19);
	DDX_Control(pDX,IDC_EDIT20,m_editTest20,m_test20);
	DDX_Control(pDX,IDC_EDIT21,m_editTest21,m_test21);
	DDX_Control(pDX,IDC_EDIT22,m_editTest22,m_test22);
	DDX_Control(pDX,IDC_EDIT23,m_editTest23,m_test23);
	DDX_Control(pDX,IDC_EDIT24,m_editTest24,m_test24);
}

BEGIN_MESSAGE_MAP(TestPage3,StyleTab)
	ON_EN_KILLFOCUS(IDC_EDIT17,OnEnKillfocusEdit17)
	ON_EN_KILLFOCUS(IDC_EDIT18,OnEnKillfocusEdit18)
	ON_EN_KILLFOCUS(IDC_EDIT19,OnEnKillfocusEdit19)
	ON_EN_KILLFOCUS(IDC_EDIT20,OnEnKillfocusEdit20)
	ON_EN_KILLFOCUS(IDC_EDIT21,OnEnKillfocusEdit21)
	ON_EN_KILLFOCUS(IDC_EDIT22,OnEnKillfocusEdit22)
	ON_EN_KILLFOCUS(IDC_EDIT23,OnEnKillfocusEdit23)
	ON_EN_KILLFOCUS(IDC_EDIT24,OnEnKillfocusEdit24)
END_MESSAGE_MAP()

BOOL
TestPage3::OnInitDialog()
{
	StyleTab::OnInitDialog();


	return FALSE;
}

// TestPage3 message handlers

void 
TestPage3::OnEnKillfocusEdit17()
{
	UpdateData();
}

void 
TestPage3::OnEnKillfocusEdit18()
{
  UpdateData();
}

void 
TestPage3::OnEnKillfocusEdit19()
{
  UpdateData();
}

void 
TestPage3::OnEnKillfocusEdit20()
{
  UpdateData();
}

void 
TestPage3::OnEnKillfocusEdit21()
{
  UpdateData();
}

void 
TestPage3::OnEnKillfocusEdit22()
{
  UpdateData();
}

void 
TestPage3::OnEnKillfocusEdit23()
{
  UpdateData();
}

void 
TestPage3::OnEnKillfocusEdit24()
{
  UpdateData();
}
