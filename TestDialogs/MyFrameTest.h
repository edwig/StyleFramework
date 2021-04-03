#pragma once


// MyFrameTest dialog

class MyFrameTest : public CDialogEx
{
	DECLARE_DYNAMIC(MyFrameTest)

public:
	MyFrameTest(CWnd* pParent = nullptr);   // standard constructor
	virtual ~MyFrameTest();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
