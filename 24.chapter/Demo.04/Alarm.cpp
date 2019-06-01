// Alarm.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "Alarm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAlarm

IMPLEMENT_DYNAMIC(CAlarm, CCmdTarget)

CAlarm::CAlarm(DATE time)
{
	EnableAutomation();
	TRACE("CAlarm ctor.\n"); 
	m_time = time; 
}

CAlarm::~CAlarm()
{
	TRACE("CAlarm dtor.\n"); 
}


void CAlarm::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CAlarm, CCmdTarget)
	//{{AFX_MSG_MAP(CAlarm)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CAlarm, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CAlarm)
	DISP_PROPERTY(CAlarm, "Time", m_time, VT_DATE)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IAlarm to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {95CA716B-AACA-4558-A488-B22DC29E0700}
static const IID IID_IAlarm =
{ 0x95ca716b, 0xaaca, 0x4558, { 0xa4, 0x88, 0xb2, 0x2d, 0xc2, 0x9e, 0x7, 0x0 } };

BEGIN_INTERFACE_MAP(CAlarm, CCmdTarget)
	INTERFACE_PART(CAlarm, IID_IAlarm, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAlarm message handlers
