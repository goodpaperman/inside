#if !defined(AFX_SPECIALFILEDLG_H__3B36D7F5_998F_41BE_A038_6FB99EB2EC50__INCLUDED_)
#define AFX_SPECIALFILEDLG_H__3B36D7F5_998F_41BE_A038_6FB99EB2EC50__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SpecialFileDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSpecialFileDialog dialog

class CSpecialFileDialog : public CFileDialog
{
// Construction
public:
	CSpecialFileDialog(BOOL bOpenFileDialog, 
		LPCTSTR lpszDefExt = NULL, 
		LPCTSTR lpszFileName = NULL, 
		DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, 
		LPCTSTR lpszFilter = NULL, 
		CWnd* pParentWnd = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSpecialFileDialog)
	enum { IDD = IDD_FILESPECIAL };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

public:
	CString m_strFileName; 
	BOOL m_bDeleteAll;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpecialFileDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSpecialFileDialog)
	virtual BOOL OnInitDialog();
	afx_msg void OnDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPECIALFILEDLG_H__3B36D7F5_998F_41BE_A038_6FB99EB2EC50__INCLUDED_)
