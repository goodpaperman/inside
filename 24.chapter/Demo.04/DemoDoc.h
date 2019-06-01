// DemoDoc.h : interface of the CDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEMODOC_H__933F3CA9_DC17_4EF1_BFA8_4B7C6C17AFBA__INCLUDED_)
#define AFX_DEMODOC_H__933F3CA9_DC17_4EF1_BFA8_4B7C6C17AFBA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Alarm.h"

class CDemoDoc : public CDocument
{
protected: // create from serialization only
	CDemoDoc();
	DECLARE_DYNCREATE(CDemoDoc)

// Attributes
public:
	CString m_strFigure[4]; 

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

public:
	CAlarm* m_pAlarm; 

// Generated message map functions
protected:
	//{{AFX_MSG(CDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CDemoDoc)
	public:
	DATE m_vaTime;
	protected:
	afx_msg void OnTimeChanged();
	afx_msg void RefreshWin();
	afx_msg void ShowWin();
	afx_msg LPDISPATCH CreateAlarm(DATE time);
	afx_msg VARIANT GetFigure(short n);
	afx_msg void SetFigure(short n, const VARIANT FAR& newValue);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMODOC_H__933F3CA9_DC17_4EF1_BFA8_4B7C6C17AFBA__INCLUDED_)
