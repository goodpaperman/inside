// DemoView.h : interface of the CDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEMOVIEW_H__FB003664_DD04_4C4B_9BDC_4900D5F2567D__INCLUDED_)
#define AFX_DEMOVIEW_H__FB003664_DD04_4C4B_9BDC_4900D5F2567D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDemoView : public CEditView
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
	protected:
 virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
 virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
 virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
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
 afx_msg void OnInternetStartServer();
 afx_msg void OnUpdateInternetStartServer(CCmdUI* pCmdUI);
 afx_msg void OnInternetRequestSocket();
 afx_msg void OnInternetRequestWininet();
 afx_msg void OnInternetStopServer();
 afx_msg void OnUpdateInternetStopServer(CCmdUI* pCmdUI);
 afx_msg void OnInternetConfiguration();
 afx_msg void OnUpdateInternetConfiguration(CCmdUI* pCmdUI);
 afx_msg void OnEditClearAll();
 afx_msg void OnRequest();
 afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
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

#endif // !defined(AFX_DEMOVIEW_H__FB003664_DD04_4C4B_9BDC_4900D5F2567D__INCLUDED_)
