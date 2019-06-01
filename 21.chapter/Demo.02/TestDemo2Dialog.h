#if !defined(AFX_TESTDEMO2DIALOG_H__0A4258EE_8D81_4FC0_93E5_96B341204A0F__INCLUDED_)
#define AFX_TESTDEMO2DIALOG_H__0A4258EE_8D81_4FC0_93E5_96B341204A0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TestDemo2Dialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTestDemo2Dialog dialog

extern "C" __declspec(dllimport) void DemoEntry(); 
#define RYG_SETSTATE (WM_USER+1)
#define RYG_GETSTATE (WM_USER+2)

class CTestDemo2Dialog : public CDialog
{
// Construction
public:
	CTestDemo2Dialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTestDemo2Dialog)
	enum { IDD = IDD_DEMO2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

private:
	enum { OFF, RED, YELLOW, GREEN } m_nState; 

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestDemo2Dialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTestDemo2Dialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	afx_msg void OnClickedRyg(); 
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTDEMO2DIALOG_H__0A4258EE_8D81_4FC0_93E5_96B341204A0F__INCLUDED_)
