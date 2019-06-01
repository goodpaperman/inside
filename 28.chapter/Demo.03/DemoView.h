// DemoView.h : interface of the CDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEMOVIEW_H__17C9E150_6945_4833_B806_907171C917B8__INCLUDED_)
#define AFX_DEMOVIEW_H__17C9E150_6945_4833_B806_907171C917B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDemoSet;

class CDemoView : public CRecordView
{
protected: // create from serialization only
	CDemoView();
	DECLARE_DYNCREATE(CDemoView)

public:
	//{{AFX_DATA(CDemoView)
	enum { IDD = IDD_DEMO_FORM };
	CDemoSet* m_pSet;
	//}}AFX_DATA

// Attributes
public:
	CDemoDoc* GetDocument();
    void LoadListbox(); 

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoView)
	public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnMove(UINT nIDMoveCommand);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
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
	afx_msg void OnRecordAdd();
	afx_msg void OnRecordClearfields();
	afx_msg void OnRecordDelete();
	afx_msg void OnUpdateRecordDelete(CCmdUI* pCmdUI);
	afx_msg void OnRecordUpdate();
	afx_msg void OnUpdateRecordUpdate(CCmdUI* pCmdUI);
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

#endif // !defined(AFX_DEMOVIEW_H__17C9E150_6945_4833_B806_907171C917B8__INCLUDED_)
