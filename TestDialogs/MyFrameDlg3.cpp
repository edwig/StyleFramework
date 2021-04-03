// MyFrameDlg3.cpp : implementation file
//
#include "stdafx.h"
#include "MyFrameDlg3.h"
#include "afxdialogex.h"
#include "SkinScrollWnd.h"

// MyFrameDlg3 dialog

IMPLEMENT_DYNAMIC(MyFrameDlg3, StyleDialog)

MyFrameDlg3::MyFrameDlg3(CWnd* pParent /*=nullptr*/)
            :StyleDialog(IDD_DIALOG3, pParent,true,true)
{
}

MyFrameDlg3::~MyFrameDlg3()
{
}

void MyFrameDlg3::DoDataExchange(CDataExchange* pDX)
{
	StyleDialog::DoDataExchange(pDX);

  // Standard CEdit fields
  DDX_Text   (pDX, IDC_EDIT1,     m_edit1);
  DDX_Text   (pDX, IDC_EDIT2,     m_edit2);
  DDX_Text   (pDX, IDC_EDIT3,     m_edit3);

  // Our StyleEdit fields
  DDX_Control(pDX, IDC_EDIT4,     m_edit4,m_string4);
  DDX_Control(pDX, IDC_EDIT5,     m_edit5,m_string5);
  DDX_Control(pDX, IDC_EDIT6,     m_edit6,m_string6);
  DDX_Control(pDX, IDC_EDIT7,     m_edit7,m_string7);

  // Buttons after the fields
  DDX_Control(pDX, IDC_BUTTON,    m_buttonMutations);
  DDX_Control(pDX, IDC_DIR_EDIT4, m_directoryEdit4);
  DDX_Control(pDX, IDC_CAL_EDIT5, m_calendarEdit5);

  // Standard ok/cancel buttons
  DDX_Control(pDX, IDOK,          m_buttonOK);
  DDX_Control(pDX, IDCANCEL,      m_buttonCancel);
}

BEGIN_MESSAGE_MAP(MyFrameDlg3, StyleDialog)
  ON_EN_KILLFOCUS (IDC_EDIT1,    &MyFrameDlg3::OnEnChangeEdit1)
  ON_EN_KILLFOCUS (IDC_EDIT2,    &MyFrameDlg3::OnEnChangeEdit2)
  ON_EN_KILLFOCUS (IDC_EDIT3,    &MyFrameDlg3::OnEnChangeEdit3)
  ON_EN_KILLFOCUS (IDC_EDIT5,    &MyFrameDlg3::OnEnChangeEdit5)
  ON_EN_KILLFOCUS (IDC_EDIT6,    &MyFrameDlg3::OnEnChangeEdit6)
  ON_EN_KILLFOCUS (IDC_EDIT7,    &MyFrameDlg3::OnEnChangeEdit7)
  ON_BN_CLICKED   (IDC_BUTTON,   &MyFrameDlg3::OnBnClickedMutate)
  ON_BN_CLICKED   (IDC_CAL_EDIT5,&MyFrameDlg3::OnBnClickedCalendarEdit5)
  ON_BN_CLICKED   (IDOK,         &MyFrameDlg3::OnBnClickedOk)
  ON_BN_CLICKED   (IDCANCEL,     &MyFrameDlg3::OnBnClickedCancel)
  ON_COMMAND      (ID_THEMA_LIME,      OnStyleLime)
  ON_COMMAND      (ID_THEMA_SKYBLUE,   OnStyleSkyblue)
  ON_COMMAND      (ID_THEMA_PURPLE,    OnStylePurple)
  ON_COMMAND      (ID_THEMA_MODERATE,  OnStyleModerateGray)
  ON_COMMAND      (ID_THEMA_PUREGRAY,  OnStylePureGray)
  ON_COMMAND      (ID_THEMA_BLACKWHITE,OnStyleBlackWhite)
END_MESSAGE_MAP()

BOOL
MyFrameDlg3::OnInitDialog()
{
  StyleDialog::OnInitDialog();
  SetWindowText("Testing the StyleEditText control");
  ShowMinMaxButton(true,false);
  SetSysMenu(IDR_MENU4);

  RegisterTooltips();

  m_edit4.SetMandatory();
  m_edit4.SetEmpty(true,"*");
  m_directoryEdit4.SetStyle("dir");

  m_edit5.SetCalendar();
  m_calendarEdit5.SetStyle("cal");

  // m_string7 = "Testing";
  m_edit7.SetPassword();
  m_edit7.SetEmpty(true,"Enter password");

  UpdateData(FALSE);
  return TRUE;
}

// Checks if all fields are OK
// If one of them is, not 'correct' will be zero
bool
MyFrameDlg3::CheckAllFieldsOK()
{
  int correct = 1;
  correct *= m_edit4.CheckEditOK();
  correct *= m_edit5.CheckEditOK();
  correct *= m_edit6.CheckEditOK();
  correct *= m_edit7.CheckEditOK();
     
  return correct;
}

void
MyFrameDlg3::RegisterTooltips()
{
  EnableToolTips();

  RegisterTooltip(IDC_EDIT1,"This is a tooltip for the first field");
  RegisterTooltip(m_edit4,  "This is a tooltip for the fourth field(Skinned!)");
}

// MyFrameDlg3 message handlers

void MyFrameDlg3::OnEnChangeEdit1()
{
  UpdateData();
}

void MyFrameDlg3::OnEnChangeEdit2()
{
  UpdateData();
}

void MyFrameDlg3::OnEnChangeEdit3()
{
  UpdateData();
}

void MyFrameDlg3::OnEnChangeEdit4()
{
  UpdateData();
}

void MyFrameDlg3::OnBnClickedDirectoryEdit4()
{
  // m_directoryEdit4.StartDirectory(IDC_EDIT4);
}

void 
MyFrameDlg3::OnEnChangeEdit5()
{
  UpdateData();
}

void 
MyFrameDlg3::OnBnClickedCalendarEdit5()
{
  // Use either one of these
  m_calendarEdit5.StartCalendar(IDC_EDIT5);
//m_calendarEdit5.StartCalendar(&m_edit5);
}

void MyFrameDlg3::OnEnChangeEdit6()
{
  UpdateData();

  CString text;
  m_edit6.GetWindowText(text);
  bool error = text.CompareNoCase("error") == 0;
  m_edit6.SetErrorState(error,"You cannot enter 'error' here!");
}

void MyFrameDlg3::OnEnChangeEdit7()
{
  UpdateData();
  m_edit7.SetErrorState(false);
}

void MyFrameDlg3::OnBnClickedMutate()
{
  m_mutate = !m_mutate;
  CWnd* edit2 = GetDlgItem(IDC_EDIT2);
  if(edit2)
  {
    edit2-> EnableWindow(m_mutate);
    m_edit5.EnableWindow(m_mutate);
  }
}

void MyFrameDlg3::OnBnClickedOk()
{
  if(CheckAllFieldsOK() == false)
  {
    UpdateData(FALSE);
    return;
  }
  StyleDialog::OnOK();
}

void MyFrameDlg3::OnBnClickedCancel()
{
  StyleDialog::OnCancel();
}
