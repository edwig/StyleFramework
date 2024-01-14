// TestPage4.cpp : implementation file
//
#include "pch.h"
#include "TestWizard.h"
#include "TestPage4.h"
#include "afxdialogex.h"

// TestPage4 dialog

IMPLEMENT_DYNAMIC(TestPage4,StyleTab)

TestPage4::TestPage4(CWnd* p_parent /*=nullptr*/)
         :StyleTab(IDD_TESTPAGE4, p_parent)
{
}

TestPage4::~TestPage4()
{
}

void TestPage4::DoDataExchange(CDataExchange* pDX)
{
	StyleTab::DoDataExchange(pDX);
	DDX_Control(pDX,IDC_EDIT25,m_editTest25,m_test25);
	DDX_Control(pDX,IDC_EDIT26,m_editTest26,m_test26);
	DDX_Control(pDX,IDC_EDIT27,m_editTest27,m_test27);
	DDX_Control(pDX,IDC_EDIT28,m_editTest28,m_test28);
	DDX_Control(pDX,IDC_EDIT29,m_editTest29,m_test29);
	DDX_Control(pDX,IDC_EDIT30,m_editTest30,m_test30);
	DDX_Control(pDX,IDC_EDIT31,m_editTest31,m_test31);
	DDX_Control(pDX,IDC_EDIT32,m_editTest32,m_test32);
}

BEGIN_MESSAGE_MAP(TestPage4,StyleTab)
	ON_EN_KILLFOCUS(IDC_EDIT25,OnEnKillfocusEdit25)
	ON_EN_KILLFOCUS(IDC_EDIT26,OnEnKillfocusEdit26)
	ON_EN_KILLFOCUS(IDC_EDIT27,OnEnKillfocusEdit27)
	ON_EN_KILLFOCUS(IDC_EDIT28,OnEnKillfocusEdit28)
	ON_EN_KILLFOCUS(IDC_EDIT29,OnEnKillfocusEdit29)
	ON_EN_KILLFOCUS(IDC_EDIT30,OnEnKillfocusEdit30)
	ON_EN_KILLFOCUS(IDC_EDIT31,OnEnKillfocusEdit31)
	ON_EN_KILLFOCUS(IDC_EDIT32,OnEnKillfocusEdit32)
END_MESSAGE_MAP()

BOOL
TestPage4::OnInitDialog()
{
	StyleTab::OnInitDialog();


	return FALSE;
}

// TestPage4 message handlers

void 
TestPage4::OnEnKillfocusEdit25()
{
	UpdateData();
}

void 
TestPage4::OnEnKillfocusEdit26()
{
  UpdateData();
}

void 
TestPage4::OnEnKillfocusEdit27()
{
  UpdateData();
}

void 
TestPage4::OnEnKillfocusEdit28()
{
  UpdateData();
}

void 
TestPage4::OnEnKillfocusEdit29()
{
  UpdateData();
}

void 
TestPage4::OnEnKillfocusEdit30()
{
  UpdateData();
}

void 
TestPage4::OnEnKillfocusEdit31()
{
  UpdateData();
}

void 
TestPage4::OnEnKillfocusEdit32()
{
  UpdateData();
}
