// TestPage2.cpp : implementation file
//
#include "pch.h"
#include "TestWizard.h"
#include "TestPage2.h"
#include "afxdialogex.h"

// TestPage2 dialog

IMPLEMENT_DYNAMIC(TestPage2,StyleTab)

TestPage2::TestPage2(CWnd* p_parent /*=nullptr*/)
          :StyleTab(IDD_TESTPAGE2, p_parent)
{
}

TestPage2::~TestPage2()
{
}

void TestPage2::DoDataExchange(CDataExchange* pDX)
{
  StyleTab::DoDataExchange(pDX);
  DDX_Control(pDX, IDC_EDIT9,  m_editTest9,  m_test9);
  DDX_Control(pDX, IDC_EDIT10, m_editTest10, m_test10);
  DDX_Control(pDX, IDC_EDIT11, m_editTest11, m_test11);
  DDX_Control(pDX, IDC_EDIT12, m_editTest12, m_test12);
  DDX_Control(pDX, IDC_EDIT13, m_editTest13, m_test13);
  DDX_Control(pDX, IDC_EDIT14, m_editTest14, m_test14);
  DDX_Control(pDX, IDC_EDIT15, m_editTest15, m_test15);
  DDX_Control(pDX, IDC_EDIT16, m_editTest16, m_test16);
}

BEGIN_MESSAGE_MAP(TestPage2, StyleTab)
  ON_EN_KILLFOCUS(IDC_EDIT9,  OnEnKillfocusEdit9)
  ON_EN_KILLFOCUS(IDC_EDIT10, OnEnKillfocusEdit10)
  ON_EN_KILLFOCUS(IDC_EDIT11, OnEnKillfocusEdit11)
  ON_EN_KILLFOCUS(IDC_EDIT12, OnEnKillfocusEdit12)
  ON_EN_KILLFOCUS(IDC_EDIT13, OnEnKillfocusEdit13)
  ON_EN_KILLFOCUS(IDC_EDIT14, OnEnKillfocusEdit14)
  ON_EN_KILLFOCUS(IDC_EDIT15, OnEnKillfocusEdit15)
  ON_EN_KILLFOCUS(IDC_EDIT16, OnEnKillfocusEdit16)
END_MESSAGE_MAP()

BOOL
TestPage2::OnInitDialog()
{
  StyleTab::OnInitDialog();


  return FALSE;
}

// TestPage2 message handlers

void
TestPage2::OnEnKillfocusEdit9()
{
  UpdateData();
}

void
TestPage2::OnEnKillfocusEdit10()
{
  UpdateData();
}

void
TestPage2::OnEnKillfocusEdit11()
{
  UpdateData();
}

void
TestPage2::OnEnKillfocusEdit12()
{
  UpdateData();
}

void
TestPage2::OnEnKillfocusEdit13()
{
  UpdateData();
}

void
TestPage2::OnEnKillfocusEdit14()
{
  UpdateData();
}

void
TestPage2::OnEnKillfocusEdit15()
{
  UpdateData();
}

void
TestPage2::OnEnKillfocusEdit16()
{
  UpdateData();
}
