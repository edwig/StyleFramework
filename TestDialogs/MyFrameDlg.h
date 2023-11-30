// MyFrameDlg.h : Interface file
//
#pragma once
#include "StyleDialog.h"
#include "StyleButton.h"
#include "StyleEdit.h"
#include "resource.h"

class MyFrameDlg :public StyleDialog
{
public:
  MyFrameDlg(CWnd* p_parent = nullptr);
 ~MyFrameDlg();

 enum { IDD = IDD_TESTS };

 virtual BOOL OnInitDialog() override;
 virtual void OnDroppedFile(UINT p_id,UINT p_index,LPCTSTR p_fileName);

protected:
  virtual void DoDataExchange(CDataExchange* pDX) override;


  DECLARE_MESSAGE_MAP()

private:
  CString     m_text;
  StyleEdit   m_editText;
  StyleButton m_buttonTest1;
  StyleButton m_buttonTest2;
  StyleButton m_buttonTest3;
  StyleButton m_buttonTest4;
  StyleButton m_buttonTest5;
  StyleButton m_buttonTest6;
  StyleButton m_buttonTest7;
  StyleButton m_buttonGrid;
  StyleButton m_buttonTabs;
  StyleButton m_buttonOK;
  StyleButton m_buttonCancel;

  StyleStatic m_staticElement;
  StyleStatic m_staticCombo;
  StyleStatic m_staticEdit;
  StyleStatic m_staticMulti;
  StyleStatic m_staticList;
  StyleStatic m_staticTree;
  StyleStatic m_staticProgress;
  StyleStatic m_staticGrid;
  StyleStatic m_staticTab;

public:
  afx_msg void OnEnChangeText();
  afx_msg void OnBnClickedTest1();
  afx_msg void OnBnClickedTest2();
  afx_msg void OnBnClickedTest3();
  afx_msg void OnBnClickedTest4();
  afx_msg void OnBnClickedTest5();
  afx_msg void OnBnClickedTest6();
  afx_msg void OnBnClickedTest7();
  afx_msg void OnBnClickedGrid();
  afx_msg void OnBnClickedTabs();
  afx_msg void OnBnClickedOk();
  afx_msg void OnBnClickedCancel();
};
