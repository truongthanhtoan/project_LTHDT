
// SnakeMFCView.h : interface of the CSnakeMFCView class
//

#pragma once
#include "Giaodien.h"


class CSnakeMFCView : public CView
{
protected: // create from serialization only
	CSnakeMFCView() noexcept;
	DECLARE_DYNCREATE(CSnakeMFCView)

// Attributes
public:
	CSnakeMFCDoc* GetDocument() const;

// Operations
public:
	Giaodien giaodien;
// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CSnakeMFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	int gameStart();
};

#ifndef _DEBUG  // debug version in SnakeMFCView.cpp
inline CSnakeMFCDoc* CSnakeMFCView::GetDocument() const
   { return reinterpret_cast<CSnakeMFCDoc*>(m_pDocument); }
#endif

