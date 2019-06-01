#if !defined(AFX_COMPUTEDLG_H__72E0F12D_63F6_45C6_B27C_4E51CC91E3E0__INCLUDED_)
#define AFX_COMPUTEDLG_H__72E0F12D_63F6_45C6_B27C_4E51CC91E3E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ComputeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CComputeDlg dialog

class CComputeDlg : public CDialog
{
// Construction
public:
	CComputeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CComputeDlg)
	enum { IDD = IDD_COMPUTE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

protected:
	int m_nTimer; 

public:
	enum { nMaxCount = 10000 }; 


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComputeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CComputeDlg)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnStart();
	virtual void OnCancel();
	//}}AFX_MSG
	afx_msg LRESULT OnThreadFinished(WPARAM wParam, LPARAM lParam); 
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMPUTEDLG_H__72E0F12D_63F6_45C6_B27C_4E51CC91E3E0__INCLUDED_)
