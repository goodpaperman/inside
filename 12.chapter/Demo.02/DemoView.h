// DemoView.h : interface of the CDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEMOVIEW_H__7D6E5C81_8459_46E5_9823_4B1208FB5E1A__INCLUDED_)
#define AFX_DEMOVIEW_H__7D6E5C81_8459_46E5_9823_4B1208FB5E1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Property.h"


class CDemoView : public CView
{
protected: // create from serialization only
	CDemoView();
	DECLARE_DYNCREATE(CDemoView)

// Attributes
public:
	CRichEditCtrl m_rich; 
	CDemoDoc* GetDocument();

private:
	void Format(CHARFORMAT& cf); 

	CFontSheet m_sh; 
	BOOL m_bDefault; 

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
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
	afx_msg void OnTransferGetdata();
	afx_msg void OnTransferStoredata();
	afx_msg void OnUpdateTransferStoredata(CCmdUI* pCmdUI);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnFormatDefault();
	afx_msg void OnFormatSelection();
	afx_msg void OnUpdateFormatSelection(CCmdUI* pCmdUI);
	//}}AFX_MSG
	afx_msg LRESULT OnUserApply(WPARAM wParam, LPARAM lParam); 
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DemoView.cpp
inline CDemoDoc* CDemoView::GetDocument()
   { return (CDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMOVIEW_H__7D6E5C81_8459_46E5_9823_4B1208FB5E1A__INCLUDED_)
