// MyFrameDlg.cpp : implementation file
//
#include "stdafx.h"
#include "MyFrame.h"
#include "MyFrameDlg1.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CAboutDlg::CAboutDlg() : StyleDialog(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	StyleDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, StyleDialog)
END_MESSAGE_MAP()

BOOL
CAboutDlg::OnInitDialog()
{
  StyleDialog::OnInitDialog();
  SetWindowText("About StyleFramework");
  m_buttonOK.SetStyle("ok");
  return TRUE;
}

//////////////////////////////////////////////////////////////////////////
//
// MyFrameDlg dialog
//
//////////////////////////////////////////////////////////////////////////

MyFrameDlg1::MyFrameDlg1(CWnd* pParent /*=NULL*/)
	          :StyleDialog(IDD, pParent,true,true)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

MyFrameDlg1::~MyFrameDlg1()
{
}

void MyFrameDlg1::DoDataExchange(CDataExchange* pDX)
{
	StyleDialog::DoDataExchange(pDX);

  DDX_Control(pDX,IDC_BUTTON_1, m_button_1);
  DDX_Control(pDX,IDC_ST_STYLE, m_staticStyle);
  DDX_Control(pDX,IDC_COMBO_1,  m_combo_1);
  DDX_Control(pDX,IDC_ST_STD,   m_staticStandard);

  DDX_Control(pDX,IDC_GROUP1,   m_group1);
  DDX_Control(pDX,IDC_RADIO1,   m_radiobox1);
  DDX_Control(pDX,IDC_RADIO2,   m_radiobox2);
  DDX_Control(pDX,IDC_RADIO3,   m_radiobox3);
  DDX_Control(pDX,IDC_RADIO4,   m_radiobox4);

  DDX_Control(pDX,IDC_GROUP2,   m_group2);
  DDX_Control(pDX,IDC_CHECK1,   m_checkbox1);
  DDX_Control(pDX,IDC_CHECK2,   m_checkbox2);
  DDX_Control(pDX,IDC_LIST,     m_list);
  DDX_Control(pDX,IDOK,         m_buttonOK);
  DDX_Control(pDX,IDCANCEL,     m_buttonCancel);
  DDX_Control(pDX,IDC_COMBO_2,  m_combo_2);

  DDX_Control(pDX,IDC_EDIT_1,   m_edit_1,m_text1);
  DDX_Control(pDX,IDC_MULTI,    m_edit_2,m_text2);
  DDX_Control(pDX,IDC_TEXT,     m_edText,m_text3);
}

