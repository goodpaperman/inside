// DemoView.h : interface of the CDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEMOVIEW_H__16B4DB64_2641_4F4C_B879_16A66A0C7615__INCLUDED_)
#define AFX_DEMOVIEW_H__16B4DB64_2641_4F4C_B879_16A66A0C7615__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDemoView : public CFormView
{
protected: // create from serialization only
	CDemoView();
	DECLARE_DYNCREATE(CDemoView)

public:
	//{{AFX_DATA(CDemoView)
	enum { IDD = IDD_STUDENT };
	int		m_nGrade;
	CString	m_strName;
	//}}AFX_DATA

// Attributes
public:
	CDemoDoc* GetDocument();

// Operations
public:

private:
	//void UpdateControlsFromDoc(); 

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
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
	POSITION m_position; 
	CStudentList* m_pList; 

protected:
	virtual void ClearEntry(); 
	virtual void InsertEntry(POSITION position); 
	virtual void GetEntry(POSITION position); 

// Generated message map functions
protected:
	//{{AFX_MSG(CDemoView)
	afx_msg void OnClear();
	afx_msg void OnCommandHome();
	afx_msg void OnCommandEnd();
	afx_msg void OnCommandNext();
	afx_msg void OnCommandPrev();
	afx_msg void OnCommandIns();
	afx_msg void OnCommandDel();
	afx_msg void OnUpdateCommandHome(CCmdUI* pCmdUI);
	afx_msg void OnUpdateCommandEnd(CCmdUI* pCmdUI);
	afx_msg void OnUpdateCommandDel(CCmdUI* pCmdUI);
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

#endif // !defined(AFX_DEMOVIEW_H__16B4DB64_2641_4F4C_B879_16A66A0C7615__INCLUDED_)
