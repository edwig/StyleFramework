#pragma once
// TestPage1 dialog

class TestPage2 : public StyleTab
{
  DECLARE_DYNAMIC(TestPage2)

public:
  TestPage2(CWnd* p_parent = nullptr);
  virtual ~TestPage2();

  // Dialog Data
#ifdef AFX_DESIGN_TIME
  enum { IDD = IDD_TESTPAGE2 };
#endif

protected:
  virtual void DoDataExchange(CDataExchange* pDX) override;
  virtual BOOL OnInitDialog() override;

  void SetRTF();

  DECLARE_MESSAGE_MAP()

  afx_msg void OnEnKillfocusEdit9();
  afx_msg void OnEnKillfocusEdit10();
  afx_msg void OnEnKillfocusEdit11();
  afx_msg void OnEnKillfocusEdit12();
  afx_msg void OnEnKillfocusEdit13();

private:
  CString   m_test9;
  CString   m_test10;
  CString   m_test11;
  CString   m_test12;
  CString   m_test13;
  StyleEdit m_editTest9;
  StyleEdit m_editTest10;
  StyleEdit m_editTest11;
  StyleEdit m_editTest12;
  StyleRichEdit m_editTest13;
};
