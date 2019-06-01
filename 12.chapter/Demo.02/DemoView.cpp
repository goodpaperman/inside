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
	ON_COMMAND(ID_FORMAT_DEFAULT, OnFormatDefault)
	ON_COMMAND(ID_FORMAT_SELECTION, OnFormatSelection)
	ON_UPDATE_COMMAND_UI(ID_FORMAT_SELECTION, OnUpdateFormatSelection)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_USERAPPLY, OnUserApply) 
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoView construction/destruction

CDemoView::CDemoView() : m_sh("")
{
	// TODO: add construction code here
	m_sh.m_page1.m_nFont = 0; 
	m_sh.m_page2.m_bBold = FALSE; 
	m_sh.m_page2.m_bItalic = FALSE; 
	m_sh.m_page2.m_bUnderline = FALSE; 
	m_sh.m_page3.m_nColor = 0; 
	m_sh.m_page4.m_nFontSize = 12; 
	g_pView = this; 
	m_bDefault = TRUE; 
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

	CHARFORMAT cf; 
	Format(cf); 
	m_rich.SetDefaultCharFormat(cf); 
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

void CDemoView::OnFormatDefault() 
{
	// TODO: Add your command handler code here
	m_sh.SetTitle("Default Format"); 
	m_bDefault = TRUE; 
	m_sh.DoModal(); 
}

void CDemoView::OnFormatSelection() 
{
	// TODO: Add your command handler code here
	m_sh.SetTitle("Selection Format"); 
	m_bDefault = FALSE; 
	m_sh.DoModal(); 
}

void CDemoView::OnUpdateFormatSelection(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	long nStart, nEnd; 
	m_rich.GetSel(nStart, nEnd); 
	pCmdUI->Enable(nStart != nEnd); 
}

LRESULT CDemoView::OnUserApply(WPARAM wParam, LPARAM lParam)
{
	TRACE("CDemoView::OnUserApply - wParam = %x\n", wParam); 
	CHARFORMAT cf; 
	Format(cf); 
	if(m_bDefault)
		m_rich.SetDefaultCharFormat(cf); 
	else 
		m_rich.SetSelectionCharFormat(cf); 

	return 0; 
}

void CDemoView::Format(CHARFORMAT& cf)
{
	cf.cbSize = sizeof(CHARFORMAT); 
	cf.dwMask = CFM_BOLD | CFM_COLOR | CFM_FACE | 
				CFM_ITALIC | CFM_SIZE | CFM_UNDERLINE; 
	cf.dwEffects = (m_sh.m_page2.m_bBold ? CFE_BOLD : 0) | 
				   (m_sh.m_page2.m_bItalic ? CFE_ITALIC : 0) |
				   (m_sh.m_page2.m_bUnderline ? CFE_UNDERLINE : 0); 
	cf.yHeight = m_sh.m_page4.m_nFontSize * 20; 
	
	switch(m_sh.m_page3.m_nColor)
	{
		case -1:
		case 0:
			cf.crTextColor = RGB(0, 0, 0); 
			break; 
		case 1:
			cf.crTextColor = RGB(255, 0, 0); 
			break; 
		case 2:
			cf.crTextColor = RGB(0, 255, 0); 
			break; 
	}

	switch(m_sh.m_page1.m_nFont)
	{
		case -1:
		case 0:
			strcpy(cf.szFaceName, "Times New Roman"); 
			break; 
		case 1:
			strcpy(cf.szFaceName, "Arial"); 
			break; 
		case 2:
			strcpy(cf.szFaceName, "Courier New"); 
			break; 
	}

	cf.bCharSet = 0; 
	cf.bPitchAndFamily = 0; 
}
