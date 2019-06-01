// Ex32bView.h : interface of the CEx32bView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX32BVIEW_H__4BABB749_AAC5_4A97_9CB8_97E451D055CC__INCLUDED_)
#define AFX_EX32BVIEW_H__4BABB749_AAC5_4A97_9CB8_97E451D055CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "valform.h"

class CEx32bCntrItem;

#define WM_POSTCOMPLETE (WM_USER + 6)

class CEx32bView : public CValidForm
{
protected: // create from serialization only
	CEx32bView();
	DECLARE_DYNCREATE(CEx32bView)

public:
	//{{AFX_DATA(CEx32bView)
	enum { IDD = IDD_EX32B_FORM };
	double	m_dHours;
	int		m_nJob;
	CString	m_strName;
	int		m_nPeriod;
	//}}AFX_DATA

// Attributes
public:
	CEx32bDoc* GetDocument();
	// m_pSelection holds the selection to the current CEx32bCntrItem.
	// For many applications, such a member variable isn't adequate to
	//  represent a selection, such as a multiple selection or a selection
	//  of objects that are not CEx32bCntrItem objects.  This selection
	//  mechanism is provided just to help you get started.

	// TODO: replace this selection mechanism with one appropriate to your app.
	CEx32bCntrItem* m_pSelection;
    virtual void ValidateDlgItem(CDataExchange* pDX, UINT nID); 

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx32bView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL IsSelected(const CObject* pDocItem) const;// Container support
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx32bView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx32bView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	afx_msg void OnDestroy();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnInsertObject();
	afx_msg void OnCancelEditCntr();
	afx_msg void OnCancelEditSrvr();
	//}}AFX_MSG
    afx_msg void OnSubmit(); 
    afx_msg void OnCancel(); 
    afx_msg LONG OnPostComplete(UINT wParam, LONG lParam); 
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex32bView.cpp
inline CEx32bDoc* CEx32bView::GetDocument()
   { return (CEx32bDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX32BVIEW_H__4BABB749_AAC5_4A97_9CB8_97E451D055CC__INCLUDED_)