BEGIN_MESSAGE_MAP(MyFrameDlg1, StyleDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
  ON_BN_CLICKED   (IDC_BUTTON_1,OnBnClickedButton1)
  ON_CBN_SELENDOK (IDC_COMBO_1, OnCbnCloseupCombo1)
  ON_CBN_SELCHANGE(IDC_COMBO_2, OnCbnCloseupCombo2)
  ON_EN_CHANGE    (IDC_EDIT_1,  OnEnKillfocusEdit1)
END_MESSAGE_MAP()

// CMyFrameDlg message handlers

BOOL MyFrameDlg1::OnInitDialog()
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

  SetWindowText("Style dialog");

  m_button_1.SetIconImage(IDI_SAVE);
  // Set the default button in this dialog
  m_buttonOK.SetDefaultButton(true);
  m_buttonOK.SetStyle("ok");
  m_buttonCancel.SetStyle("can");

  m_text1 = "You should be able to read this text!";
  m_text3 = "This text cannot be edited";

  // Set the icon for this dialog.  The framework does this automatically
  // when the application's main window is not a dialog
  SetIcon(m_hIcon, TRUE);			// Set big icon
  SetIcon(m_hIcon, FALSE);		// Set small icon

  InitCombo1();
  InitCombo2();
  InitList();

  m_edText.EnableWindow(FALSE);

  // Testing static colors
  m_staticStyle.SetTextColor(RGB(0,128,0));

  UpdateData(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void 
MyFrameDlg1::InitList()
{
  // Fill the list control
  m_list.InsertColumn(0, "Example text", 0, 500);

  for (int ind = 0; ind < 40; ++ind)
  {
    CString tekst;
    tekst.Format("This is the list item [%d] with a very long text", ind);
    m_list.InsertItem(ind, tekst);
  }
}

void 
MyFrameDlg1::InitCombo1()
{
  m_combo_1.AddString("Lime");
  m_combo_1.AddString("Skyblue");
  m_combo_1.AddString("Purple");
  m_combo_1.AddString("Moderate gray");
  m_combo_1.AddString("Pure gray");
  m_combo_1.AddString("Black & White");
  m_combo_1.AddString("Dark theme");
}

void 
MyFrameDlg1::InitCombo2()
{
  m_combo_2.SetMinVisibleItems(20);
  m_combo_2.SetMaxDroppedWidth(200); // Max 2 * as width

  // Text in the second combo box
  m_combo_2.ResetContent();
  for(int ind = 0; ind < 40; ++ind)
  {
    CString tekst;
    tekst.Format("This is choice %d from a total of 40", ind + 1);
    m_combo_2.AddString(tekst);
  }
  m_combo_2.AddString("Everything of value is defenseless. Free after: Lucebert. Shown on the side of a building in Rotterdam");
  m_combo_2.AddString("Astra");
  m_combo_2.AddString("Altrom Zero");
  m_combo_2.AddString("Azziza Twice");
  m_combo_2.AddString("ZZ Top");
  
  // Set default choice
  int num = m_combo_2.FindStringExact(0, "ZZ Top");
  m_combo_2.SetCurSel(num);
}

void MyFrameDlg1::OnSysCommand(UINT nID, LPARAM lParam)
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

void MyFrameDlg1::OnPaint()
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
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		StyleDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR MyFrameDlg1::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void
MyFrameDlg1::OnBnClickedButton1()
{
  INT_PTR res = StyleMessageBox(this,"Standard message with a long text to show you the width of this dialog! (Wider than a standard MessageBox().","Testing",MB_YESNO | MB_ICONWARNING);

  if(res == IDNO)
  {
    StyleMessageBox(this,"We are sorry that you couldn't read the text\nPlease tell us what went wrong!","Sorry",MB_OK);
  }

  // Flip window-enabled
  BOOL enab = m_combo_1.IsWindowEnabled();
  m_combo_1.EnableWindow(!enab);
}

void
MyFrameDlg1::OnCbnCloseupCombo1()
{
  int sel = m_combo_1.GetCurSel();
  if(sel >= 0)
  {
    CString message("Your choice was: ");
    message += ThemeColor::theme_names[sel];
    CString message2("We hope you enjoy this style and its controls and colors");
    CString message3("Change the style in any of our programs!");

    m_edText.SetWindowText(message);

    SetTheme((ThemeColor::Themes)sel);

    CreateToast(STYLE_TOAST_MESSAGE,STYLE_POS_BOTLEFT,message,message2,message3);
  }
}

void
MyFrameDlg1::OnCbnCloseupCombo2()
{
  int sel = m_combo_2.GetCurSel();
  if (sel >= 0)
  {
    CString message("Your choice was: ");
    CString choice;
    m_combo_2.GetLBText(sel,choice);
    message += choice;

    StyleMessageBox(this, message, "Info", MB_OK | MB_ICONINFORMATION);
  }
}

void 
MyFrameDlg1::OnEnKillfocusEdit1()
{
  UpdateData();
  CString test;
  m_edit_1.GetWindowText(test);

  bool iserror = test.CompareNoCase("ERROR") == 0;
  CString message = "You may not type the word ERROR here!";
  m_edit_1.SetErrorState(iserror,message);
  
  if(iserror)
  {
    CreateToast(STYLE_TOAST_ERROR,STYLE_POS_BOTLEFT,message,"","",8000);
  }
}
