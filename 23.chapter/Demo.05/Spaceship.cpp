// Spaceship.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "Interface.h"
#include "Spaceship.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpaceship

IMPLEMENT_DYNCREATE(CSpaceship, CCmdTarget)

CSpaceship::CSpaceship()
{
	//EnableAutomation();
	TRACE("CSpaceship ctor\n"); 
	m_nPosition = 100; 
	m_nAcceleration = 101; 
	m_nColor = 102; 
	
	// To keep the application running as long as an OLE automation 
	//	object is active, the constructor calls AfxOleLockApp.
	
	AfxOleLockApp();
}

CSpaceship::~CSpaceship()
{
	TRACE("CSpaceship dtor\n"); 
	// To terminate the application when all objects created with
	// 	with OLE automation, the destructor calls AfxOleUnlockApp.
	
	AfxOleUnlockApp();
}


void CSpaceship::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	//CCmdTarget::OnFinalRelease();
	delete this; 
}


BEGIN_MESSAGE_MAP(CSpaceship, CCmdTarget)
	//{{AFX_MSG_MAP(CSpaceship)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//BEGIN_DISPATCH_MAP(CSpaceship, CCmdTarget)
//    //{{AFX_DISPATCH_MAP(CSpaceship)
//        // NOTE - the ClassWizard will add and remove mapping macros here.
//    //}}AFX_DISPATCH_MAP
//END_DISPATCH_MAP()

// Note: we add support for IID_ISpaceship to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {420B7A4A-9648-4505-A736-FC60B5BD3EF2}
static const IID IID_ISpaceship =
{ 0x420b7a4a, 0x9648, 0x4505, { 0xa7, 0x36, 0xfc, 0x60, 0xb5, 0xbd, 0x3e, 0xf2 } };

BEGIN_INTERFACE_MAP(CSpaceship, CCmdTarget)
	//INTERFACE_PART(CSpaceship, IID_ISpaceship, Dispatch)
	INTERFACE_PART(CSpaceship, IID_IMotion, Motion)
	INTERFACE_PART(CSpaceship, IID_IVisual, Visual)
END_INTERFACE_MAP()

// {77782B23-960D-4F47-A92E-727E229E5A78}
IMPLEMENT_OLECREATE(CSpaceship, "Demo.Spaceship", 0x77782b23, 0x960d, 0x4f47, 0xa9, 0x2e, 0x72, 0x7e, 0x22, 0x9e, 0x5a, 0x78)

/////////////////////////////////////////////////////////////////////////////
// CSpaceship message handlers

STDMETHODIMP_(ULONG) CSpaceship::XMotion::AddRef()
{
	TRACE("CSpaceship::XMotion::AddRef\n"); 
	METHOD_PROLOGUE(CSpaceship, Motion)
	return pThis->ExternalAddRef(); 
}

STDMETHODIMP_(ULONG) CSpaceship::XMotion::Release()
{
	TRACE("CSpaceship::XMotion::Release\n"); 
	METHOD_PROLOGUE(CSpaceship, Motion)
	return pThis->ExternalRelease(); 
}

STDMETHODIMP CSpaceship::XMotion::QueryInterface(REFIID iid, LPVOID* ppvObj)
{
	ITrace(iid, "CSpaceship::XMotion::QueryInterface"); 
	METHOD_PROLOGUE(CSpaceship, Motion)
	return pThis->ExternalQueryInterface(&iid, ppvObj); 
}

STDMETHODIMP_(void) CSpaceship::XMotion::Fly()
{
	TRACE("CSpaceship::XMotion::Fly\n"); 
	METHOD_PROLOGUE(CSpaceship, Motion)
	TRACE("m_nPosition = %d\n", pThis->m_nPosition); 
	TRACE("m_nAcceleration = %d\n", pThis->m_nAcceleration); 
	return; 
}

STDMETHODIMP_(int&) CSpaceship::XMotion::GetPosition()
{
	TRACE("CSpaceship::XMotion::GetPosition\n"); 
	METHOD_PROLOGUE(CSpaceship, Motion)
	TRACE("m_nPosition = %d\n", pThis->m_nPosition); 
	TRACE("m_nAcceleration = %d\n", pThis->m_nAcceleration); 
	return pThis->m_nPosition; 
}

STDMETHODIMP_(ULONG) CSpaceship::XVisual::AddRef()
{
	TRACE("CSpaceship::XVisual::AddRef\n"); 
	METHOD_PROLOGUE(CSpaceship, Visual)
	return pThis->ExternalAddRef(); 
}

STDMETHODIMP_(ULONG) CSpaceship::XVisual::Release()
{
	TRACE("CSpaceship::XVisual::Release\n"); 
	METHOD_PROLOGUE(CSpaceship, Visual)
	return pThis->ExternalRelease(); 
}

STDMETHODIMP CSpaceship::XVisual::QueryInterface(REFIID iid, LPVOID* ppvObj)
{
	ITrace(iid, "CSpaceship::XVisual::QueryInterface"); 
	METHOD_PROLOGUE(CSpaceship, Visual)
	return pThis->ExternalQueryInterface(&iid, ppvObj); 
}

STDMETHODIMP_(void) CSpaceship::XVisual::Display()
{
	TRACE("CSpaceship::XVisual::Display\n"); 
	METHOD_PROLOGUE(CSpaceship, Visual)
	TRACE("m_nPosition = %d\n", pThis->m_nPosition); 
	TRACE("m_nColor = %d\n", pThis->m_nColor); 
}

void ITrace(REFIID iid, const char* str)
{
	OLECHAR* lpszIID; 
	::StringFromIID(iid, &lpszIID); 
	CString strTemp = (LPCWSTR)lpszIID; 
	TRACE("%s - %s\n", (const char*)strTemp, (const char*)str); 
	AfxFreeTaskMem(lpszIID); 
}