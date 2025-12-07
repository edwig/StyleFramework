#pragma once

// TestPage1 dialog

class TestPage1 : public StyleTab
{
	DECLARE_DYNAMIC(TestPage1)

public:
	TestPage1(CWnd* p_parent = nullptr);
	virtual ~TestPage1();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTPAGE1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX) override;
	virtual BOOL OnInitDialog() override;

	DECLARE_MESSAGE_MAP()

	afx_msg void OnEnKillfocusEdit1();
	afx_msg void OnEnKillfocusEdit2();
	afx_msg void OnEnKillfocusEdit3();
	afx_msg void OnEnKillfocusEdit4();
	afx_msg void OnEnKillfocusEdit5();

private:
	CString   m_test1;
	CString   m_test2;
	CString   m_test3;
	CString   m_test4;
	CString   m_test5;
	StyleEdit m_editTest1;
	StyleEdit m_editTest2;
	StyleEdit m_editTest3;
	StyleEdit m_editTest4;
	StyleEdit m_editTest5;
};
