// Demo.h : main header file for the DEMO application
//

#if !defined(AFX_DEMO_H__C5DE1A68_417E_4AE6_B8B3_B046293DDBDC__INCLUDED_)
#define AFX_DEMO_H__C5DE1A68_417E_4AE6_B8B3_B046293DDBDC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDemoApp:
// See Demo.cpp for the implementation of this class
//

class CDemoApp : public CWinApp
{
public:
	CDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance(); 
	//}}AFX_VIRTUAL

	CMultiDocTemplate* m_pTemplateHex; 

// Implementation
	//{{AFX_MSG(CDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMO_H__C5DE1A68_417E_4AE6_B8B3_B046293DDBDC__INCLUDED_)
