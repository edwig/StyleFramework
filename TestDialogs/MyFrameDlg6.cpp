o// MyFrameDlg6.cpp : implementation file
//
#include "stdafx.h"
#include "MyFrameDlg6.h"
#include "StyleMessageBox.h"

// MyFrameDlg6 dialog

IMPLEMENT_DYNAMIC(MyFrameDlg6, StyleDialog)

MyFrameDlg6::MyFrameDlg6(CWnd* pParent /*=nullptr*/)
            :StyleDialog(IDD, pParent)
{

}

MyFrameDlg6::~MyFrameDlg6()
{
}

void MyFrameDlg6::DoDataExchange(CDataExchange* pDX)
{
	StyleDialog::DoDataExchange(pDX);

  DDX_Control(pDX,IDC_EDIT, m_edit,m_string);
  DDX_Control(pDX,IDC_ADD,  m_buttonAdd);
  DDX_Control(pDX,IDC_TREE1,m_list1);
  DDX_Control(pDX,IDC_TREE2,m_list2);
  DDX_Control(pDX,IDC_LEGEN,m_buttonLegen);
  DDX_Control(pDX,IDOK,     m_buttonOK);
  DDX_Control(pDX,IDCANCEL, m_buttonCancel);
}

BEGIN_MESSAGE_MAP(MyFrameDlg6, StyleDialog)
  ON_EN_KILLFOCUS (IDC_EDIT,  &MyFrameDlg6::OnEnChangeEdit)
  ON_BN_CLICKED   (IDC_ADD,   &MyFrameDlg6::OnBnClickedAdd)
  ON_BN_CLICKED   (IDC_LEGEN, &MyFrameDlg6::OnBnClickedLegen)
  ON_BN_CLICKED   (IDOK,      &MyFrameDlg6::OnBnClickedOk)
  ON_BN_CLICKED   (IDCANCEL,  &MyFrameDlg6::OnBnClickedCancel)
END_MESSAGE_MAP()

BOOL
MyFrameDlg6::OnInitDialog()
{ 
  StyleDialog::OnInitDialog();
  SetWindowText("Testing the TreeControl");
  ShowMinMaxButton();
  SetSysMenu(IDR_MENU4);
  ShowSysMenu();

  SetCanResize();

  return InitFirstFocus();
}

void 
MyFrameDlg6::SetupDynamicLayout()
{
  StyleDialog::SetupDynamicLayout();

  CMFCDynamicLayout& manager = *GetDynamicLayout();
#ifdef _DEBUG
  manager.AssertValid();
#endif

  HWND edit  = m_edit .GetSkin()->GetSafeHwnd();
  HWND list1 = m_list1.GetSkin()->GetSafeHwnd();
  HWND list2 = m_list2.GetSkin()->GetSafeHwnd();

  manager.AddItem(edit,          manager.MoveNone(),                          manager.SizeHorizontal(100));
  manager.AddItem(m_buttonAdd,   manager.MoveHorizontal(100),                 manager.SizeNone());
  manager.AddItem(list1,         manager.MoveNone(),                          manager.SizeHorizontalAndVertical(50,100));
  manager.AddItem(list2,         manager.MoveHorizontal(50),                  manager.SizeHorizontalAndVertical(50,100));
  manager.AddItem(m_buttonLegen, manager.MoveVertical(100),                   manager.SizeNone());
  manager.AddItem(m_buttonOK,    manager.MoveHorizontalAndVertical(100, 100), manager.SizeNone());
  manager.AddItem(m_buttonCancel,manager.MoveHorizontalAndVertical(100, 100), manager.SizeNone());

  manager.Adjust();
}

// MyFrameDlg6 message handlers

void 
MyFrameDlg6::OnEnChangeEdit()
{
  UpdateData();
}

static HTREEITEM hParent1 = TVI_ROOT;
static HTREEITEM hParent2 = TVI_ROOT;

void
MyFrameDlg6::OnBnClickedAdd()
{
  if(m_string.IsEmpty())
  {
    StyleMessageBox(this,"Fill in a text first","ERROR",MB_OK | MB_ICONERROR);
    return;
  }

  hParent1 = m_list1.InsertItem(m_string, hParent1);
  m_list1.EnsureVisible(hParent1);

  hParent2 = m_list2.InsertItem(m_string, hParent2);
  m_list2.EnsureVisible(hParent2);
}

void 
MyFrameDlg6::OnLbnSelchangeList1()
{
}

void
MyFrameDlg6::OnLbnSelchangeList2()
{
}

void
MyFrameDlg6::OnBnClickedLegen()
{
  m_list1.DeleteAllItems();
  m_list2.DeleteAllItems();
  hParent1 = TVI_ROOT;
  hParent2 = TVI_ROOT;
}

void 
MyFrameDlg6::OnBnClickedOk()
{
  OnOK();
}

void 
MyFrameDlg6::OnBnClickedCancel()
{
  OnCancel();
}

