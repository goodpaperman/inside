#if !defined(AFX_TABLESELECT_H__FF078E05_2F1F_4D28_9237_1D2783E34936__INCLUDED_)
#define AFX_TABLESELECT_H__FF078E05_2F1F_4D28_9237_1D2783E34936__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TableSelect.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTableSelect dialog

class CTableSelect : public CDialog
{
// Construction
public:
	CTableSelect(CDaoDatabase* pDatabase, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTableSelect)
	enum { IDD = IDD_TABLE_SELECT };
	CString	m_strSelection;
	//}}AFX_DATA
    CDaoDatabase* m_pDatabase; 


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTableSelect)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTableSelect)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkTables();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABLESELECT_H__FF078E05_2F1F_4D28_9237_1D2783E34936__INCLUDED_)
