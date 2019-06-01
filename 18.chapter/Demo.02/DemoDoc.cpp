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

/////////////////////////////////////////////////////////////////////////////
// CDemoDoc construction/destruction

CDemoDoc::CDemoDoc()
{
	// TODO: add one-time construction code here

}

CDemoDoc::~CDemoDoc()
{
}

BOOL CDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	int n1, n2, n3; 
	srand((unsigned)time(NULL)); 
	m_ellipseArray.SetSize(nMaxEllipses); 
	for(int i=0; i<nMaxEllipses; i++)
	{
		n1 = rand() * 600 / RAND_MAX; 
		n2 = rand() * 600 / RAND_MAX; 
		n3 = rand() * 50 / RAND_MAX; 
		m_ellipseArray[i] = CRect(n1, -n2, n1 + n3, -(n2 + n3)); 
	}

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDemoDoc serialization

void CDemoDoc::Serialize(CArchive& ar)
{
	m_ellipseArray.Serialize(ar); 
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
