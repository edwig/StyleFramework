#pragma once
#include "Resource.h"

// MyFrameDlg5 dialog

class MyFrameDlg6 : public StyleDialog
{
	DECLARE_DYNAMIC(MyFrameDlg6)

public:
	MyFrameDlg6(CWnd* pParent = nullptr);   // standard constructor
	virtual ~MyFrameDlg6();
  virtual BOOL OnInitDialog()       override;
  virtual void SetupDynamicLayout() override;

// Dialog Data
	enum { IDD = IDD_DIALOG6 };

protected:
  virtual void DoDataExchange(CDataExchange* pDX) override;

	DECLARE_MESSAGE_MAP()

  CString       m_string;
  StyleEdit     m_edit;
  StyleTreeCtrl m_list1;
  StyleTreeCtrl m_list2;
  StyleButton   m_buttonAdd;
  StyleButton   m_buttonLegen;
  StyleButton   m_buttonOK;
  StyleButton   m_buttonCancel;
  
public:
  afx_msg void OnEnChangeEdit();
  afx_msg void OnBnClickedAdd();
  afx_msg void OnLbnSelchangeList1();
  afx_msg void OnLbnSelchangeList2();
  afx_msg void OnBnClickedOk();
  afx_msg void OnBnClickedCancel();
  afx_msg void OnBnClickedLegen();
};
