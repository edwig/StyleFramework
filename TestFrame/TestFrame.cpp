// TestFrame.cpp : Defines the class behaviors for the application.
//
#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "TestFrame.h"
#include "MainFrm.h"
#include "StdException.h"

#include "TestFrameDoc.h"
#include "TestFrameView.h"
#include <StyleDialog.h>
#include <RegistryManager.h>
#include <StyleMessageBox.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestFrameApp

BEGIN_MESSAGE_MAP(CTestFrameApp, BaseWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CTestFrameApp::OnAppAbout)
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, &BaseWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &BaseWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, &BaseWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()


// CTestFrameApp construction

CTestFrameApp::CTestFrameApp()
							:m_handler(this)
{
	m_bHiColorIcons = TRUE;

	// replace application ID string below with unique ID string; recommended
	// format for string is CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("Edwig.TestFrame.Test.1_0"));
}

// The one and only CTestFrameApp object

CTestFrameApp theApp;


// CTestFrameApp initialization

BOOL CTestFrameApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	BaseWinApp::InitInstance();

  AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// AfxInitRichEdit2() is required to use RichEdit control
	// AfxInitRichEdit2();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	
	SetRegistryKey("EDO\\MyFrame");
	if(SetRegistryProfile("EDO\\MyFrame",PROGRAM_NAME,"2.0"))
	{
		StyleMessageBox(nullptr,"Version change: Your previous profile has been reset","Warning",MB_OK|MB_ICONINFORMATION);
	}
	LoadStdProfileSettings(10);  // Load standard INI file options (including MRU)

	InitContextMenuManager();
  InitKeyboardManager();
	InitShellManager();
	InitTooltipManager();
	InitToast();

  CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(IDR_MAINFRAME,
		                                    RUNTIME_CLASS(CTestFrameDoc),
		                                    RUNTIME_CLASS(MainFrame),       // main SDI frame window
		                                    RUNTIME_CLASS(CTestFrameView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);


	// Dispatch commands specified on the command line.  Will return FALSE if
	// app was launched with /RegServer, /Register, /Unregserver or /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

  LoadCustomState();

	// The one and only window has been initialized, so show and update it
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	ShowStartToast();

	return TRUE;
}

// main running routine until thread exits
int 
CTestFrameApp::Run()
{
  ASSERT_VALID(this);
  _AFX_THREAD_STATE* pState = AfxGetThreadState();

  // for tracking the idle time state
  BOOL bIdle = TRUE;
  LONG lIdleCount = 0;

  // acquire and dispatch messages until a WM_QUIT message is received.
  for (;;)
  {
    // phase1: check to see if we can do idle work
    while (bIdle && !::PeekMessage(&(pState->m_msgCur), NULL, NULL, NULL, PM_NOREMOVE))
    {
      // call OnIdle while in bIdle state
			if (!OnIdle(lIdleCount++))
			{
				bIdle = FALSE; // assume "no idle" state
			}
    }

    // phase2: pump messages while available
    do
    {
      // pump message, but quit on WM_QUIT
			if (!PumpMessage())
			{
				return ExitInstance();
			}

      // reset "no idle" state after pumping "normal" message
      //if (IsIdleMessage(&m_msgCur))
      if (IsIdleMessage(&(pState->m_msgCur)))
      {
        bIdle = TRUE;
        lIdleCount = 0;
      }
    } 
		while (::PeekMessage(&(pState->m_msgCur), NULL, NULL, NULL, PM_NOREMOVE));
  }
}

