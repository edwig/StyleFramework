// TestPage2.cpp : implementation file
//
#include "pch.h"
#include "TestProperties.h"
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
  DDX_Control(pDX, IDC_EDIT13, m_editTest13);

  if (pDX->m_bSaveAndValidate == FALSE)
  {
    m_editTest13.SetRTFText(m_test13);
  }

}

BEGIN_MESSAGE_MAP(TestPage2, StyleTab)
  ON_EN_KILLFOCUS(IDC_EDIT9,  OnEnKillfocusEdit9)
  ON_EN_KILLFOCUS(IDC_EDIT10, OnEnKillfocusEdit10)
  ON_EN_KILLFOCUS(IDC_EDIT11, OnEnKillfocusEdit11)
  ON_EN_KILLFOCUS(IDC_EDIT12, OnEnKillfocusEdit12)
  // ON_EN_KILLFOCUS(IDC_EDIT13, OnEnKillfocusEdit13)
END_MESSAGE_MAP()

BOOL
TestPage2::OnInitDialog()
{
  StyleTab::OnInitDialog();

  SetRTF();

  return FALSE;
}

void
TestPage2::SetRTF()
{
  CString rtfText = _T("This is some {\\b bold} text.\n")
                    _T("This is some {\\i italic} text.\n")
                    _T("This is some {\\ul underlined} text.\n")
                    _T("This is some {\\cf1 colored} text.\n")
                    _T("This is some {\\f1 different font} text.\n")
                    _T("This is some {\\fs36 \\cf2 large} text.\n")
                    _T("{\\f2 \\cf3 This is monospaced console text}\n")
    ;
  m_editTest13.SetFontname(1,_T("Arial"));
  m_editTest13.SetFontsize(1,24);
  m_editTest13.SetFontname(2,_T("Courier New"));
  m_editTest13.SetFontsize(2,18);
  m_editTest13.SetColor(1,RGB(255,0,0)); // Red
  m_editTest13.SetColor(2,RGB(0,0,255)); // Blue
  m_editTest13.SetColor(3,RGB(0,255,0)); // Green
  m_test13 = m_editTest13.FormatRTFText(rtfText);

  UpdateData(FALSE);
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
  // m_test13 = m_editTest13.GetRTFText();
}
