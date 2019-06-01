// Bank.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "Bank.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBank

IMPLEMENT_DYNCREATE(CBank, CCmdTarget)

CBank::CBank()
{
	EnableAutomation();
	
	// To keep the application running as long as an OLE automation 
	//	object is active, the constructor calls AfxOleLockApp.
	
	m_dBalance = 0; 
	AfxOleLockApp();
	TRACE("Bank is open!\n"); 
}

CBank::~CBank()
{
	// To terminate the application when all objects created with
	// 	with OLE automation, the destructor calls AfxOleUnlockApp.
	
	AfxOleUnlockApp();
	TRACE("Bank is close!\n"); 
}


void CBank::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CBank, CCmdTarget)
	//{{AFX_MSG_MAP(CBank)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CBank, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CBank)
	DISP_PROPERTY_EX(CBank, "Balance", GetBalance, SetBalance, VT_R8)
	DISP_FUNCTION(CBank, "Withdrawal", Withdrawal, VT_R8, VTS_R8)
	DISP_FUNCTION(CBank, "Deposit", Deposit, VT_EMPTY, VTS_R8)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IBank to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {B66CB015-C9B1-485B-9E0B-D7EBD2858834}
static const IID IID_IBank =
{ 0xb66cb015, 0xc9b1, 0x485b, { 0x9e, 0xb, 0xd7, 0xeb, 0xd2, 0x85, 0x88, 0x34 } };

BEGIN_INTERFACE_MAP(CBank, CCmdTarget)
	INTERFACE_PART(CBank, IID_IBank, Dispatch)
END_INTERFACE_MAP()

// {03E074A4-5B70-4DD7-A214-2D5782A09849}
IMPLEMENT_OLECREATE2(CBank, "Demo.Bank", 0x3e074a4, 0x5b70, 0x4dd7, 0xa2, 0x14, 0x2d, 0x57, 0x82, 0xa0, 0x98, 0x49)

/////////////////////////////////////////////////////////////////////////////
// CBank message handlers

double CBank::Withdrawal(double dAmount) 
{
	// TODO: Add your dispatch handler code here
	if(dAmount < 0.0)
		return 0.0; 

	if(dAmount <= m_dBalance)
	{
		m_dBalance -= dAmount; 
		return dAmount; 
	}

	double dTemp = m_dBalance; 
	m_dBalance = 0.0; 
	return dTemp;
}

void CBank::Deposit(double dAmount) 
{
	// TODO: Add your dispatch handler code here
	if(dAmount < 0.0)
		return; 

	m_dBalance += dAmount; 
}

double CBank::GetBalance() 
{
	// TODO: Add your property handler here

	return m_dBalance;
}

void CBank::SetBalance(double newValue) 
{
	// TODO: Add your property handler here
	TRACE("Sorry, Dave, I can't do that!\n"); 
}
