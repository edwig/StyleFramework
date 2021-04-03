#pragma once
#include "resource.h"
#include "TestEdit.h"

// MyFrameDlg4 dialog

class MyFrameDlg4 : public StyleDialog
{
	DECLARE_DYNAMIC(MyFrameDlg4)

public:
	MyFrameDlg4(CWnd* pParent = nullptr);   // standard constructor
	virtual ~MyFrameDlg4();
  virtual BOOL OnInitDialog();

// Dialog Data
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
  virtual void SetupDynamicLayout() override;

  void SetStatusPanes();

	DECLARE_MESSAGE_MAP()

  CMenu         m_menu;
  StyleEdit     m_edit1;
  StyleEdit     m_edit2;
  StyleEdit     m_edit3;
  StyleEdit     m_edit4;
  CString       m_info1;
  CString       m_info2;
  CString       m_info3;
  CString       m_info4;
  StyleButton   m_buttonError;
  StyleButton   m_buttonOK;
  StyleButton   m_buttonCancel;
  
  bool          m_testResize;
public:
  afx_msg void OnEnChangeEdit1();
  afx_msg void OnEnChangeEdit2();
  afx_msg void OnEnChangeEdit3();
  afx_msg void OnEnChangeEdit4();
  afx_msg void OnBnClickedError();
  afx_msg void OnBnClickedOk();
};
