// DemoView.cpp : implementation of the CDemoView class
//

#include "stdafx.h"
#include "Demo.h"

#include "DemoDoc.h"
#include "DemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoView

IMPLEMENT_DYNCREATE(CDemoView, CView)

BEGIN_MESSAGE_MAP(CDemoView, CView)
	//{{AFX_MSG_MAP(CDemoView)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoView construction/destruction

CDemoView::CDemoView()
{
	// TODO: add construction code here

}

CDemoView::~CDemoView()
{
}

BOOL CDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView drawing

void CDemoView::OnDraw(CDC* pDC)
{
	CDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView diagnostics

#ifdef _DEBUG
void CDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDemoDoc* CDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDemoDoc)));
	return (CDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDemoView message handlers

void CDemoView::OnEditCopy() 
{
	// TODO: Add your command handler code here
	COleDataSource* pSource = SaveText(); 
	if(pSource)
		pSource->SetClipboard(); 
}

void CDemoView::OnEditPaste() 
{
	// TODO: Add your command handler code here
	COleDataObject dataObject; 
	VERIFY(dataObject.AttachClipboard()); 
	DoPasteText(&dataObject); 
}

COleDataSource* CDemoView::SaveText()
{
	CDemoDoc* pDoc = GetDocument(); 
	if(!pDoc->m_strText.IsEmpty())
	{
		COleDataSource* pSource = new COleDataSource(); 
		int nTextSize = GetDocument()->m_strText.GetLength() + 1; 
		HGLOBAL hText = ::GlobalAlloc(GMEM_SHARE, nTextSize); 
		LPSTR pText = (LPSTR)::GlobalLock(hText); 
		ASSERT(pText); 
		strcpy(pText, GetDocument()->m_strText); 
		::GlobalUnlock(hText); 
		pSource->CacheGlobalData(CF_TEXT, hText); 
		return pSource; 
	}

	return NULL; 
}

BOOL CDemoView::DoPasteText(COleDataObject* pDataObject)
{
	STGMEDIUM stg; 
	FORMATETC fmt; 
	if(!pDataObject->IsDataAvailable(CF_TEXT))
	{
		TRACE("CF_TEXT format is unavailable\n"); 
		return FALSE; 
	}

	SETFORMATETC(fmt, CF_TEXT, DVASPECT_CONTENT, NULL, TYMED_HGLOBAL, -1); 
	VERIFY(pDataObject->GetData(CF_TEXT, &stg, &fmt)); 
	HGLOBAL hText = stg.hGlobal; 
	GetDocument()->m_strText = (LPSTR)::GlobalLock(hText); 
	::GlobalUnlock(hText); 
	TRACE("strText: %s\n", GetDocument()->m_strText); 
	return TRUE;  
}
