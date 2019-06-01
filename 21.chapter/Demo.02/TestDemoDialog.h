#if !defined(AFX_TESTDEMODIALOG_H__B57A156C_330C_48E1_B5A1_E91B4648FFB7__INCLUDED_)
#define AFX_TESTDEMODIALOG_H__B57A156C_330C_48E1_B5A1_E91B4648FFB7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TestDemoDialog.h : header file
//

extern "C" __declspec(dllimport) double DemoSquareRoot(double d); 

/////////////////////////////////////////////////////////////////////////////
// CTestDemoDialog dialog

class CTestDemoDialog : public CDialog
{
// Construction
public:
	CTestDemoDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTestDemoDialog)
	enum { IDD = IDD_DEMO };
	double	m_dInput;
	double	m_dOutput;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestDemoDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTestDemoDialog)
	afx_msg void OnCompute();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTDEMODIALOG_H__B57A156C_330C_48E1_B5A1_E91B4648FFB7__INCLUDED_)
