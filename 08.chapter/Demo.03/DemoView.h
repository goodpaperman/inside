// DemoView.h : interface of the CDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEMOVIEW_H__E43F68D8_6051_4313_970A_BC48F217660B__INCLUDED_)
#define AFX_DEMOVIEW_H__E43F68D8_6051_4313_970A_BC48F217660B__INCLUDED_

#include "webbrowser.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDemoView : public CView
{
protected: // create from serialization only
	CDemoView();
	DECLARE_DYNCREATE(CDemoView)

// Attributes
public:
	CDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
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
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
		
	afx_msg void OnBeforeNavigateExplorer1(LPCTSTR URL, 
		long Flags, LPCTSTR TargetFrameName, 
		VARIANT FAR* PostData, LPCTSTR Headers, BOOL FAR* Cancel); 
	afx_msg void OnTitleChangeExplorer2(LPCTSTR Text); 
	DECLARE_EVENTSINK_MAP() 

private:
	CWebBrowser m_target;
	CWebBrowser m_search;
	static const char s_engineAltavista[]; 
};

#ifndef _DEBUG  // debug version in DemoView.cpp
inline CDemoDoc* CDemoView::GetDocument()
   { return (CDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMOVIEW_H__E43F68D8_6051_4313_970A_BC48F217660B__INCLUDED_)
