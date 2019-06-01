#if !defined(AFX_PROMPTDLG_H__1B093722_559F_4670_968B_B561E885C6E3__INCLUDED_)
#define AFX_PROMPTDLG_H__1B093722_559F_4670_968B_B561E885C6E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PromptDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPromptDlg dialog

class CPromptDlg : public CDialog
{
// Construction
public:
	CPromptDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPromptDlg)
	enum { IDD = IID_PROMPT };
	long	m_lValue;
	CString	m_strValue;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPromptDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPromptDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROMPTDLG_H__1B093722_559F_4670_968B_B561E885C6E3__INCLUDED_)
