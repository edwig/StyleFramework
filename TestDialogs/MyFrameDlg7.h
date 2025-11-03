#pragma once

// MyFrameDlg7 dialog

class MyFrameDlg7 : public StyleDialog
{
	DECLARE_DYNAMIC(MyFrameDlg7)

public:
	MyFrameDlg7(CWnd* pParent = nullptr);   // standard constructor
	virtual ~MyFrameDlg7();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG7 };
#endif

protected:
  virtual void DoDataExchange(CDataExchange* pDX) override;
  virtual BOOL OnInitDialog() override;

	DECLARE_MESSAGE_MAP()

  int               m_total;
  int               m_interval;
  StyleEdit         m_editTotal;
  StyleEdit         m_editInterval;
  StyleProgressCtrl m_progress1;
  StyleProgressCtrl m_progress2;
  StyleStatic       m_staticTotal;
  StyleStatic       m_staticIntval;
  StyleButton       m_buttonReset;
  StyleButton       m_buttonStartMarquee;
  StyleButton       m_buttonStopMarquee;
  StyleButton       m_buttonStart;
  StyleButton       m_buttonPause;
  StyleButton       m_buttonError;
  StyleButton       m_buttonOK;
  StyleButton       m_buttonCancel;
public:
  afx_msg void OnTimer(UINT_PTR nID);
  afx_msg void OnEnChangeTotal();
  afx_msg void OnEnChangeInterval();
  afx_msg void OnBnClickedReset();
  afx_msg void OnBnClickedStartMarquee();
  afx_msg void OnBnClickedStopMarquee();
  afx_msg void OnBnClickedStart();
  afx_msg void OnBnClickedPause();
  afx_msg void OnBnClickedError();
  afx_msg void OnBnClickedOk();
  afx_msg void OnBnClickedCancel();
};
