// MyFrameDlg7.cpp : implementation file
//
#include "stdafx.h"
#include "MyFrameDlg7.h"
#include "afxdialogex.h"
#include "resource.h"

// MyFrameDlg7 dialog

IMPLEMENT_DYNAMIC(MyFrameDlg7, StyleDialog)

MyFrameDlg7::MyFrameDlg7(CWnd* pParent /*=nullptr*/)
	          :StyleDialog(IDD_DIALOG7, pParent)
{
  m_total    = 100;
  m_interval = 50;
}

MyFrameDlg7::~MyFrameDlg7()
{
}

void MyFrameDlg7::DoDataExchange(CDataExchange* pDX)
{
	StyleDialog::DoDataExchange(pDX);
  DDX_Control(pDX, IDC_RESET,     m_buttonReset);
  DDX_Control(pDX, IDC_PROGRESS1, m_progress1);
  DDX_Control(pDX, IDC_PROGRESS2, m_progress2);
  DDX_Control(pDX, IDC_STARTM,    m_buttonStartMarquee);
  DDX_Control(pDX, IDC_STOPM,     m_buttonStopMarquee);
  DDX_Control(pDX, IDC_START,     m_buttonStart);
  DDX_Control(pDX, IDC_PAUSE,     m_buttonPause);
  DDX_Control(pDX, IDC_ERROR,     m_buttonError);
  DDX_Control(pDX, IDOK,          m_buttonOK);
  DDX_Control(pDX, IDCANCEL,      m_buttonCancel);
  DDX_Control(pDX, IDC_TOTAL,     m_editTotal,m_total);
  DDX_Control(pDX, IDC_INTERVAL,  m_editInterval,m_interval);
}


BEGIN_MESSAGE_MAP(MyFrameDlg7, StyleDialog)
  ON_WM_TIMER()
  ON_EN_KILLFOCUS(IDC_TOTAL,    &MyFrameDlg7::OnEnChangeTotal)
  ON_EN_KILLFOCUS(IDC_INTERVAL, &MyFrameDlg7::OnEnChangeInterval)
  ON_BN_CLICKED  (IDC_RESET,    &MyFrameDlg7::OnBnClickedReset)
  ON_BN_CLICKED  (IDC_STARTM,   &MyFrameDlg7::OnBnClickedStartMarquee)
  ON_BN_CLICKED  (IDC_STOPM,    &MyFrameDlg7::OnBnClickedStopMarquee)
  ON_BN_CLICKED  (IDC_START,    &MyFrameDlg7::OnBnClickedStart)
  ON_BN_CLICKED  (IDC_PAUSE,    &MyFrameDlg7::OnBnClickedPause)
  ON_BN_CLICKED  (IDC_ERROR,    &MyFrameDlg7::OnBnClickedError)
  ON_BN_CLICKED  (IDOK,         &MyFrameDlg7::OnBnClickedOk)
  ON_BN_CLICKED  (IDCANCEL,     &MyFrameDlg7::OnBnClickedCancel)
  ON_COMMAND     (ID_THEMA_LIME,      OnStyleLime)
  ON_COMMAND     (ID_THEMA_SKYBLUE,   OnStyleSkyblue)
  ON_COMMAND     (ID_THEMA_PURPLE,    OnStylePurple)
  ON_COMMAND     (ID_THEMA_MODERATE,  OnStyleModerateGray)
  ON_COMMAND     (ID_THEMA_PUREGRAY,  OnStylePureGray)
  ON_COMMAND     (ID_THEMA_BLACKWHITE,OnStyleBlackWhite)
END_MESSAGE_MAP()

BOOL
MyFrameDlg7::OnInitDialog()
{
  StyleDialog::OnInitDialog();
  SetWindowText("Testing the progress control");
  SetSysMenu(IDR_MENU4);
  ShowMinMaxButton(true, false);

  m_buttonOK    .SetStyle("ok");
  m_buttonCancel.SetStyle("can");

  UpdateData(FALSE);

  return TRUE;
}

// MyFrameDlg7 message handlers

void 
MyFrameDlg7::OnEnChangeTotal()
{
  UpdateData();
}

void 
MyFrameDlg7::OnEnChangeInterval()
{
  UpdateData();
}

void 
MyFrameDlg7::OnTimer(UINT_PTR nID)
{
  if (nID == 1)
  {
    m_progress2.StepIt();

    int index = m_progress1.StepIt();
    
    int lower = 0;
    int upper = 0;
    m_progress1.GetRange(lower,upper);

    // Ready?
    if (index == upper)
    {
      KillTimer(1);
    }
  }
}


void 
MyFrameDlg7::OnBnClickedStart()
{
  m_progress1.SetRange(0,m_total);
  m_progress1.SetPos(0);
  m_progress1.SetStep(1);

  m_progress2.SetRange(0, m_total);
  m_progress2.SetPos(0);
  m_progress2.SetStep(1);


  SetTimer(1, m_interval, nullptr);
}

void
MyFrameDlg7::OnBnClickedPause()
{
  int state = m_progress1.GetState();
  if (state == PBST_NORMAL)
  {
    m_progress1.SetState(PBST_PAUSED);
  }
  else
  {
    m_progress1.SetState(PBST_NORMAL);
  }
}

void
MyFrameDlg7::OnBnClickedError()
{
  int state = m_progress1.GetState();
  if (state == PBST_NORMAL)
  {
    m_progress1.SetState(PBST_ERROR);
  }
  else
  {
    m_progress1.SetState(PBST_NORMAL);
  }
}

void
MyFrameDlg7::OnBnClickedReset()
{
  m_total    = 100;
  m_interval = 50;
  m_progress1.SetRange32(0, 100);
  m_progress2.SetRange32(0, 100);
  m_progress1.SetStep(1);
  m_progress2.SetStep(1);
  m_progress1.SetPos(0);
  m_progress2.SetPos(0);
  m_progress1.SetState(PBST_NORMAL);
  m_progress2.SetState(PBST_NORMAL);

  UpdateData(FALSE);
}

void
MyFrameDlg7::OnBnClickedStartMarquee()
{
  m_progress1.SetRange32(0,m_total);
  m_progress1.SetStep(1);
  m_progress2.SetRange32(0, m_total);
  m_progress2.SetStep(1);

  m_progress1.SetMarquee(TRUE, m_interval);
  m_progress2.SetMarquee(TRUE, m_interval);
}

void
MyFrameDlg7::OnBnClickedStopMarquee()
{
  m_progress1.SetMarquee(FALSE, 0);
  m_progress2.SetMarquee(FALSE, 0);
}

void 
MyFrameDlg7::OnBnClickedOk()
{
  StyleDialog::OnOK();
}

void 
MyFrameDlg7::OnBnClickedCancel()
{
  StyleDialog::OnCancel();
}
