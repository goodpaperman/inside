// DemoView.h : interface of the CDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEMOVIEW_H__4B83746C_EB8D_4C81_AB13_D0E18A54E2CE__INCLUDED_)
#define AFX_DEMOVIEW_H__4B83746C_EB8D_4C81_AB13_D0E18A54E2CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "rowview.h"


class CDemoView : public CRowView
{
protected: // create from serialization only
	CDemoView();
	DECLARE_DYNCREATE(CDemoView)

// Attributes
public:
	CDemoDoc* GetDocument();

// Operations
public:
    int m_nSelectRow; 
    CDaoRecordset* m_pSet; 
    int m_nCharWidth; 

	virtual void GetRowWidthHeight(CDC* pDC, int& nRowWidth,
		int& nRowHeight);
	virtual int GetActiveRow();
	virtual int GetRowCount();
	virtual void OnDrawRow(CDC* pDC, int nRow, int y, BOOL bSelected);
	virtual void ChangeSelectionNextRow(BOOL bNext);
	virtual void ChangeSelectionToRow(int nRow);
    void DrawDataRow(CDC* pDC, int y); 

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDemoView)
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DemoView.cpp
inline CDemoDoc* CDemoView::GetDocument()
   { return (CDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMOVIEW_H__4B83746C_EB8D_4C81_AB13_D0E18A54E2CE__INCLUDED_)
