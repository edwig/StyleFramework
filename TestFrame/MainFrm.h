// MainFrm.h : interface of the CMainFrame class
//
#pragma once
#include "FileView.h"
#include "ClassView.h"
#include "OutputWnd.h"
#include "PropertiesWnd.h"
#include "CalendarBar.h"
#include "Resource.h"

#if MENUFRAME
#define BaseFrame StyleFrameWndEx  // 6 Menu icons in large titlebar
#else
#define BaseFrame StyleFrameWnd    // Small titlebar with standard menu's
#endif

class COutlookBar : public CMFCOutlookBar
{
	virtual BOOL AllowShowOnPaneMenu() const { return TRUE; }
	virtual void GetPaneName(CString& strName) const { BOOL bNameValid = strName.LoadString(IDS_OUTLOOKBAR); ASSERT(bNameValid); if (!bNameValid) strName.Empty(); }
};

class MainFrame : public BaseFrame
{
	
protected: // create from serialization only
	MainFrame();
	DECLARE_DYNCREATE(MainFrame)

  virtual BOOL Create(LPCTSTR lpszClassName,
                      LPCTSTR lpszWindowName,
                      DWORD   dwStyle       = WS_OVERLAPPEDWINDOW,
                      const   RECT& rect    = CFrameWnd::rectDefault,
                      CWnd*   pParentWnd    = NULL,
                      LPCTSTR lpszMenuName  = NULL,
                      DWORD   dwExStyle     = 0,
                      CCreateContext* pContext = NULL);

public:
	virtual BOOL LoadFrame(UINT nIDResource, DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, CWnd* pParentWnd = NULL, CCreateContext* pContext = NULL);
	virtual ~MainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CMFCToolBar       m_wndToolBar;
	CMFCStatusBar     m_wndStatusBar;
	CMFCToolBarImages m_UserImages;
	CFileView         m_wndFileView;
	CClassView        m_wndClassView;
	COutputWnd        m_wndOutput;
	CPropertiesWnd    m_wndProperties;
	COutlookBar       m_wndNavigationBar;
	CMFCShellTreeCtrl m_wndTree;
	CCalendarBar      m_wndCalendar;
	CMFCCaptionBar    m_wndCaptionBar;
#if MENUFRAME == 0
  CMFCMenuBar       m_wndMenuBar;
  CMenu m_menu;
#endif

// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnViewCustomize();
	afx_msg LRESULT OnToolbarCreateNew(WPARAM wp, LPARAM lp);
	afx_msg void OnApplicationLook(UINT id);
	afx_msg void OnUpdateApplicationLook(CCmdUI* pCmdUI);
	afx_msg void OnViewFileView();
	afx_msg void OnUpdateViewFileView(CCmdUI* pCmdUI);
	afx_msg void OnViewClassView();
	afx_msg void OnUpdateViewClassView(CCmdUI* pCmdUI);
	afx_msg void OnViewOutputWindow();
	afx_msg void OnUpdateViewOutputWindow(CCmdUI* pCmdUI);
	afx_msg void OnViewPropertiesWindow();
	afx_msg void OnUpdateViewPropertiesWindow(CCmdUI* pCmdUI);
	afx_msg void OnViewCaptionBar();
	afx_msg void OnUpdateViewCaptionBar(CCmdUI* pCmdUI);
	afx_msg void OnOptions();
	afx_msg void OnSettingChange(UINT uFlags, LPCTSTR lpszSection);
	afx_msg void OnTesting();
	afx_msg LRESULT OnToastMessage(WPARAM wp,LPARAM lp);
	DECLARE_MESSAGE_MAP()

	BOOL CreateDockingWindows();
	void SetDockingWindowIcons(BOOL bHiColorIcons);
	BOOL CreateOutlookBar(CMFCOutlookBar& bar, UINT uiID, CMFCShellTreeCtrl& tree, CCalendarBar& calendar, int nInitialWidth);
	BOOL CreateCaptionBar();

	int FindFocusedOutlookWnd(CMFCOutlookBarTabCtrl** ppOutlookWnd);

	CMFCOutlookBarTabCtrl* FindOutlookParent(CWnd* pWnd);
  CMFCOutlookBarTabCtrl* m_pCurrOutlookWnd  { nullptr };
	CMFCOutlookBarPane*    m_pCurrOutlookPage { nullptr };

};
