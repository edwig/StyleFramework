// MySettingsDlg.h : header file
//

#pragma once
#include "GrayWindow.h"
#include "resource.h"

// CMyFrameDlg dialog
class MySettingsDlg : public StyleDialog
{
  // Construction
public:
  MySettingsDlg(CWnd* pParent = NULL);	// standard constructor

  enum { IDD = IDD_MYSETTINGS_DIALOG };

  bool ShowgrayScreen() { return m_grayWindow.Show(); };
  void HidegrayScreen() { m_grayWindow.Hide(); };

protected:
  virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

                                                    // Implementation
protected:
  StyleButton     m_buttonOK;
  StyleButton     m_buttonCancel;

  GrayWindow      m_grayWindow;
  StyleTabCtrl    m_tab;

  // Generated message map functions
  virtual BOOL    OnInitDialog();
  afx_msg void    OnDestroy();
  afx_msg void    OnSysCommand(UINT nID, LPARAM lParam);

  DECLARE_MESSAGE_MAP()
};

