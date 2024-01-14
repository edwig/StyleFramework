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

  DECLARE_MESSAGE_MAP()

  afx_msg void OnEnKillfocusEdit9();
  afx_msg void OnEnKillfocusEdit10();
  afx_msg void OnEnKillfocusEdit11();
  afx_msg void OnEnKillfocusEdit12();
  afx_msg void OnEnKillfocusEdit13();
  afx_msg void OnEnKillfocusEdit14();
  afx_msg void OnEnKillfocusEdit15();
  afx_msg void OnEnKillfocusEdit16();

private:
  CString   m_test9;
  CString   m_test10;
  CString   m_test11;
  CString   m_test12;
  CString   m_test13;
  CString   m_test14;
  CString   m_test15;
  CString   m_test16;
  StyleEdit m_editTest9;
  StyleEdit m_editTest10;
  StyleEdit m_editTest11;
  StyleEdit m_editTest12;
  StyleEdit m_editTest13;
  StyleEdit m_editTest14;
  StyleEdit m_editTest15;
  StyleEdit m_editTest16;
};
