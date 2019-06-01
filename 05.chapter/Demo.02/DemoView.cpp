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
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
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
	CFont fontTest1, fontTest2, fontTest3, fontTest4; 
	fontTest1.CreateFont(50, 0, 0, 0, 400, FALSE, FALSE, FALSE, 
		ANSI_CHARSET, OUT_DEFAULT_PRECIS, 
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 
		DEFAULT_PITCH | FF_SWISS, "Arial"); 
	CFont* pOldFont = pDC->SelectObject(&fontTest1); 
	TraceMetrics(pDC); 
	pDC->TextOut(0, 0, "This is Arial, default width"); 

	fontTest2.CreateFont(50, 0, 0, 0, 400, FALSE, FALSE, FALSE, 
		ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, 
		DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Courier"); 
	pDC->SelectObject(&fontTest2); 
	TraceMetrics(pDC); 
	pDC->TextOut(0, 100, "This is Courier, default width"); 

	fontTest3.CreateFont(50, 10, 0, 0, 400, FALSE, FALSE, FALSE, 
		ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, 
		DEFAULT_QUALITY, DEFAULT_PITCH | FF_ROMAN, NULL); 
	pDC->SelectObject(&fontTest3); 
	TraceMetrics(pDC); 
	pDC->TextOut(0, 200, "This is generic Roman, variable width"); 

	fontTest4.CreateFont(50, 0, 0, 0, 400, FALSE, FALSE, FALSE, 
		ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, 
		DEFAULT_QUALITY, DEFAULT_PITCH | FF_MODERN, "LinePrinter"); 
	pDC->SelectObject(&fontTest4); 
	TraceMetrics(pDC); 
	pDC->TextOut(0, 300, "This is LinePrinter, default width"); 
	pDC->SelectObject(pOldFont); 
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

void CDemoView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	CRect clientRect; 
	GetClientRect(&clientRect); 
	pDC->SetMapMode(MM_ANISOTROPIC); 
	pDC->SetWindowExt(400, 450); 
	pDC->SetViewportExt(clientRect.right, clientRect.bottom); 
	pDC->SetViewportOrg(0, 0); 

}

void CDemoView::TraceMetrics(CDC* pDC)
{
	TEXTMETRIC tm; 
	char szFaceName[100]; 
	pDC->GetTextMetrics(&tm); 
	pDC->GetTextFace(99, szFaceName); 
	TRACE("font = %s, tmHeight = %d, tmInternalLeading = %d, "
		"tmExternalLeading = %d\n", szFaceName, tm.tmHeight, 
		tm.tmInternalLeading, tm.tmExternalLeading); 
}