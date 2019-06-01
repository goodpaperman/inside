// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__2C7CE009_CD8B_461A_91F0_193F6933E2FE__INCLUDED_)
#define AFX_STDAFX_H__2C7CE009_CD8B_461A_91F0_193F6933E2FE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers`

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT


#import "..\Demo.02\debug\bank.tlb" rename_namespace("BankDriv")
using namespace BankDriv; 
#import "..\Demo.03\debug\demo2.tlb" rename_namespace("AutoDriv")
using namespace AutoDriv; 
#import "..\Demo.04\debug\demo3.tlb" rename_namespace("ClockDriv")
using namespace ClockDriv; 


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__2C7CE009_CD8B_461A_91F0_193F6933E2FE__INCLUDED_)
