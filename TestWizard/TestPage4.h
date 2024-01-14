#pragma once

// TestPage4 dialog

class TestPage4 : public StyleTab
{
	DECLARE_DYNAMIC(TestPage4)

public:
	TestPage4(CWnd* p_parent = nullptr);
	virtual ~TestPage4();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTPAGE4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX) override;
	virtual BOOL OnInitDialog() override;

	DECLARE_MESSAGE_MAP()

	afx_msg void OnEnKillfocusEdit25();
	afx_msg void OnEnKillfocusEdit26();
	afx_msg void OnEnKillfocusEdit27();
	afx_msg void OnEnKillfocusEdit28();
	afx_msg void OnEnKillfocusEdit29();
	afx_msg void OnEnKillfocusEdit30();
	afx_msg void OnEnKillfocusEdit31();
	afx_msg void OnEnKillfocusEdit32();

private:
	CString   m_test25;
	CString   m_test26;
	CString   m_test27;
	CString   m_test28;
	CString   m_test29;
	CString   m_test30;
	CString   m_test31;
	CString   m_test32;
	StyleEdit m_editTest25;
	StyleEdit m_editTest26;
	StyleEdit m_editTest27;
	StyleEdit m_editTest28;
	StyleEdit m_editTest29;
	StyleEdit m_editTest30;
	StyleEdit m_editTest31;
	StyleEdit m_editTest32;
};
