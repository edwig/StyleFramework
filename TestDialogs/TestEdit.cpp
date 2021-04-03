#include "stdafx.h"
#include "TestEdit.h"


BEGIN_MESSAGE_MAP(TestEdit, CEdit)
  ON_WM_SIZE()
  ON_WM_MOVE()
END_MESSAGE_MAP()

void 
TestEdit::OnSize(UINT nType, int cx, int cy)
{
  CEdit::OnSize(nType, cx, cy);
  TRACE("CEdit OnSize_%d %d,%d,%d\n",GetDlgCtrlID(),nType,cx,cy);
}

void
TestEdit::OnMove(int x, int y)
{
  CEdit::OnMove(x, y);
  TRACE("CEdit OnMove_%d %d,%d\n", GetDlgCtrlID(),x, y);
}