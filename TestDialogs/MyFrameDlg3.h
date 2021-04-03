#pragma once
#include "resource.h"

// MyFrameDlg3 dialog

class MyFrameDlg3 : public StyleDialog
{
	DECLARE_DYNAMIC(MyFrameDlg3)

public:
	MyFrameDlg3(CWnd* pParent = nullptr);   // standard constructor
	virtual ~MyFrameDlg3();
  virtual BOOL OnInitDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
  virtual void DoDataExchange(CDataExchange* pDX) override;

  bool CheckAllFieldsOK();
  void RegisterTooltips();

	DECLARE_MESSAGE_MAP()

  CString       m_edit1;
  CString       m_edit2;
  CString       m_edit3;

  CString       m_string4;
  CString       m_string5;
  CString       m_string6;
  CString       m_string7;

  StyleEdit     m_edit4;
  StyleEdit     m_edit5;
  StyleEdit     m_edit6;
  StyleEdit     m_edit7;

  StyleButton   m_buttonMutations;
  StyleButton   m_directoryEdit4;
  StyleButton   m_calendarEdit5;
  StyleButton   m_buttonOK;
  StyleButton   m_buttonCancel;

  bool          m_mutate { true };
public:
  afx_msg void OnEnChangeEdit1();
  afx_msg void OnEnChangeEdit2();
  afx_msg void OnEnChangeEdit3();
  afx_msg void OnEnChangeEdit4();
  afx_msg void OnEnChangeEdit5();
  afx_msg void OnEnChangeEdit6();
  afx_msg void OnEnChangeEdit7();
  afx_msg void OnBnClickedMutate();
  afx_msg void OnBnClickedDirectoryEdit4();
  afx_msg void OnBnClickedCalendarEdit5();
  afx_msg void OnBnClickedOk();
  afx_msg void OnBnClickedCancel();
};
