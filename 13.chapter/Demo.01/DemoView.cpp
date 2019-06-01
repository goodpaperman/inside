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
	ON_COMMAND(ID_DRAW_CIRCLE, OnDrawCircle)
	ON_UPDATE_COMMAND_UI(ID_DRAW_CIRCLE, OnUpdateDrawCircle)
	ON_COMMAND(ID_DRAW_SQUARE, OnDrawSquare)
	ON_UPDATE_COMMAND_UI(ID_DRAW_SQUARE, OnUpdateDrawSquare)
	ON_COMMAND(ID_DRAW_PATTERN, OnDrawPattern)
	ON_UPDATE_COMMAND_UI(ID_DRAW_PATTERN, OnUpdateDrawPattern)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoView construction/destruction

CDemoView::CDemoView() : m_rect(0, 0, 100, 100)
{
	// TODO: add construction code here
	m_bCircle = TRUE; 
	m_bPattern = FALSE; 
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

	CBrush brush(HS_BDIAGONAL, 0L); 

	if(m_bPattern)
		pDC->SelectObject(&brush); 
	else 
		pDC->SelectStockObject(WHITE_BRUSH); 

	if(m_bCircle)
		pDC->Ellipse(m_rect); 
	else 
		pDC->Rectangle(m_rect); 

	pDC->SelectStockObject(WHITE_BRUSH); 
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

void CDemoView::OnDrawCircle() 
{
	// TODO: Add your command handler code here
	m_bCircle = TRUE; 
	m_rect += CPoint(25, 25); 
	InvalidateRect(&m_rect); 
}

void CDemoView::OnUpdateDrawCircle(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(!m_bCircle); 
}

void CDemoView::OnDrawSquare() 
{
	// TODO: Add your command handler code here
	m_bCircle = FALSE; 
	m_rect += CPoint(25, 25); 
	InvalidateRect(&m_rect); 
}

void CDemoView::OnUpdateDrawSquare(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_bCircle); 
}

void CDemoView::OnDrawPattern() 
{
	// TODO: Add your command handler code here
	m_bPattern ^= 1; 
}

void CDemoView::OnUpdateDrawPattern(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_bPattern); 
}
