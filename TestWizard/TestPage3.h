#pragma once

// TestPage3 dialog

class TestPage3 : public StyleTab
{
	DECLARE_DYNAMIC(TestPage3)

public:
	TestPage3(CWnd* p_parent = nullptr);
	virtual ~TestPage3();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTPAGE3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX) override;
	virtual BOOL OnInitDialog() override;

	DECLARE_MESSAGE_MAP()

	afx_msg void OnEnKillfocusEdit17();
	afx_msg void OnEnKillfocusEdit18();
	afx_msg void OnEnKillfocusEdit19();
	afx_msg void OnEnKillfocusEdit20();
	afx_msg void OnEnKillfocusEdit21();
	afx_msg void OnEnKillfocusEdit22();
	afx_msg void OnEnKillfocusEdit23();
	afx_msg void OnEnKillfocusEdit24();

private:
	CString   m_test17;
	CString   m_test18;
	CString   m_test19;
	CString   m_test20;
	CString   m_test21;
	CString   m_test22;
	CString   m_test23;
	CString   m_test24;
	StyleEdit m_editTest17;
	StyleEdit m_editTest18;
	StyleEdit m_editTest19;
	StyleEdit m_editTest20;
	StyleEdit m_editTest21;
	StyleEdit m_editTest22;
	StyleEdit m_editTest23;
	StyleEdit m_editTest24;
};
