// DemoAuto.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "DemoAuto.h"
#include "PromptDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoAuto

IMPLEMENT_DYNCREATE(CDemoAuto, CCmdTarget)

CDemoAuto::CDemoAuto()
{
	EnableAutomation();
	
	// To keep the application running as long as an OLE automation 
	//	object is active, the constructor calls AfxOleLockApp.

	m_lData = 0; 
	::VariantInit(&m_vaTextData); 
	AfxOleLockApp();
	TRACE("CDemoAuto create.\n");
}

CDemoAuto::~CDemoAuto()
{
	// To terminate the application when all objects created with
	// 	with OLE automation, the destructor calls AfxOleUnlockApp.
	
	AfxOleUnlockApp();
	TRACE("CDemoAuot destroyed.\n"); 
}


void CDemoAuto::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CDemoAuto, CCmdTarget)
	//{{AFX_MSG_MAP(CDemoAuto)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CDemoAuto, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CDemoAuto)
	DISP_PROPERTY_NOTIFY(CDemoAuto, "LongData", m_lData, OnLongDataChanged, VT_I4)
	DISP_PROPERTY_NOTIFY(CDemoAuto, "TextData", m_vaTextData, OnTextDataChanged, VT_VARIANT)
	DISP_FUNCTION(CDemoAuto, "DisplayDialog", DisplayDialog, VT_BOOL, VTS_NONE)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IDemoAuto to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {E3EA3678-AE8D-43B6-B418-7E3A1CD7CC2D}
static const IID IID_IDemoAuto =
{ 0xe3ea3678, 0xae8d, 0x43b6, { 0xb4, 0x18, 0x7e, 0x3a, 0x1c, 0xd7, 0xcc, 0x2d } };

BEGIN_INTERFACE_MAP(CDemoAuto, CCmdTarget)
	INTERFACE_PART(CDemoAuto, IID_IDemoAuto, Dispatch)
END_INTERFACE_MAP()

// {C67BE7D0-9010-4E06-B282-7E8798D15168}
IMPLEMENT_OLECREATE(CDemoAuto, "Demo.Auto", 0xc67be7d0, 0x9010, 0x4e06, 0xb2, 0x82, 0x7e, 0x87, 0x98, 0xd1, 0x51, 0x68)

/////////////////////////////////////////////////////////////////////////////
// CDemoAuto message handlers

void CDemoAuto::OnLongDataChanged() 
{
	// TODO: Add notification handler code
	TRACE("CDemoAuto::OnLongDataChanged\n"); 
}

void CDemoAuto::OnTextDataChanged() 
{
	// TODO: Add notification handler code
	TRACE("CDemoAuto::OnTextDataChanged\n"); 
}

BOOL CDemoAuto::DisplayDialog() 
{
	// TODO: Add your dispatch handler code here
	TRACE("Entering CDemoAuto::DisplayDialog %p\n", this); 
	BOOL bRet = TRUE; 
	AfxLockTempMaps(); 
	CWnd* pTopWnd = CWnd::FromHandle(::GetTopWindow(NULL)); 
	try
	{
		CPromptDlg dlg; 
		if(m_vaTextData.vt == VT_BSTR)
			dlg.m_strValue = m_vaTextData.bstrVal; 
		dlg.m_lValue = m_lData; 
		if(dlg.DoModal() == IDOK)
		{
			m_vaTextData = COleVariant(dlg.m_strValue).Detach(); 
			m_lData = dlg.m_lValue; 
			bRet = TRUE; 
		}
		else 
			bRet = FALSE; 
	}
	catch(CException* pe)
	{
		TRACE("Exception: failure to display dialog\n"); 
		bRet = FALSE; 
		pe->Delete(); 
	}
	AfxUnlockTempMaps(); 
	return bRet;
}
