// Ex32aView.h : interface of the CEx32aView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX32AVIEW_H__693A187E_396E_46A7_9014_5FA7554096EB__INCLUDED_)
#define AFX_EX32AVIEW_H__693A187E_396E_46A7_9014_5FA7554096EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CEx32aCntrItem;

class CEx32aView : public CRichEditView
{
protected: // create from serialization only
	CEx32aView();
	DECLARE_DYNCREATE(CEx32aView)

// Attributes
public:
	CEx32aDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx32aView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx32aView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx32aView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	afx_msg void OnDestroy();
	afx_msg void OnCancelEditSrvr();
	//}}AFX_MSG
    afx_msg void OnStart(); 
    afx_msg void OnStop(); 
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex32aView.cpp
inline CEx32aDoc* CEx32aView::GetDocument()
   { return (CEx32aDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX32AVIEW_H__693A187E_396E_46A7_9014_5FA7554096EB__INCLUDED_)
