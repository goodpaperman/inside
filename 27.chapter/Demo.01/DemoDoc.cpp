// DemoDoc.cpp : implementation of the CDemoDoc class
//

#include "stdafx.h"
#include "Demo.h"

#include "DemoDoc.h"
#include "SrvrItem.h"
#include "TextDialog.h" 

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoDoc

IMPLEMENT_DYNCREATE(CDemoDoc, COleServerDoc)

BEGIN_MESSAGE_MAP(CDemoDoc, COleServerDoc)
	//{{AFX_MSG_MAP(CDemoDoc)
	ON_COMMAND(ID_MODIFY, OnModify)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoDoc construction/destruction

CDemoDoc::CDemoDoc()
{
	// Use OLE compound files
	EnableCompoundFile();

	// TODO: add one-time construction code here

}

CDemoDoc::~CDemoDoc()
{
}

BOOL CDemoDoc::OnNewDocument()
{
	if (!COleServerDoc::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	m_strText = "Initial default text"; 
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CDemoDoc server implementation

COleServerItem* CDemoDoc::OnGetEmbeddedItem()
{
	// OnGetEmbeddedItem is called by the framework to get the COleServerItem
	//  that is associated with the document.  It is only called when necessary.

	CDemoSrvrItem* pItem = new CDemoSrvrItem(this);
	ASSERT_VALID(pItem);
	return pItem;
}



/////////////////////////////////////////////////////////////////////////////
// CDemoDoc serialization

void CDemoDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		ar << m_strText; 
	}
	else
	{
		// TODO: add loading code here
		ar >> m_strText; 
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDemoDoc diagnostics

#ifdef _DEBUG
void CDemoDoc::AssertValid() const
{
	COleServerDoc::AssertValid();
}

void CDemoDoc::Dump(CDumpContext& dc) const
{
	COleServerDoc::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDemoDoc commands

void CDemoDoc::OnModify() 
{
	// TODO: Add your command handler code here
	CTextDialog dlg; 
	dlg.m_strText = m_strText; 
	if(dlg.DoModal() == IDOK)
	{
		m_strText = dlg.m_strText; 
		UpdateAllViews(NULL); 
		UpdateAllItems(NULL); 
		SetModifiedFlag(); 
	}
}
