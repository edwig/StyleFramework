// TestPropertiesDlg.h : header file
//
#pragma once
#include "TestPage1.h"
#include "TestPage2.h"
#include "resource.h"

// TestPropertiesDlg dialog
class TestPropertiesDlg : public StyleDialog
{
// Construction
public:
	TestPropertiesDlg(CWnd* pParent = nullptr);	// standard constructor
	virtual ~TestPropertiesDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTPROPERTIES };
#endif

	protected:
  virtual void DoDataExchange(CDataExchange* pDX) override;
  virtual BOOL OnInitDialog() override;
	virtual void SetupDynamicLayout() override;

// Implementation
protected:
	void InitTabs();

	CString       m_type;
	StyleEdit     m_editType;
	StyleButton	  m_buttonOK;
	StyleTabCtrl  m_tabs;

	TestPage1*    m_page1 { nullptr };
	TestPage2*    m_page2 { nullptr };

	// Generated message map functions
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnEnChangeType();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	DECLARE_MESSAGE_MAP()
};
