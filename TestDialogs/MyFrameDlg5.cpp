// MyFrameDlg5.cpp : implementation file
//
#include "stdafx.h"
#include "MyFrameDlg5.h"
#include "StyleMessageBox.h"

// MyFrameDlg5 dialog

IMPLEMENT_DYNAMIC(MyFrameDlg5, StyleDialog)

MyFrameDlg5::MyFrameDlg5(CWnd* pParent /*=nullptr*/)
            :StyleDialog(IDD, pParent)
{

}

MyFrameDlg5::~MyFrameDlg5()
{
}

void MyFrameDlg5::DoDataExchange(CDataExchange* pDX)
{
	StyleDialog::DoDataExchange(pDX);

  DDX_Control(pDX,IDC_EDIT,   m_edit,m_string);
  DDX_Control(pDX,IDC_ADD,    m_buttonAdd);
  DDX_Control(pDX,IDC_LIST1,  m_list1);
  DDX_Control(pDX,IDC_LIST2,  m_list2);
  DDX_Control(pDX,IDC_LEGEN,  m_buttonLegen);
  DDX_Control(pDX,IDC_PRINTEN,m_buttonPrinten);
  DDX_Control(pDX,IDOK,       m_buttonOK);
  DDX_Control(pDX,IDCANCEL,   m_buttonCancel);
}


BEGIN_MESSAGE_MAP(MyFrameDlg5, StyleDialog)
  ON_EN_KILLFOCUS (IDC_EDIT,    &MyFrameDlg5::OnEnChangeEdit)
  ON_BN_CLICKED   (IDC_ADD,     &MyFrameDlg5::OnBnClickedAdd)
  ON_LBN_SELCHANGE(IDC_LIST1,   &MyFrameDlg5::OnLbnSelchangeList1)
  ON_LBN_SELCHANGE(IDC_LIST2,   &MyFrameDlg5::OnLbnSelchangeList2)
  ON_BN_CLICKED   (IDC_LEGEN,   &MyFrameDlg5::OnBnClickedLegen)
  ON_BN_CLICKED   (IDC_PRINTEN, &MyFrameDlg5::OnBnClickedPrinten)
  ON_BN_CLICKED   (IDOK,        &MyFrameDlg5::OnBnClickedOk)
  ON_BN_CLICKED   (IDCANCEL,    &MyFrameDlg5::OnBnClickedCancel)
END_MESSAGE_MAP()

BOOL
MyFrameDlg5::OnInitDialog()
{
  LoadStyleTheme();
  StyleDialog::OnInitDialog();
  SetWindowText("Testing the ListBox");
  ShowMinMaxButton();
  SetSysMenu(IDR_MENU4);
  ShowSysMenu();

  SetCanResize();

  return TRUE;
}

void 
MyFrameDlg5::SetupDynamicLayout()
{
  StyleDialog::SetupDynamicLayout();

  CMFCDynamicLayout& manager = *GetDynamicLayout();
#ifdef _DEBUG
  manager.AssertValid();
#endif

  HWND list1 = m_list1.GetSkin()->GetSafeHwnd();
  HWND list2 = m_list2.GetSkin()->GetSafeHwnd();

  manager.AddItem(IDC_EDIT,       manager.MoveNone(),                          manager.SizeHorizontal(100));
  manager.AddItem(m_buttonAdd,    manager.MoveHorizontal(100),                 manager.SizeNone());
  manager.AddItem(IDC_LIST1,      manager.MoveNone(),                          manager.SizeHorizontalAndVertical(50,100));
  manager.AddItem(IDC_LIST2,      manager.MoveHorizontal(50),                  manager.SizeHorizontalAndVertical(50,100));
  manager.AddItem(m_buttonLegen,  manager.MoveVertical(100),                   manager.SizeNone());
  manager.AddItem(m_buttonPrinten,manager.MoveVertical(100),                   manager.SizeNone());
  manager.AddItem(m_buttonOK,     manager.MoveHorizontalAndVertical(100, 100), manager.SizeNone());
  manager.AddItem(m_buttonCancel, manager.MoveHorizontalAndVertical(100, 100), manager.SizeNone());

  manager.Adjust();
}

// MyFrameDlg5 message handlers

void 
MyFrameDlg5::OnEnChangeEdit()
{
  UpdateData();
}

void 
MyFrameDlg5::OnBnClickedAdd()
{
  if(m_string.IsEmpty())
  {
    StyleMessageBox(this,"Fill in a text first","ERROR",MB_OK | MB_ICONERROR);
    return;
  }
  m_list1.AddString(m_string);
  m_list2.AddString(m_string);
}

void 
MyFrameDlg5::OnLbnSelchangeList1()
{
  int ind = m_list1.GetCurSel();
  if(ind >= 0)
  {
    CString text;
    m_list1.GetText(ind,text);
    StyleMessageBox(this,text,"Line from list 1",MB_OK);
  }
}

void
MyFrameDlg5::OnLbnSelchangeList2()
{
  int ind = m_list2.GetCurSel();
  if (ind >= 0)
  {
    CString text;
    m_list2.GetText(ind, text);
    StyleMessageBox(this, text, "Line from list 2", MB_OK);
  }
}

void
MyFrameDlg5::OnBnClickedLegen()
{
  m_list1.ResetContent();
  m_list2.ResetContent();
}

void
MyFrameDlg5::OnBnClickedPrinten()
{
  m_list1.Print("Left side list");
}

void 
MyFrameDlg5::OnBnClickedOk()
{
  OnOK();
}

void 
MyFrameDlg5::OnBnClickedCancel()
{
  OnCancel();
}

