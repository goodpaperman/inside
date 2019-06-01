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
	ON_COMMAND(ID_TRANSFER_GETDATA, OnTransferGetdata)
	ON_COMMAND(ID_TRANSFER_STOREDATA, OnTransferStoredata)
	ON_UPDATE_COMMAND_UI(ID_TRANSFER_STOREDATA, OnUpdateTransferStoredata)
	ON_WM_CREATE()
	ON_WM_SIZE()
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

int CDemoView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	CRect rect(0, 0, 0, 0); 
	m_rich.Create(ES_AUTOVSCROLL | ES_MULTILINE | ES_WANTRETURN | WS_CHILD | WS_VISIBLE | WS_VSCROLL, 
		rect, this, 1); 
	return 0;
}

void CDemoView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	CRect rect; 
	GetClientRect(&rect); 
	m_rich.SetWindowPos(&wndTop, 0, 0, rect.Width(), rect.Height(), SWP_SHOWWINDOW); 
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

void CDemoView::OnTransferGetdata() 
{
	// TODO: Add your command handler code here
	CDemoDoc* pDoc = GetDocument(); 
	m_rich.SetWindowText(pDoc->m_strText); 
	m_rich.SetModify(FALSE); 
}

void CDemoView::OnTransferStoredata() 
{
	// TODO: Add your command handler code here
	CDemoDoc* pDoc = GetDocument(); 
	m_rich.GetWindowText(pDoc->m_strText); 
	m_rich.SetModify(FALSE); 
}

void CDemoView::OnUpdateTransferStoredata(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_rich.GetModify()); 
}