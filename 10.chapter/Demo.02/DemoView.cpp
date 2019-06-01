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
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoView construction/destruction

CDemoView::CDemoView() : m_sizeEllipse(100, -100), 
						 m_pointTopLeft(0, 0), 
						 m_sizeOffset(0, 0)
{
	// TODO: add construction code here
	m_bCaptured = FALSE; 
	m_pdcMemory = new CDC; 
	m_pBitmap = new CBitmap; 
}

CDemoView::~CDemoView()
{
	delete m_pdcMemory; 
	delete m_pBitmap; 
}

BOOL CDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView drawing

void CDemoView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	OnPrepareDC(&dc); 
	CRect rectUpdate;  
	dc.GetClipBox(&rectUpdate); 
	CBitmap* pOldBitmap = m_pdcMemory->SelectObject(m_pBitmap);
	m_pdcMemory->SelectClipRgn(NULL); 
	m_pdcMemory->IntersectClipRect(&rectUpdate); 

	CBrush backgroundBrush((COLORREF)::GetSysColor(COLOR_WINDOW)); 
	CBrush* pOldBrush = m_pdcMemory->SelectObject(&backgroundBrush); 
	m_pdcMemory->PatBlt(rectUpdate.left, rectUpdate.top, rectUpdate.Width(), rectUpdate.Height(), PATCOPY); 
	OnDraw(m_pdcMemory); 
	dc.BitBlt(rectUpdate.left, rectUpdate.top, rectUpdate.Width(), rectUpdate.Height(), 
		m_pdcMemory, rectUpdate.left, rectUpdate.top, SRCCOPY); 
	m_pdcMemory->SelectObject(pOldBitmap); 
	m_pdcMemory->SelectObject(pOldBrush); 
}

void CDemoView::OnDraw(CDC* pDC)
{
	CDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
    CBrush brushHatch(HS_DIAGCROSS, RGB(255, 0, 0)); 
    CPoint point(0, 0); 
    pDC->LPtoDP(&point); 
    pDC->SetBrushOrg(point); 

	pDC->SelectObject(&brushHatch); 
	pDC->Ellipse(CRect(m_pointTopLeft, m_sizeEllipse)); 
	pDC->SelectStockObject(BLACK_BRUSH); 
	pDC->Rectangle(CRect(100, -100, 200, -200)); 
}

void CDemoView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

    CSize sizeTotal(800, 1050);
    CSize sizePage(sizeTotal.cx/2, sizeTotal.cy/2); 
    CSize sizeLine(sizeTotal.cx/50, sizeTotal.cy/50); 
    SetScrollSizes(MM_LOENGLISH, sizeTotal, sizePage, sizeLine);

	if(m_pdcMemory->GetSafeHdc() == NULL)
	{
		CClientDC dc(this); 
		OnPrepareDC(&dc); 
		CRect rectMax(0, 0, sizeTotal.cx, -sizeTotal.cy); 
		dc.LPtoDP(&rectMax); 
		m_pdcMemory->CreateCompatibleDC(&dc); 
		m_pBitmap->CreateCompatibleBitmap(&dc, rectMax.right, rectMax.bottom); 
		m_pdcMemory->SetMapMode(MM_LOENGLISH); 
	}
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
{
	CScrollView::Dump(dc);
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
	CRect rectEllipse(m_pointTopLeft, m_sizeEllipse); 
	CRgn circle; 
	CClientDC dc(this); 
	OnPrepareDC(&dc); 
	dc.LPtoDP(rectEllipse); 
	circle.CreateEllipticRgnIndirect(rectEllipse); 
	if(circle.PtInRegion(point))
	{
		SetCapture(); 
		m_bCaptured = TRUE; 
		CPoint pointTopLeft(m_pointTopLeft); 
		dc.LPtoDP(&pointTopLeft); 
		m_sizeOffset = point - pointTopLeft; 
		::SetCursor(::LoadCursor(NULL, IDC_CROSS)); 
	}
}

void CDemoView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_bCaptured)
	{
		CClientDC dc(this); 
		OnPrepareDC(&dc); 
		CRect rectOld(m_pointTopLeft, m_sizeEllipse); 
		dc.LPtoDP(rectOld); 
		//InvalidateRect(&rectOld, TRUE); 
		InvalidateRect(&rectOld, FALSE); 
		m_pointTopLeft = point - m_sizeOffset; 
		dc.DPtoLP(&m_pointTopLeft); 
		CRect rectNew(m_pointTopLeft, m_sizeEllipse); 
		dc.LPtoDP(rectNew); 
		//InvalidateRect(&rectNew, TRUE); 
		InvalidateRect(&rectNew, FALSE); 
	}
}

void CDemoView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_bCaptured)
	{
		::ReleaseCapture(); 
		m_bCaptured = FALSE; 
	}
}