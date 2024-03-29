// MyFrameDlg.h : header file
//
#pragma once
#include "resource.h"

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
  StyleButton m_buttonOK;
protected:
  DECLARE_MESSAGE_MAP()
};

// CMyFrameDlg dialog
class MyFrameDlg1 : public StyleDialog
{
// Construction
public:
	MyFrameDlg1(CWnd* pParent = NULL);	// standard constructor
  virtual ~MyFrameDlg1();

	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

// Implementation
protected:
  void InitList();
  void InitCombo1();
  void InitCombo2();

  StyleStatic       m_staticStyle;
  StyleStatic       m_staticStandard;
  StyleButton       m_button_1;
  StyleComboBox     m_combo_1;
  StyleComboBox     m_combo_2;
  StyleEdit         m_edit_1;
  StyleEdit         m_edit_2;
  CString           m_text1;
  CString           m_text2;
  CString           m_text3;
  StyleEdit         m_edText;

  StyleGroupBox     m_group1;
  StyleGroupBox     m_group2;
  StyleCheckbox     m_radiobox1;
  StyleCheckbox     m_radiobox2;
  StyleCheckbox     m_radiobox3;
  StyleCheckbox     m_radiobox4;
  StyleCheckbox     m_checkbox1;
  StyleCheckbox     m_checkbox2;

  StyleListCtrl     m_list;

  StyleButton       m_buttonOK;
  StyleButton       m_buttonCancel;

  HBITMAP           m_hBmpScrollBar;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
  afx_msg void OnBnClickedButton1();
  afx_msg void OnCbnCloseupCombo1();
  afx_msg void OnCbnCloseupCombo2();
  afx_msg void OnEnKillfocusEdit1();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};


