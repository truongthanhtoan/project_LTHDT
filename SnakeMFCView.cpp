
// SnakeMFCView.cpp : implementation of the CSnakeMFCView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SnakeMFC.h"
#endif

#include "SnakeMFCDoc.h"
#include "SnakeMFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSnakeMFCView

IMPLEMENT_DYNCREATE(CSnakeMFCView, CView)

BEGIN_MESSAGE_MAP(CSnakeMFCView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
//	ON_WM_KEYDOWN()
ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CSnakeMFCView construction/destruction

CSnakeMFCView::CSnakeMFCView() noexcept
{
	// TODO: add construction code here
	giaodien = Giaodien();
}

CSnakeMFCView::~CSnakeMFCView()
{
}

BOOL CSnakeMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSnakeMFCView drawing

void CSnakeMFCView::OnDraw(CDC* /*pDC*/)
{
	CSnakeMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CClientDC pdc(this);
	giaodien.drawHinh(&pdc);
}

void CSnakeMFCView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSnakeMFCView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSnakeMFCView diagnostics

#ifdef _DEBUG
void CSnakeMFCView::AssertValid() const
{
	CView::AssertValid();
}

void CSnakeMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSnakeMFCDoc* CSnakeMFCView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSnakeMFCDoc)));
	return (CSnakeMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CSnakeMFCView message handlers
void CSnakeMFCView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	if (giaodien.control == 0 && nChar == 32)
	{
		gameStart();
	}
	if (giaodien.control == 1 && nChar >=37 && nChar <=40)
	{
		giaodien.direction = nChar;
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

UINT moveSnake(LPVOID nparam)
{
	CSnakeMFCView* cview = (CSnakeMFCView*)nparam;
	cview->giaodien.moveSnake();
	return 0;
}

UINT showMove(LPVOID nparam)
{
	CSnakeMFCView* cview = (CSnakeMFCView*)nparam;
	CClientDC pdc(cview);
	cview->giaodien.showMove(&pdc);
	return 0;
}

int CSnakeMFCView::gameStart()
{
	// TODO: Add your implementation code here.
	giaodien.startG();
	AfxBeginThread(moveSnake, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);
	AfxBeginThread(showMove, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);
	return 0;
}
