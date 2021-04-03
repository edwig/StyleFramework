// MyGridDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyGridDlg.h"
#include "MyFrame.h"
#include "afxdialogex.h"
#include "Resource.h"
#include "StyleColors.h"


// MyGridDlg dialog

IMPLEMENT_DYNAMIC(MyGridDlg, StyleDialog)

MyGridDlg::MyGridDlg(CWnd* pParent /*=nullptr*/)
	        :StyleDialog(IDD_GRIDDIALOG, pParent,true,true)
{
  m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

MyGridDlg::~MyGridDlg()
{
}

void MyGridDlg::DoDataExchange(CDataExchange* pDX)
{
	StyleDialog::DoDataExchange(pDX);

  DDX_Control(pDX,IDC_TEXT,m_text,m_string);
  DDX_Control(pDX,IDC_GRID,m_grid);
  DDX_Control(pDX,IDOK,    m_buttonOK);
  DDX_Control(pDX,IDCANCEL,m_buttonCancel);
}

BEGIN_MESSAGE_MAP(MyGridDlg, StyleDialog)
  ON_NOTIFY(GVN_SELCHANGED,  IDC_GRID,OnSelChangedGrid)
  ON_NOTIFY(GVN_ENDLABELEDIT,IDC_GRID,OnGridEndEdit)

  ON_COMMAND     (ID_THEMA_LIME,      OnStyleLime)
  ON_COMMAND     (ID_THEMA_SKYBLUE,   OnStyleSkyblue)
  ON_COMMAND     (ID_THEMA_PURPLE,    OnStylePurple)
  ON_COMMAND     (ID_THEMA_MODERATE,  OnStyleModerateGray)
  ON_COMMAND     (ID_THEMA_PUREGRAY,  OnStylePureGray)
  ON_COMMAND     (ID_THEMA_BLACKWHITE,OnStyleBlackWhite)

END_MESSAGE_MAP()

// MyGridDlg message handlers

BOOL
MyGridDlg::OnInitDialog()
{
  StyleDialog::OnInitDialog();
  SetWindowText("My Grid testing dialog");
  SetSysMenu(IDR_MENU4);

  m_buttonOK.SetStyle("ok");
  m_buttonCancel.SetStyle("can");

  FillGrid();

  SetCanResize();
  ShowMinMaxButton();

  return TRUE;
}

// Triggered by SetCanResize
void
MyGridDlg::SetupDynamicLayout()
{
  // See to it that we get a manager;
  StyleDialog::SetupDynamicLayout();

  CMFCDynamicLayout& manager = *GetDynamicLayout();
#ifdef _DEBUG
  manager.AssertValid();
#endif

  HWND grid = m_grid.GetSkin()->GetSafeHwnd();
  HWND text = m_text.GetSkin()->GetSafeHwnd();
    
  manager.AddItem(grid,           manager.MoveNone(),                          manager.SizeHorizontalAndVertical(100,100));
  manager.AddItem(text,           manager.MoveVertical(100),                   manager.SizeHorizontal(100));
  manager.AddItem(m_buttonOK,     manager.MoveHorizontalAndVertical(100, 100), manager.SizeNone());
  manager.AddItem(m_buttonCancel, manager.MoveHorizontalAndVertical(100, 100), manager.SizeNone());
}

void
MyGridDlg::FillGrid()
{
  m_grid.SetColumnCount(5);
  m_grid.SetRowCount(1);
  m_grid.SetFixedRowCount(1);
  m_grid.GetCell(0, 0)->SetText("Index");
  m_grid.GetCell(0, 1)->SetText("Variable");
  m_grid.GetCell(0, 2)->SetText("Value");
  m_grid.GetCell(0, 3)->SetText("ComboBox");
  m_grid.GetCell(0, 4)->SetText("CheckBox");
  m_grid.SetColumnWidth(0, 80);
  m_grid.SetColumnWidth(1, 280);
  m_grid.SetColumnWidth(2, 280);
  m_grid.SetColumnWidth(3, 140);
  m_grid.SetColumnWidth(4, 80);
  m_grid.SetEditable();
  m_grid.SetSingleColSelection(TRUE);
  m_grid.SetSingleRowSelection(TRUE);

  // Add to the list
  int firstRow = 0;

  for(int index = 0; index < 50; ++index)
  {
    CString col1;
    CString col2;
    CString col3;
    col1.Format("%02d", index + 1);
    col2.Format("Var_%02d", 50 - index);
    col3.Format("VALUE_%03d_LONGER", 3 * index);

    int row = m_grid.InsertRow(col1);
    m_grid.GetCell(row, 1)->SetText(col2);
    m_grid.GetCell(row, 2)->SetText(col3);
    m_grid.SetCellType(row, 3,RUNTIME_CLASS(CGridCellCombo));
    m_grid.SetCellType(row, 4,RUNTIME_CLASS(CGridCellCheck));

    CGridCellCombo* combo = reinterpret_cast<CGridCellCombo*>(m_grid.GetCell(row, 3));
    SetComboList(combo);

    if (!firstRow)
    {
      firstRow = row;
    }
  }

  if (firstRow)
  {
    m_grid.SetFocusCell(1, 0);
  }
  m_grid.SetSortColumn(0);
  m_grid.SetSortAscending(TRUE);
  m_grid.SetHeaderSort();

  m_grid.SetFocus();
}

void
MyGridDlg::SetComboList(CGridCellCombo* p_combo)
{
  CStringArray list;
  list.Add("First choice");
  list.Add("Second 2");
  list.Add("3 = Third");
  list.Add("Four = 4");
  list.Add("Firth of Fifth");

  for (int i = 0; i < 30; ++i)
  {
    list.Add("Another one");
  }

  p_combo->SetOptions(list);
  p_combo->SetStyle(CBS_DROPDOWNLIST | CBS_SORT);
  // p_combo->SetStyle(CBS_DROPDOWN);
}

void 
MyGridDlg::AddToText(CString p_text)
{
  CString total = m_text.GetWindowString();
  total += p_text;
  m_text.SetWindowText(total);
}

void 
MyGridDlg::OnSelChangedGrid(NMHDR* p_nmhdr,LRESULT* p_result)
{
  NM_GRIDVIEW* pItem = (NM_GRIDVIEW*)p_nmhdr;
  CString debug;
  debug.Format("End Selection Change on row %d, col %d (%d Selected)\r\n",
               pItem->iRow
              ,pItem->iColumn
              ,m_grid.GetSelectedCount());
  AddToText(debug);
  *p_result = 0;
}

void 
MyGridDlg::OnGridEndEdit(NMHDR* p_nmhdr, LRESULT* p_result)
{
  NM_GRIDVIEW* pItem = (NM_GRIDVIEW*)p_nmhdr;
  CString debug;
  debug.Format("End Edit on row %d, col %d\r\n",pItem->iRow,pItem->iColumn);
  AddToText(debug);
  *p_result = 0;
}
