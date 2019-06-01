#if !defined(AFX_TEXTDIALOG_H__8016228D_63E6_44D3_9237_76EA4C69A9CE__INCLUDED_)
#define AFX_TEXTDIALOG_H__8016228D_63E6_44D3_9237_76EA4C69A9CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TextDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTextDialog dialog

class CTextDialog : public CDialog
{
// Construction
public:
	CTextDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTextDialog)
	enum { IDD = IDD_TEXT };
	CString	m_strText;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTextDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTDIALOG_H__8016228D_63E6_44D3_9237_76EA4C69A9CE__INCLUDED_)
