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
	int nPosition = 0; 
	for(int i=6; i<=24; i+=2)
		ShowFont(pDC, nPosition, i); 

	TRACE("LOGPIXELSX = %d, LOGPIXELSY = %d\n", 
		pDC->GetDeviceCaps(LOGPIXELSX), 
		pDC->GetDeviceCaps(LOGPIXELSY)); 
	TRACE("HORZSIZE = %d, VERTSIZE = %d\n", 
		pDC->GetDeviceCaps(HORZSIZE), 
		pDC->GetDeviceCaps(VERTSIZE)); 
	TRACE("HORZRES = %d, VERTRES = %d\n", 
		pDC->GetDeviceCaps(HORZRES), 
		pDC->GetDeviceCaps(VERTRES)); 
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
	pDC->SetMapMode(MM_ANISOTROPIC); 
	pDC->SetWindowExt(1440, 1440); 
	pDC->SetViewportExt(pDC->GetDeviceCaps(LOGPIXELSX), -pDC->GetDeviceCaps(LOGPIXELSY)); 
	//CView::OnPrepareDC(pDC, pInfo);
}

void CDemoView::ShowFont(CDC *pDC, int &nPos, int nPoints)
{
	TEXTMETRIC tm = { 0 }; 
	CFont fontText; 
	CString strText; 
	CSize sizeText; 

	fontText.CreateFont(-nPoints*20, 0, 0, 0, 400, FALSE, FALSE, FALSE, 
		ANSI_CHARSET, OUT_DEFAULT_PRECIS, 
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 
		DEFAULT_PITCH | FF_SWISS, "Arial"); 

	CFont* pOldFont = (CFont*)pDC->SelectObject(&fontText); 
	pDC->GetTextMetrics(&tm); 
	TRACE("points = %d, tmHeight = %d, tmInternalLeading = %d,"
		"tmExternalLeading = %d\n", nPoints, tm.tmHeight, 
		tm.tmInternalLeading, tm.tmExternalLeading); 

	strText.Format("This is %d - point Arial", nPoints); 
	sizeText = pDC->GetTextExtent(strText); 
	TRACE("string width = %d, string height = %d\n", 
		sizeText.cx, sizeText.cy); 

	pDC->TextOut(0, nPos, strText); 
	pDC->SelectObject(pOldFont); 
	nPos -= tm.tmHeight + tm.tmExternalLeading; 
}
