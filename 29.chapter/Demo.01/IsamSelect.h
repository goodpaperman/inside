#if !defined(AFX_ISAMSELECT_H__DEB90B10_6FDD_4741_9BE9_673B8B614E0D__INCLUDED_)
#define AFX_ISAMSELECT_H__DEB90B10_6FDD_4741_9BE9_673B8B614E0D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// IsamSelect.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CIsamSelect dialog

class CIsamSelect : public CDialog
{
// Construction
public:
	CIsamSelect(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CIsamSelect)
	enum { IDD = IDD_ISAM_SELECT };
	CString	m_strDirectory;
	CString	m_strIsam;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIsamSelect)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CIsamSelect)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ISAMSELECT_H__DEB90B10_6FDD_4741_9BE9_673B8B614E0D__INCLUDED_)
