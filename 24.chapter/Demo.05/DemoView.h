// DemoView.h : interface of the CDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEMOVIEW_H__06011BC5_A6C8_48B1_8B1B_220D79305923__INCLUDED_)
#define AFX_DEMOVIEW_H__06011BC5_A6C8_48B1_8B1B_220D79305923__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BankDriver.h"
#include "AutoDriver.h"
#include "ClockDriver.h"
#include "XL5EN32.h"


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
	IBank m_bank; 
	IAuto m_auto; 
	IAlarm m_alarm; 
	IClock m_clock; 
	IApplication m_app; 
	IWorkbooks m_workbooks; 
	IWorksheets m_worksheets; 
	IWorksheet m_worksheet; 
	IRange m_range[5]; 

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
	afx_msg void OnBankLoad();
	afx_msg void OnUpdateBankLoad(CCmdUI* pCmdUI);
	afx_msg void OnUnloadBank();
	afx_msg void OnUpdateUnloadBank(CCmdUI* pCmdUI);
	afx_msg void OnTestBank();
	afx_msg void OnUpdateTestBank(CCmdUI* pCmdUI);
	afx_msg void OnLoadDll();
	afx_msg void OnUpdateLoadDll(CCmdUI* pCmdUI);
	afx_msg void OnUnloadDll();
	afx_msg void OnUpdateUnloadDll(CCmdUI* pCmdUI);
	afx_msg void OnGetDllData();
	afx_msg void OnUpdateGetDllData(CCmdUI* pCmdUI);
	afx_msg void OnLoadClock();
	afx_msg void OnUpdateLoadClock(CCmdUI* pCmdUI);
	afx_msg void OnUnloadClock();
	afx_msg void OnUpdateUnloadClock(CCmdUI* pCmdUI);
	afx_msg void OnCreateClockAlarm();
	afx_msg void OnUpdateCreateClockAlarm(CCmdUI* pCmdUI);
	afx_msg void OnRefreshClockTime();
	afx_msg void OnUpdateRefreshClockTime(CCmdUI* pCmdUI);
	afx_msg void OnLoadExcel();
	afx_msg void OnUpdateLoadExcel(CCmdUI* pCmdUI);
	afx_msg void OnExecuteExcel();
	afx_msg void OnUpdateExecuteExcel(CCmdUI* pCmdUI);
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

#endif // !defined(AFX_DEMOVIEW_H__06011BC5_A6C8_48B1_8B1B_220D79305923__INCLUDED_)
