// MyFrameDlg.h : header file
//
#pragma once
#include "resource.h"

// CMyFrameDlg dialog
class MyFrameDlg2 : public StyleDialog
{
// Construction
public:
	MyFrameDlg2(CWnd* pParent = NULL);	// standard constructor
  virtual ~MyFrameDlg2();

	enum { IDD = IDD_DIALOG2 };

protected:
  virtual void DoDataExchange(CDataExchange* pDX) override;
  virtual void SetupDynamicLayout() override;
  virtual BOOL OnInitDialog() override;


// Implementation
protected:
  void FillCombo1();
  void FillCombo2();
  void FillCombo3();
  void SetSpinButtons();
  void RegisterTooltips();

  int             m_error;
  StyleComboBox   m_combo_1;
  StyleComboBox   m_combo_2;
  StyleComboBox   m_combo_3;
  StyleCheckbox   m_check1;
  StyleCheckbox   m_check2;
  StyleCheckbox   m_check3;
  StyleEdit       m_editString1;
  StyleEdit       m_editString2;
  CString         m_string1;
  CString         m_string2;
  StyleSpinButtonCtrl m_spin1;
  StyleSpinButtonCtrl m_spin2;
  StyleHyperLink  m_visitEdwig;
  StyleButton     m_buttonError;
  StyleStatic     m_staticColor;
  StyleStatic     m_staticMulti;
  StyleStatic     m_staticEnabled;
  StyleStatic     m_staticNumber10;
  StyleStatic     m_staticNumber20;
  StyleStatic     m_staticTest;
  StyleButton     m_buttonOK;
  StyleButton     m_buttonCancel;

  DECLARE_MESSAGE_MAP()

public:
  // Generated message map functions
  afx_msg void OnPaint();
  afx_msg void OnCbnCloseupCombo1();
  afx_msg void OnCbnCloseupCombo2();
  afx_msg void OnCbnCloseupCombo3();
  afx_msg void OnBnClickedCheck1();
  afx_msg void OnBnClickedCheck2();
  afx_msg void OnBnClickedCheck3();
  afx_msg void OnEnChangeEdit1();
  afx_msg void OnEnChangeEdit2();
  afx_msg void OnDeltaposSpin2(NMHDR* pNMHDR, LRESULT* pResult);
  afx_msg void OnBnClickedError();
  afx_msg HCURSOR OnQueryDragIcon();
  afx_msg HBRUSH  OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
  afx_msg BOOL    OnEraseBkgnd(CDC* pDC);
};


