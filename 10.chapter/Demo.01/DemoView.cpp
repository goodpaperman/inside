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
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
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

void CDemoView::OnDraw(CDC* pDC)
{
	CDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
    //pDC->BitBlt(20, -20, m_sizeSource.cx, -m_sizeSource.cy, 
    //    m_pdcMemory, 0, 0, SRCCOPY); 

    pDC->SetStretchBltMode(COLORONCOLOR); 
    pDC->StretchBlt(20, -20, m_sizeDest.cx, -m_sizeDest.cy, 
        m_pdcMemory, 0, 0, m_sizeSource.cx, m_sizeDest.cy, SRCCOPY); 

    pDC->StretchBlt(20, -520, m_sizeSource.cx, -m_sizeSource.cy, 
        m_pdcMemory, 0, 0, m_sizeSource.cx, m_sizeSource.cy, SRCCOPY); 
}

void CDemoView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	// TODO: calculate the total size of this view
    //CSize sizeTotal;
    //sizeTotal.cx = sizeTotal.cy = 100;
    //SetScrollSizes(MM_TEXT, sizeTotal);
	CSize sizeTotal(800, 1050); 
	CSize sizeLine = CSize(sizeTotal.cx/100, sizeTotal.cy/100); 
	SetScrollSizes(MM_LOENGLISH, sizeTotal, sizeTotal, sizeLine); 

	BITMAP bm; 
	if(m_pdcMemory->GetSafeHdc() == NULL)
	{
		CClientDC dc(this); 
		OnPrepareDC(&dc); 
		m_pBitmap->LoadBitmap(IDB_SETUP); //IDB_LIFTOFF); 
		m_pdcMemory->CreateCompatibleDC(&dc); 
		m_pdcMemory->SelectObject(m_pBitmap); 
		m_pBitmap->GetObject(sizeof(BITMAP), &bm); 
		m_sizeSource.cx = bm.bmWidth; 
		m_sizeSource.cy = bm.bmHeight; 
		m_sizeDest = m_sizeSource; 
		dc.DPtoLP(&m_sizeDest); 
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
