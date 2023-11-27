#pragma once
#include "GridCellCombo.h"
#include "GridCellCheck.h"

// MyGridDlg dialog

class MyGridDlg : public StyleDialog
{
	DECLARE_DYNAMIC(MyGridDlg)

public:
	MyGridDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~MyGridDlg();

  virtual void DoDataExchange(CDataExchange* pDX) override;
  virtual void SetupDynamicLayout() override;
  virtual BOOL OnInitDialog() override;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GRIDDIALOG };
#endif

protected:
  void AddToText(CString p_text);
  void SetComboList(CGridCellCombo* p_combo,bool p_rigid);

	DECLARE_MESSAGE_MAP()

  afx_msg void OnSelChangedGrid(NMHDR*, LRESULT*);
  afx_msg void OnGridEndEdit(NMHDR*, LRESULT*);

  void FillGrid();

  HICON         m_hIcon;
  StyleButton   m_buttonOK;
  StyleButton   m_buttonCancel;
  StyleGridCtrl m_grid;
  StyleEdit     m_text;
  CString       m_string;
};
