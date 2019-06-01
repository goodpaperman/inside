// DemoView.cpp : implementation of the CDemoView class
//

#include "stdafx.h"
#include "Demo.h"

#include "DemoDoc.h"
#include "DemoView.h"
#include "DemoDlg.h"

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
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_GOODBYE, OnGoodbye)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoView construction/destruction

CDemoView::CDemoView()
{
	// TODO: add construction code here
	m_pDlg = new CDemoDlg(this); 
}

CDemoView::~CDemoView()
{
	delete m_pDlg; 
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
	pDC->TextOut(0, 0, "Press the left mouse button here."); 
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

void CDemoView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_pDlg->GetSafeHwnd() == 0)
		m_pDlg->Create(); 
}

void CDemoView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_pDlg->DestroyWindow(); 
}

LRESULT CDemoView::OnGoodbye(WPARAM wParam, LPARAM lParam)
{
	TRACE("CDemoView::OnGoodbye %x, %lx\n", wParam, lParam); 
	TRACE("Dialog edit1 contents = %s\n", 
		(const char*)m_pDlg->m_strEdit1); 
	m_pDlg->DestroyWindow();
	return 0L; 
}