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
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
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

	int j = pDoc->m_ellipseArray.GetUpperBound(); 
	for(int i=0; i<j; i++)
		pDC->Ellipse(pDoc->m_ellipseArray[i]); 
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView printing

BOOL CDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	CDemoDoc* pDoc = GetDocument(); 
	pInfo->SetMaxPage(pDoc->m_ellipseArray.GetUpperBound() / CDemoDoc::nLinesPerPage + 1); 
	return DoPreparePrinting(pInfo);
}

void CDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
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
	pDC->SetMapMode(MM_LOENGLISH); 
}

void CDemoView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	pDC->SetMapMode(MM_TWIPS); 
	CDemoDoc* pDoc = GetDocument(); 
	m_nPage = pInfo->m_nCurPage; 
	int nStart = (m_nPage - 1) * CDemoDoc::nLinesPerPage; 
	int nEnd = nStart + CDemoDoc::nLinesPerPage; 

	CFont font; 
	font.CreateFont(-280, 0, 0, 0, 400, FALSE, FALSE, FALSE, 
					ANSI_CHARSET, OUT_DEFAULT_PRECIS, 
					CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 
					DEFAULT_PITCH | FF_MODERN, "Courier New"); 

	CFont* pOldFont = (CFont*)pDC->SelectObject(&font); 
	PrintPageHeader(pDC); 

	TEXTMETRIC tm; 
	pDC->GetTextMetrics(&tm); 
	CPoint point(720, -1440); 
	int nHeight = tm.tmHeight + tm.tmExternalLeading; 
	for(int i=nStart; i<nEnd; i++)
	{
		if(i>pDoc->m_ellipseArray.GetUpperBound())
			break; 

		CString str; 
		str.Format("%6d %6d %6d %6d %6d", i+1, 
			pDoc->m_ellipseArray[i].left, 
			pDoc->m_ellipseArray[i].top, 
			pDoc->m_ellipseArray[i].right, 
			pDoc->m_ellipseArray[i].bottom); 
		
		point.y -= nHeight; 
		pDC->TextOut(point.x, point.y, str); 
	}

	PrintPageFooter(pDC); 
	pDC->SelectObject(pOldFont); 
}

void CDemoView::PrintPageHeader(CDC* pDC)
{
	CString str; 
	CPoint point(0, 0); 
	pDC->TextOut(point.x, point.y, "Bubble Reprot"); 
	point += CSize(720, -720); 
	str.Format("%6.6s %6.6s %6.6s %6.6s %6.6s", 
		"Index", "Left", "Top", "Right", "Bottom"); 
	pDC->TextOut(point.x, point.y, str); 
}

void CDemoView::PrintPageFooter(CDC* pDC)
{
	CString str; 
	CPoint point(0, -14400); 
	CDemoDoc* pDoc = GetDocument(); 
	str.Format("Document %s", (LPCTSTR)pDoc->GetTitle()); 
	pDC->TextOut(point.x, point.y, str); 
	str.Format("Page %d", m_nPage); 
	CSize size = pDC->GetTextExtent(str); 
	point.x += 11520 - size.cx; 
	pDC->TextOut(point.x, point.y, str); 
}
