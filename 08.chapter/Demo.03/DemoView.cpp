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

const char CDemoView::s_engineAltavista[] = "http://altavista.digital.com"; 

IMPLEMENT_DYNCREATE(CDemoView, CView)

BEGIN_MESSAGE_MAP(CDemoView, CView)
	//{{AFX_MSG_MAP(CDemoView)
	ON_WM_CREATE()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_EVENTSINK_MAP(CDemoView, CView)
	ON_EVENT(CDemoView, ID_BROWSER_SEARCH, 100, 
			OnBeforeNavigateExplorer1, VTS_BSTR VTS_I4 
			VTS_BSTR VTS_PVARIANT VTS_BSTR VTS_PBOOL)
	ON_EVENT(CDemoView, ID_BROWSER_TARGET, 113, 
			OnTitleChangeExplorer2, VTS_BSTR)
END_EVENTSINK_MAP()

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

int CDemoView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	DWORD dwStyle = WS_VISIBLE | WS_CHILD; 
	if(m_search.Create(NULL, dwStyle, CRect(0, 0, 100, 100), this, ID_BROWSER_SEARCH) == 0)
	{
		AfxMessageBox("Unable to create search control!\n"); 
		return -1; 
	}

	if(m_target.Create(NULL, dwStyle, CRect(0, 0, 100, 100), this, ID_BROWSER_TARGET) == 0)
	{
		AfxMessageBox("Unable to create target control!\n");
		return -1; 
	}

	return 0;
}

void CDemoView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	m_search.Navigate(s_engineAltavista, NULL, NULL, NULL, NULL); 
	m_target.GoHome(); 
}


void CDemoView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	CRect rectClient; 
	GetClientRect(&rectClient); 
	CRect rectBrowse(rectClient); 
	rectBrowse.right = rectClient.right/2; 
	CRect rectSearch(rectClient); 
	rectSearch.left = rectClient.right/2; 

	m_target.SetWidth(rectBrowse.Width()); 
	m_target.SetHeight(rectBrowse.Height()); 
	m_target.UpdateWindow(); 

	m_search.SetLeft(rectSearch.left); 
	m_search.SetWidth(rectSearch.Width()); 
	m_search.SetHeight(rectSearch.Height()); 
	m_search.UpdateWindow(); 
}

void CDemoView::OnBeforeNavigateExplorer1(LPCTSTR URL, 
	long Flags, LPCTSTR TargetFrameName, 
	VARIANT* PostData, LPCTSTR Headers, BOOL* Cancel)
{
	TRACE("CDemoView::OnBeforeNavigateExplorer1 -- URL = %s\n", URL); 
	if(!strnicmp(URL, s_engineAltavista, strlen(s_engineAltavista)))
		return; 

	m_target.Navigate(URL, NULL, NULL, NULL, NULL); 
	*Cancel = TRUE; 
}

void CDemoView::OnTitleChangeExplorer2(LPCTSTR Text)
{
	CWnd* pWnd = AfxGetApp()->m_pMainWnd; 
	if(pWnd != NULL)
	{
		if(::IsWindow(pWnd->m_hWnd))
			pWnd->SetWindowText(Text); 
	}
}