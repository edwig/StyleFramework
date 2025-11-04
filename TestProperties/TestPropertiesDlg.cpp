// TestPropertiesDlg.cpp : implementation file
//
#include "pch.h"
#include "StyleFramework.h"
#include "TestProperties.h"
#include "TestPropertiesDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAboutDlg dialog used for App About

class CAboutDlg : public StyleDialog
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX) override;
	virtual BOOL OnInitDialog() override;

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

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
	SetWindowText(_T("About..."));
	return TRUE;
}

// TestPropertiesDlg dialog


TestPropertiesDlg::TestPropertiesDlg(CWnd* pParent /*=nullptr*/)
	                 :StyleDialog(IDD_TESTPROPERTIES, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

TestPropertiesDlg::~TestPropertiesDlg()
{
	delete m_page1;
	delete m_page2;
}

void TestPropertiesDlg::DoDataExchange(CDataExchange* pDX)
{
  StyleDialog::DoDataExchange(pDX);
  DDX_Control(pDX,IDC_TYPE, m_editType,m_type);
  DDX_Control(pDX,IDC_TABS, m_tabs);
  DDX_Control(pDX,IDOK,			m_buttonOK);
  DDX_Control(pDX,IDC_TYPE,	m_editType,m_type);
}

BEGIN_MESSAGE_MAP(TestPropertiesDlg, StyleDialog)
  ON_WM_SYSCOMMAND()
  ON_WM_PAINT()
  ON_WM_QUERYDRAGICON()
  ON_EN_KILLFOCUS(IDC_TYPE,OnEnChangeType)
END_MESSAGE_MAP()


// TestPropertiesDlg message handlers

BOOL TestPropertiesDlg::OnInitDialog()
{
	StyleDialog::OnInitDialog();
	SetWindowText(_T("Test Property pages"));
  SetWindowText(_T("My Settings dialog"));

	// Add extra initialization here
	ShowMinMaxButton();
	ShowSysMenu();

	InitTabs();

	// MUST be called after all init
	SetCanResize();

	m_editType.SetFocus();
	return FALSE;
}

void 
TestPropertiesDlg::SetupDynamicLayout()
{
	StyleDialog::SetupDynamicLayout();

	auto manager = GetDynamicLayout();
	if (manager != nullptr)
	{
		manager->AddItem(IDC_STATIC1,CMFCDynamicLayout::MoveNone()                        ,CMFCDynamicLayout::SizeNone());
		manager->AddItem(IDC_TYPE   ,CMFCDynamicLayout::MoveNone()                        ,CMFCDynamicLayout::SizeHorizontal(100));
		manager->AddItem(IDC_TABS   ,CMFCDynamicLayout::MoveNone()                        ,CMFCDynamicLayout::SizeHorizontalAndVertical(100,100));
		manager->AddItem(m_buttonOK ,CMFCDynamicLayout::MoveHorizontalAndVertical(100,100),CMFCDynamicLayout::SizeNone());
	}
}

void 
TestPropertiesDlg::InitTabs()
{
	m_page1 = new TestPage1(this);
	m_page2 = new TestPage2(this);
	m_page1->Create(IDD_TESTPAGE1,&m_tabs);
	m_page2->Create(IDD_TESTPAGE2,&m_tabs);

  m_tabs.InsertItem(0, m_page1, _T("First Page"));
  m_tabs.InsertItem(1, m_page2, _T("Second Page"));
  m_tabs.InsertItem(2, nullptr, _T("Third Page"));
  m_tabs.InsertItem(3, nullptr, _T("Fourth Page"));
  m_tabs.InsertItem(4, nullptr, _T("Fifth Page"));

  m_tabs.SetImages(IDB_TABICONS);
  m_tabs.SetTabImage(0, 0);
  m_tabs.SetTabImage(1, 1);
  m_tabs.SetTabImage(2, 2);
  m_tabs.SetTabImage(3, 3);
  m_tabs.SetTabImage(4, 4);

  m_tabs.SetUseTabNotch(true);
	m_tabs.Init();
}

void TestPropertiesDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void TestPropertiesDlg::OnPaint()
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
HCURSOR TestPropertiesDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void
TestPropertiesDlg::OnEnChangeType()
{
	UpdateData();
}