BOOL 
CTestFrameApp::PumpMessage()
{
  _AFX_THREAD_STATE* pState = AfxGetThreadState();
	MSG* msg = &(pState->m_msgCur);

  AutoSeTranslator trans(SeTranslator);

	try
	{
		BOOL result = ::GetMessage(msg, nullptr, 0, 0);

		if (result == 0)
		{
			// Note: prevents calling message loop things in 'ExitInstance'
			// WM_QUIT Received. Stop the message loop
			return FALSE;
		}

		// Error while receiving message
		// Can result from messages for windows already destroyed
		// Return TRUE, so we stay in the application
		if (result == -1)
		{
			return TRUE;
		}

		// Do the on-idle handlers
		if (msg->message == WM_KICKIDLE)
		{
			OnIdle(0);
			return TRUE;
		}
		// Pre-Process menu key items for the main window
		bool dispatch = true;
		BaseFrame* main = dynamic_cast<BaseFrame*>(m_pMainWnd);
		if (main)
		{
			dispatch = !main->PreTranslateMenu(msg);
		}
		if (dispatch && !PreTranslateMessage(msg))
    {
			::TranslateMessage(msg);
			::DispatchMessage(msg);
		}
	}
	catch (StdException& ex)
	{
	  StyleMessageBox(nullptr,ex.GetErrorMessage(),"Testing",MB_OK|MB_ICONERROR);
	}
  return TRUE;
}

// CTestFrameApp message handlers

// CAboutDlg dialog used for App About

class CAboutDlg : public StyleDialog
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif
  virtual BOOL OnInitDialog() override;

protected:
	virtual void DoDataExchange(CDataExchange* pDX) override;

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

  SetWindowText("About StylingFramework");

  return FALSE;
}


// App command to run the dialog
void CTestFrameApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CTestFrameApp customization load/save methods
void 
CTestFrameApp::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
	bNameValid = strName.LoadString(IDS_EXPLORER);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EXPLORER);
}

void CTestFrameApp::LoadCustomState()
{
}

void CTestFrameApp::SaveCustomState()
{
}

void
CTestFrameApp::InitToast()
{
  // TODO: Add extra initialization here
  WinToast::WinToastError error;
  WinToast::instance()->setAppName(L"TestFrame");
  const auto aumi = WinToast::configureAUMI(L"EDO", L"MyFrame", L"TestFrame", L"2021.1.0");
  WinToast::instance()->setAppUserModelId(aumi);

  if (!WinToast::instance()->initialize(&error))
  {
    CString message;
    message.Format("Failed to initialize WinToast :%d", error);
    StyleMessageBox(m_pMainWnd,message,"Error",MB_OK|MB_ICONERROR);
  }
}


void CTestFrameApp::ShowStartToast()
{
  WinToastTemplate templ;
  if(WinToast::isWin10AnniversaryOrHigher())
  {
    templ = WinToastTemplate(WinToastTemplate::HeroImageAndImageAndText04);
    bool inlineImage = false;

    // Beware: **MUST** be an absolute pathname
    templ.setHeroImagePath(L"C:\\Develop\\StyleFrameWork\\TestFrame\\Edwig_Koala.png", inlineImage);
  }
  else
  {
    templ = WinToastTemplate(WinToastTemplate::ImageAndText04);
  }
  // Beware: **MUST** be an absolute pathname
  templ.setImagePath(L"C:\\Develop\\StyleFrameWork\\TestFrame\\EdwigHuisman.jpg", WinToastTemplate::CropHint::Circle);

  templ.setTextField(L"You are logged in",								WinToastTemplate::FirstLine);
  templ.setTextField(L"Session: edwig on database 'test'",WinToastTemplate::SecondLine);
  templ.setTextField(L"Application: Open-ERP",			      WinToastTemplate::ThirdLine);

  templ.addAction(L"OK");
  templ.addAction(L"Show details");

  templ.setDuration(WinToastTemplate::Duration::Long);
  templ.setAudioOption(WinToastTemplate::AudioOption::Default);
  templ.setAudioPath(WinToastTemplate::AudioSystemFile::Call1);
  templ.setExpiration(CLOCKS_PER_SEC * 60 * 60 * 8); // One working day
  templ.setAttributionText(L"Global session number: 1234");


  if(WinToast::instance()->showToast(templ,&m_handler) == -1L)
  {
    StyleMessageBox(m_pMainWnd,"Could not launch your toast notification!","Error",MB_OK|MB_ICONERROR);
  }
}

// CTestFrameApp message handlers
