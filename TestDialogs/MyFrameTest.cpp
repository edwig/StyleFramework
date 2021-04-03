// MyFrameTest.cpp : implementation file
//

#include "pch.h"
#include "MyFrameTest.h"
#include "afxdialogex.h"


// MyFrameTest dialog

IMPLEMENT_DYNAMIC(MyFrameTest, CDialogEx)

MyFrameTest::MyFrameTest(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TESTS, pParent)
{

}

MyFrameTest::~MyFrameTest()
{
}

void MyFrameTest::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyFrameTest, CDialogEx)
END_MESSAGE_MAP()


// MyFrameTest message handlers
