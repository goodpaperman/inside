// DemoDoc.cpp : implementation of the CDemoDoc class
//

#include "stdafx.h"
#include "Demo.h"

#include "DemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoDoc

IMPLEMENT_DYNCREATE(CDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CDemoDoc, CDocument)
	//{{AFX_DISPATCH_MAP(CDemoDoc)
	DISP_PROPERTY_NOTIFY(CDemoDoc, "Time", m_vaTime, OnTimeChanged, VT_DATE)
	DISP_FUNCTION(CDemoDoc, "RefreshWin", RefreshWin, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CDemoDoc, "ShowWin", ShowWin, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CDemoDoc, "CreateAlarm", CreateAlarm, VT_DISPATCH, VTS_DATE)
	DISP_PROPERTY_PARAM(CDemoDoc, "Figure", GetFigure, SetFigure, VT_VARIANT, VTS_I2)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IDemo to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {93748A0C-0957-46C9-A7D3-9E36392F4C4C}
static const IID IID_IDemo =
{ 0x93748a0c, 0x957, 0x46c9, { 0xa7, 0xd3, 0x9e, 0x36, 0x39, 0x2f, 0x4c, 0x4c } };

BEGIN_INTERFACE_MAP(CDemoDoc, CDocument)
	INTERFACE_PART(CDemoDoc, IID_IDemo, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoDoc construction/destruction

CDemoDoc::CDemoDoc() : m_pAlarm(0)
{
	// TODO: add one-time construction code here

	TRACE("CDemoDoc ctor\n"); 
	//m_pAlarm = NULL; 
	EnableAutomation();
	AfxOleLockApp();
}

CDemoDoc::~CDemoDoc()
{
	TRACE("CDemoDoc dtor\n"); 
	AfxOleUnlockApp();
}

BOOL CDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDemoDoc serialization

void CDemoDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDemoDoc diagnostics

#ifdef _DEBUG
void CDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDemoDoc commands

void CDemoDoc::OnTimeChanged() 
{
	// TODO: Add notification handler code
	TRACE("Time Change\n"); 
}

VARIANT CDemoDoc::GetFigure(short n) 
{
	// TODO: Add your property handler here
	TRACE("Entering CDemoDoc::GetFigure -- n = %d, m_strFigure[n] = %s\n", n, m_strFigure[n]); 
	return COleVariant(m_strFigure[n]).Detach();
}

void CDemoDoc::SetFigure(short n, const VARIANT FAR& newValue) 
{
	// TODO: Add your property handler here
	TRACE("Entering CDemoDoc::SetFigure -- n = %d, vt = %d\n", n, newValue.vt); 
	COleVariant vaTemp; 
	vaTemp.ChangeType(VT_BSTR, (COleVariant*)&newValue); 
	m_strFigure[n] = vaTemp.bstrVal; 
}

void CDemoDoc::RefreshWin() 
{
	// TODO: Add your dispatch handler code here
	COleDateTime dt(m_vaTime); 
	TRACE("Entering RefreshWin, Time = %02d:%02d:%02d\n", dt.GetHour(), dt.GetMinute(), dt.GetSecond()); 
	//AfxGetMainWnd()->UpdateWindow(); 
	UpdateAllViews(NULL); 
}

void CDemoDoc::ShowWin() 
{
	// TODO: Add your dispatch handler code here
	AfxGetMainWnd()->ShowWindow(SW_SHOW); 
}

LPDISPATCH CDemoDoc::CreateAlarm(DATE time) 
{
	// TODO: Add your dispatch handler code here
	TRACE("Entering CDemoDoc::CreateAlarm, time = %f\n", time); 
	m_pAlarm = new CAlarm(time); 
	return m_pAlarm->GetIDispatch(FALSE); 
}
