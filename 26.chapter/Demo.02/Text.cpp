// Text.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "Text.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CText

IMPLEMENT_DYNCREATE(CText, CCmdTarget)

CText::CText()
{
	EnableAutomation();
	
	// To keep the application running as long as an OLE automation 
	//	object is active, the constructor calls AfxOleLockApp.
	
	AfxOleLockApp();
	m_pchText = NULL; 
}

CText::~CText()
{
	// To terminate the application when all objects created with
	// 	with OLE automation, the destructor calls AfxOleUnlockApp.
	
	if(m_pchText != NULL)
		delete[] m_pchText; 

	AfxOleUnlockApp();
}


void CText::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CText, CCmdTarget)
	//{{AFX_MSG_MAP(CText)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CText, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CText)
	DISP_PROPERTY_EX(CText, "Text", GetText, SetText, VT_VARIANT)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IText to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {0CBC9685-4D25-4CBE-A79A-63A30711B110}
static const IID IID_IText =
{ 0xcbc9685, 0x4d25, 0x4cbe, { 0xa7, 0x9a, 0x63, 0xa3, 0x7, 0x11, 0xb1, 0x10 } };

BEGIN_INTERFACE_MAP(CText, CCmdTarget)
	INTERFACE_PART(CText, IID_IText, Dispatch)
	INTERFACE_PART(CText, IID_IPersistStream, PersistStream) 
END_INTERFACE_MAP()

// {2B43BB26-5C11-4DA5-9035-D5B71F590100}
IMPLEMENT_OLECREATE(CText, "Demo.Text", 0x2b43bb26, 0x5c11, 0x4da5, 0x90, 0x35, 0xd5, 0xb7, 0x1f, 0x59, 0x1, 0x0)

/////////////////////////////////////////////////////////////////////////////
// CText message handlers

VARIANT CText::GetText() 
{
	return COleVariant(m_pchText).Detach(); 
}

void CText::SetText(const VARIANT FAR& newValue) 
{
	// TODO: Add your property handler here
	CString strTemp; 
	ASSERT(newValue.vt == VT_BSTR); 
	if(m_pchText != NULL)
		delete[] m_pchText; 

	strTemp = newValue.bstrVal; 
	m_pchText = new char[strTemp.GetLength() + 1]; 
	strcpy(m_pchText, strTemp); 
}

STDMETHODIMP_(ULONG) CText::XPersistStream::AddRef()
{
	METHOD_PROLOGUE(CText, PersistStream) 
	return (ULONG)pThis->ExternalAddRef(); 
}

STDMETHODIMP_(ULONG) CText::XPersistStream::Release()
{
	METHOD_PROLOGUE(CText, PersistStream) 
	return (ULONG)pThis->ExternalRelease(); 
}

STDMETHODIMP CText::XPersistStream::QueryInterface(REFIID iid, void **ppvObj)
{
	METHOD_PROLOGUE(CText, PersistStream) 
	return (HRESULT)pThis->ExternalQueryInterface(&iid, ppvObj); 
}

STDMETHODIMP CText::XPersistStream::GetClassID(LPCLSID lpClassID)
{
	METHOD_PROLOGUE(CText, PersistStream)
	ASSERT_VALID(pThis); 
	*lpClassID = CText::guid; 
	return NOERROR; 
}

STDMETHODIMP CText::XPersistStream::IsDirty()
{
	METHOD_PROLOGUE(CText, PersistStream)
	ASSERT_VALID(pThis); 
	return NOERROR; 
}

STDMETHODIMP CText::XPersistStream::Load(LPSTREAM pStm)
{
	ULONG nLength; 
	STATSTG statstg; 
	METHOD_PROLOGUE(CText, PersistStream) 
	ASSERT_VALID(pThis); 
	if(pThis->m_pchText != NULL)
		delete [] pThis->m_pchText; 

	VERIFY(pStm->Stat(&statstg, STATFLAG_NONAME) == NOERROR); 
	int nSize = statstg.cbSize.QuadPart; 
	if(nSize > 0)
	{
		pThis->m_pchText = new char[nSize]; 
		pStm->Read(pThis->m_pchText, nSize, &nLength); 
	}

	return NOERROR; 
}

STDMETHODIMP CText::XPersistStream::Save(LPSTREAM pStm, BOOL fClearDirty)
{
	METHOD_PROLOGUE(CText, PersistStream)
	ASSERT_VALID(pThis);
	int nSize = strlen(pThis->m_pchText) + 1; 
	pStm->Write(pThis->m_pchText, nSize, NULL); 
	return NOERROR; 
}

STDMETHODIMP CText::XPersistStream::GetSizeMax(ULARGE_INTEGER* pcbSize)
{
	METHOD_PROLOGUE(CText, PersistStream) 
	ASSERT_VALID(pThis); 
	pcbSize->LowPart = strlen(pThis->m_pchText) + 1; 
	pcbSize->HighPart = 0; 
	return NOERROR; 
}
