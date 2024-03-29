// StringView.h : interface of the CStringView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STRINGVIEW_H__E8A76C08_7408_4871_8EF7_E6B610845081__INCLUDED_)
#define AFX_STRINGVIEW_H__E8A76C08_7408_4871_8EF7_E6B610845081__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PoemDoc.h"

class CStringView : public CScrollView
{
protected: // create from serialization only
	CStringView();
	DECLARE_DYNCREATE(CStringView)

// Attributes
public:
	CRect m_rectPrint; 

	CPoemDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStringView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CStringView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CStringView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in StringView.cpp
inline CPoemDoc* CStringView::GetDocument()
   { return (CPoemDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STRINGVIEW_H__E8A76C08_7408_4871_8EF7_E6B610845081__INCLUDED_)
