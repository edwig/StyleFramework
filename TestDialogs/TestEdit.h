#pragma once
#include <afxwin.h>

class TestEdit :   public CEdit
{
public:
  afx_msg void OnSize(UINT nType, int cx, int cy);
  afx_msg void OnMove(int x, int y);


  DECLARE_MESSAGE_MAP()
};

