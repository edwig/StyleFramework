// MySettingsDlg.cpp : implementation file
//
#include "stdafx.h"
#include "MyFrame.h"
#include "MySettingsDlg.h"
#include "MyFrameDlg1.h"
#include "afxdialogex.h"
#include "StyleMessageBox.h"
#include "StyleColors.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


MySettingsDlg::MySettingsDlg(CWnd* pParent /*=NULL*/)
               :StyleDialog(IDD, pParent,true,true)
{
  m_icon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void MySettingsDlg::DoDataExchange(CDataExchange* pDX)
{
  StyleDialog::DoDataExchange(pDX);

  DDX_Control(pDX, IDC_TAB_1, m_tab);
  DDX_Control(pDX, IDOK,      m_buttonOK);
  DDX_Control(pDX, IDCANCEL,  m_buttonCancel);

}

BEGIN_MESSAGE_MAP(MySettingsDlg, StyleDialog)
  ON_WM_CREATE()
  ON_WM_SYSCOMMAND()
  ON_WM_PAINT()
  ON_WM_QUERYDRAGICON()
  ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_1, &MySettingsDlg::OnTcnSelchangeTab1)
END_MESSAGE_MAP()

int
MySettingsDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
  m_grayWindow.CreateEx(0, AfxRegisterWndClass(0), "", WS_POPUP, CRect(0, 0, 0, 0), this, 0);
  return 0;
}

void
MySettingsDlg::OnDestroy()
{
  m_grayWindow.DestroyWindow();
}


// CMyFrameDlg message handlers

BOOL MySettingsDlg::OnInitDialog()
{
  StyleDialog::OnInitDialog();

  // Add "About..." menu item to system menu.

  // IDM_ABOUTBOX must be in the system command range.
  ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
  ASSERT(IDM_ABOUTBOX < 0xF000);

  CMenu* pSysMenu = GetSystemMenu(FALSE);
  if (pSysMenu != NULL)
  {
    BOOL bNameValid;
    CString strAboutMenu;
    bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
    ASSERT(bNameValid);
    if (!strAboutMenu.IsEmpty())
    {
      pSysMenu->AppendMenu(MF_SEPARATOR);
      pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
    }
  }

  SetWindowText("My Settings dialog");

  m_tab.InsertItem(0, nullptr, "First");
  m_tab.InsertItem(1, nullptr, "Second tab");
  m_tab.InsertItem(2, nullptr, "Third");
  m_tab.InsertItem(3, nullptr, "Fourth");
  m_tab.InsertItem(4, nullptr, "Fifth");

  m_tab.SetImages(IDB_TABICONS);
  m_tab.SetTabImage(0, 0);
  m_tab.SetTabImage(1, 1);
  m_tab.SetTabImage(2, 2);
  m_tab.SetTabImage(3, 3);
  m_tab.SetTabImage(4, 4);

  m_tab.SetErrorState(2, 14);
  m_tab.SetUseTabNotch(true);
  m_tab.SetTabActive(4,false);

  // Set the icon for this dialog.  The framework does this automatically
  //  when the application's main window is not a dialog
  SetIcon(m_icon, TRUE);			// Set big icon
  SetIcon(m_icon, FALSE);		// Set small icon

  // Add extra initialization here
  m_buttonOK.SetDefaultButton(true);

  return TRUE;  // return TRUE  unless you set the focus to a control
}

void MySettingsDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
  if ((nID & 0xFFF0) == IDM_ABOUTBOX)
  {
    CAboutDlg dlgAbout;
    dlgAbout.DoModal();
  }
  else
  {
    StyleDialog::OnSysCommand(nID, lParam);
  }
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void MySettingsDlg::OnPaint()
{
  if (IsIconic())
  {
    CPaintDC dc(this); // device context for painting

    SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

    // Center icon in client rectangle
    int cxIcon = GetSystemMetrics(SM_CXICON);
    int cyIcon = GetSystemMetrics(SM_CYICON);
    CRect rect;
    GetClientRect(&rect);
    int x = (rect.Width() - cxIcon + 1) / 2;
    int y = (rect.Height() - cyIcon + 1) / 2;

    // Draw the icon
    dc.DrawIcon(x, y, m_icon);
  }
  else
  {
    StyleDialog::OnPaint();
  }
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR MySettingsDlg::OnQueryDragIcon()
{
  return static_cast<HCURSOR>(m_icon);
}

void
MySettingsDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
  int num = TabCtrl_GetCurSel(pNMHDR->hwndFrom);
}