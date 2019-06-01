#if !defined(AFX_DEMODLG_H__A35E4808_4BF7_43A3_B4A4_EC97CA5E5860__INCLUDED_)
#define AFX_DEMODLG_H__A35E4808_4BF7_43A3_B4A4_EC97CA5E5860__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DemoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDemoDlg dialog

class CDemoDlg : public CDialog
{
// Construction
public:
	CDemoDlg(CWnd* pParent = NULL);   // standard constructor
	CDemoDlg(CView* pView); 
	BOOL Create(); 

// Dialog Data
	//{{AFX_DATA(CDemoDlg)
	enum { IDD = IDD_DIALOG1 };
	CString	m_strEdit1;
	//}}AFX_DATA

private:
	CView* m_pView; 

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
	virtual void OnCancel();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMODLG_H__A35E4808_4BF7_43A3_B4A4_EC97CA5E5860__INCLUDED_)
