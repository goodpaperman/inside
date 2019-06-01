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

IMPLEMENT_DYNCREATE(CDemoView, CScrollView)

BEGIN_MESSAGE_MAP(CDemoView, CScrollView)
	//{{AFX_MSG_MAP(CDemoView)
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoView construction/destruction

CDemoView::CDemoView() : m_rectEllipse(0, 0, 4000, -4000)
{
	// TODO: add construction code here
	m_nColor = GRAY_BRUSH; 
}

CDemoView::~CDemoView()
{
}

BOOL CDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

void CDemoView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate(); 
	CSize sizeTotal(20000, 30000); 
	CSize sizePage(sizeTotal.cx/2, sizeTotal.cy/2); 
	CSize sizeLine(sizeTotal.cx/50, sizeTotal.cy/50); 
	SetScrollSizes(MM_HIMETRIC, sizeTotal, sizePage, sizeLine); 
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView drawing

void CDemoView::OnDraw(CDC* pDC)
{
	CDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	// TODO: add draw code for native data here
	pDC->SelectStockObject(m_nColor); 
	pDC->Ellipse(m_rectEllipse); 
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView printing

BOOL CDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
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
	CScrollView::AssertValid();
}

void CDemoView::Dump(CDumpContext& dc) const
{	CScrollView::Dump(dc);
}

CDemoDoc* CDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDemoDoc)));
	return (CDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDemoView message handlers

void CDemoView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this); 
	OnPrepareDC(&dc); 
	CRect rectDevice = m_rectEllipse; 
	dc.LPtoDP(&rectDevice); 

	CRgn rgn; 
	rgn.CreateEllipticRgnIndirect(&rectDevice); 
	//if(rectDevice.PtInRect(point))
	if(rgn.PtInRegion(point))
	{
		if(m_nColor == GRAY_BRUSH)
			m_nColor = WHITE_BRUSH; 
		else 
			m_nColor = GRAY_BRUSH; 
	}

	InvalidateRect(&rectDevice); 
	CScrollView::OnLButtonDown(nFlags, point);
}

//void CDemoView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
//{
//    // TODO: Add your specialized code here and/or call the base class
//    pDC->SetMapMode(MM_HIMETRIC); 
//    CScrollView::OnPrepareDC(pDC, pInfo);
//}

void CDemoView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default	
	//CScrollView::OnKeyDown(nChar, nRepCnt, nFlags);

	switch(nChar)
	{
		case VK_HOME:
			OnVScroll(SB_TOP, 0, NULL); 
			OnHScroll(SB_LEFT, 0, NULL); 
			break; 
		case VK_END:
			OnVScroll(SB_BOTTOM, 0, NULL); 
			OnHScroll(SB_RIGHT, 0, NULL); 
			break; 
		case VK_UP:
			OnVScroll(SB_LINEUP, 0, NULL); 
			break; 
		case VK_DOWN:
			OnVScroll(SB_LINEDOWN, 0, NULL); 
			break; 
		case VK_PRIOR:
			OnVScroll(SB_PAGEUP, 0, NULL); 
			break; 
		case VK_NEXT:
			OnVScroll(SB_PAGEDOWN, 0, NULL); 
			break; 
		case VK_LEFT:
			OnHScroll(SB_LINELEFT, 0, NULL); 
			break; 
		case VK_RIGHT:
			OnHScroll(SB_LINERIGHT, 0, NULL); 
			break; 
		default:
			break; 
	}
}
