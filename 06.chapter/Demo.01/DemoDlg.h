#if !defined(AFX_DEMODLG_H__6928906E_34E5_4212_AE21_D3774514D00B__INCLUDED_)
#define AFX_DEMODLG_H__6928906E_34E5_4212_AE21_D3774514D00B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DemoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDemoDlg dialog

enum { nMin = 0 }; 
enum { nMax = 100 }; 

class CDemoDlg : public CDialog
{
// Construction
public:
	CDemoDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDemoDlg)
	enum { IDD = IDD_DIALOG1 };
	CString	m_strBio;
	int		m_nCat;
	CString	m_strDept;
	BOOL	m_bInsDis;
	CString	m_strEduc;
	BOOL	m_bInsLife;
	int		m_nLoyal;
	BOOL	m_bInsMed;
	CString	m_strName;
	int		m_nRely;
	CString	m_strSkill;
	int		m_nSsn;
	int		m_nLang;
	//}}AFX_DATA

	HBRUSH m_hYellowBrush; 
	HBRUSH m_hRedBrush; 


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDemoDlg)
	afx_msg void OnSpecial();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnBtnOK();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMODLG_H__6928906E_34E5_4212_AE21_D3774514D00B__INCLUDED_)
