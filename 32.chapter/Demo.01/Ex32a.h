// Ex32a.h : main header file for the EX32A application
//

#if !defined(AFX_EX32A_H__9C3546E7_143C_4A31_98EC_8280B52C5B0B__INCLUDED_)
#define AFX_EX32A_H__9C3546E7_143C_4A31_98EC_8280B52C5B0B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx32aApp:
// See Ex32a.cpp for the implementation of this class
//

class CEx32aApp : public CWinApp
{
public:
	CEx32aApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx32aApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	COleTemplateServer m_server;
		// Server object for document creation
	//{{AFX_MSG(CEx32aApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX32A_H__9C3546E7_143C_4A31_98EC_8280B52C5B0B__INCLUDED_)
