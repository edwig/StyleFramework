
// TestFrameView.cpp : implementation of the CTestFrameView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TestFrame.h"
#endif

#include "TestFrameDoc.h"
#include "TestFrameView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestFrameView

IMPLEMENT_DYNCREATE(CTestFrameView, CView)

BEGIN_MESSAGE_MAP(CTestFrameView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT,        &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW,&CTestFrameView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CTestFrameView construction/destruction

CTestFrameView::CTestFrameView()
{
	// TODO: add construction code here

}

CTestFrameView::~CTestFrameView()
{
}

BOOL CTestFrameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTestFrameView drawing

void CTestFrameView::OnDraw(CDC* /*pDC*/)
{
	CTestFrameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CTestFrameView printing


void CTestFrameView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTestFrameView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestFrameView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestFrameView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CTestFrameView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTestFrameView::OnContextMenu(CWnd* /* pWnd */, CPoint /*point*/)
{
#ifndef SHARED_HANDLERS
//	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTestFrameView diagnostics

#ifdef _DEBUG
void CTestFrameView::AssertValid() const
{
	CView::AssertValid();
}

void CTestFrameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestFrameDoc* CTestFrameView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestFrameDoc)));
	return (CTestFrameDoc*)m_pDocument;
}
#endif //_DEBUG


// CTestFrameView message handlers
