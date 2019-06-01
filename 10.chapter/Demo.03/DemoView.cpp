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
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
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

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView drawing

void CDemoView::OnDraw(CDC* pDC)
{
	CDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	BeginWaitCursor(); 
	m_dibResource.UsePalette(pDC); 
	m_dibFile.UsePalette(pDC); 
	pDC->TextOut(0, 0, "Click the left mouse button here to load a file."); 
	CSize sizeResourceDib = m_dibResource.GetDimensions(); 
	sizeResourceDib.cx *= 30; 
	sizeResourceDib.cy *= -30; 
	m_dibResource.Draw(pDC, CPoint(0, -800), sizeResourceDib); 
	CSize sizeFileDib = m_dibFile.GetDimensions(); 
	sizeFileDib.cx *= 30; 
	sizeFileDib.cy *= -30; 
	m_dibFile.Draw(pDC, CPoint(1800, -800), sizeFileDib); 
	EndWaitCursor(); 
}

void CDemoView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal(30000, 40000); // 30 - by - 40 cm
	CSize sizeLine = CSize(sizeTotal.cx/100, sizeTotal.cy/100); 
	SetScrollSizes(MM_HIMETRIC, sizeTotal, sizeTotal, sizeLine); 
	LPVOID lpvResource = (LPVOID)::LoadResource(NULL, ::FindResource(NULL, MAKEINTRESOURCE(IDB_LIFTOFF), RT_BITMAP)); 
	m_dibResource.AttachMemory(lpvResource); 
	CClientDC dc(this); 
	TRACE("bits per pixel = %d\n", dc.GetDeviceCaps(BITSPIXEL)); 
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

#define MEMORY_MAPPED_FILES

void CDemoView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CFileDialog dlg(TRUE, "bmp", "*.bmp"); 
	if(dlg.DoModal() != IDOK)
		return; 

#ifdef MEMORY_MAPPED_FILES
	if(m_dibFile.AttachMapFile(dlg.GetPathName(), TRUE))
		Invalidate(); 
#else
	CFile file; 
	file.Open(dlg.GetPathName(), CFile::modeRead); 
	if(m_dibFile.Read(&file))
		Invalidate(); 
#endif
	CClientDC dc(this); 
	m_dibFile.SetSystemPalette(&dc); 
}
