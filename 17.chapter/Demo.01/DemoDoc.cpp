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
	ON_COMMAND(ID_EDIT_CLEAR_ALL, OnEditClearAll)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CLEAR_ALL, OnUpdateEditClearAll)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE, OnUpdateFileSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoDoc construction/destruction

CDemoDoc::CDemoDoc()// : m_student("default value", 0)
{
	// TODO: add one-time construction code here
	TRACE("Document object constructed\n"); 
#ifdef _DEBUG
	afxDump.SetDepth(1); 
#endif
}

CDemoDoc::~CDemoDoc()
{
}

BOOL CDemoDoc::OnNewDocument()
{
	TRACE("Entering CStudentDoc::OnNewDocument.\n"); 
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
	TRACE("Entering CDemoDoc::Serialize\n"); 
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}

	m_studentList.Serialize(ar); 
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
	dc << "\n" << m_studentList << "\n"; 
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDemoDoc commands

void CDemoDoc::DeleteContents() 
{
	// TODO: Add your specialized code here and/or call the base class
#ifdef _DEBUG
	Dump(afxDump); 
#endif
	
	TRACE("Entering CDemoDoc::DeleteContents\n"); 
	while(m_studentList.GetHeadPosition())
		delete m_studentList.RemoveHead(); 

	CDocument::DeleteContents();
}

void CDemoDoc::OnEditClearAll() 
{
	// TODO: Add your command handler code here
	DeleteContents(); 
	UpdateAllViews(NULL); 
}

void CDemoDoc::OnUpdateEditClearAll(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(!m_studentList.IsEmpty()); 
}

BOOL CDemoDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	TRACE("Entering CDemoDoc::OnOpenDocument\n"); 
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// TODO: Add your specialized creation code here
	
	return TRUE;
}

void CDemoDoc::OnUpdateFileSave(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(IsModified()); 
}
