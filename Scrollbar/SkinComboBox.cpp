// SkinComboBox.cpp : 实现文件
//

#include "stdafx.h"
#include "SkinComboBox.h"
#include "skinscrollwnd.h"

// CSkinComboBox

IMPLEMENT_DYNAMIC(CSkinComboBox, CComboBox)

CSkinComboBox::CSkinComboBox()
{
	m_hWndList=NULL;
}

CSkinComboBox::~CSkinComboBox()
{
}


BEGIN_MESSAGE_MAP(CSkinComboBox, CComboBox)
	ON_CONTROL_REFLECT(CBN_CLOSEUP, OnCbnCloseup)
	ON_CONTROL_REFLECT(CBN_DROPDOWN, OnCbnDropdown)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()

// CSkinComboBox

void CSkinComboBox::OnCbnCloseup()
{
  // TODO: Add control notification handler code here
	if(!m_hWndList) return ;
	::ShowWindow(::GetParent(::GetParent(m_hWndList)),SW_HIDE);
}

void CSkinComboBox::OnCbnDropdown()
{
  // TODO: Add control notification handler code here
	if(!m_hWndList) return ;
	CWnd *pFrame=CWnd::FromHandle(::GetParent(::GetParent(m_hWndList)));
	CRect rc;
	GetWindowRect(&rc);
	CRect rc2;
	this->GetDroppedControlRect(&rc2);
	int nHei;
	int nLineHei=GetItemHeight(0);
	if(nLineHei*GetCount()<rc2.Height()-2)
		nHei=nLineHei*GetCount()+2;
	else
		nHei=rc2.Height();
	pFrame->SetWindowPos(&wndTopMost,rc.left,rc.bottom,rc2.Width(),nHei,0);
	pFrame->ShowWindow(SW_SHOW);
}

HBRUSH CSkinComboBox::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CComboBox::OnCtlColor(pDC, pWnd, nCtlColor);
	if (nCtlColor == CTLCOLOR_LISTBOX && !m_hWndList && m_hBmpScroll)
	{
		// The pop-up list pops up for the first time, first hiding the list
		pWnd->ShowWindow(SW_HIDE);
		SkinWndScroll(pWnd,m_hBmpScroll);
		m_hWndList=pWnd->m_hWnd;
	}
	return hbr;
}
