// HexView.cpp : implementation of the CHexView class
//

#include "stdafx.h"
#include "Demo.h"

#include "PoemDoc.h"
#include "HexView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHexView

IMPLEMENT_DYNCREATE(CHexView, CScrollView)

BEGIN_MESSAGE_MAP(CHexView, CScrollView)
	//{{AFX_MSG_MAP(CHexView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHexView construction/destruction

// 8 * 10.5 inch.
CHexView::CHexView() : m_rectPrint(0, 0, 11520, -15120)
{
	// TODO: add construction code here

}

CHexView::~CHexView()
{
}

BOOL CHexView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CHexView drawing

void CHexView::OnDraw(CDC* pDC)
{
	CPoemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	pDC->Rectangle(m_rectPrint + CRect(0, 0, -20, 20)); 

	CString str; 
	int j = m_rectPrint.Width() / 1440; 
	for(int i=0; i<=j; i++)
	{
		str.Format("%02d", i); 
		pDC->TextOut(i*1440, 0, str); 
	}

	j = -m_rectPrint.Height() / 1440; 
	for(i=0; i<=j; i++)
	{
		str.Format("%02d", i); 
		pDC->TextOut(0, -i*1440, str); 
	}

	CFont font; 
	font.CreateFont(-160, 80, 0, 0, 400, FALSE, FALSE, FALSE, ANSI_CHARSET, 
					OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, 
					DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, 
					"Arial"); 
	CFont* pOldFont = (CFont*)pDC->SelectObject(&font); 
	
	TEXTMETRIC tm; 
	pDC->GetTextMetrics(&tm); 
	int nHeight = tm.tmHeight + tm.tmExternalLeading; 
	TRACE("font height = %d, internal leading = %d\n", 
		nHeight, tm.tmInternalLeading); 

	CString outputline; 
	j = pDoc->m_stringArray.GetSize(); 
	for(i = 0; i<j; i++)
	{
		outputline.Format("%02x ", i); 
		int l = pDoc->m_stringArray[i].GetLength(); 
		for(int k=0; k<l; k++)
		{
			int n = pDoc->m_stringArray[i][k] & 0x00FF; 
			str.Format("%02x", n); 
			outputline += str; 
		}

		pDC->TextOut(720, -i*nHeight - 720, outputline); 
	}

	pDC->SelectObject(pOldFont); 
	TRACE("LOGPIXELSX = %d, LOGPIXELSY = %d\n", 
		pDC->GetDeviceCaps(LOGPIXELSX), 
		pDC->GetDeviceCaps(LOGPIXELSY)); 
	TRACE("HORZSIZE = %d, VERTSIZE = %d\n", 
		pDC->GetDeviceCaps(HORZSIZE), 
		pDC->GetDeviceCaps(VERTSIZE)); 
}

void CHexView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal(m_rectPrint.Width(), -m_rectPrint.Height());
	CSize sizePage(sizeTotal.cx / 2, sizeTotal.cy / 2); 
	CSize sizeLine(sizeTotal.cx / 100, sizeTotal.cy / 100); 
	SetScrollSizes(MM_TWIPS, sizeTotal, sizePage, sizeLine);
}

/////////////////////////////////////////////////////////////////////////////
// CHexView printing

BOOL CHexView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	pInfo->SetMaxPage(1); 
	return DoPreparePrinting(pInfo);
}

void CHexView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CHexView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CHexView diagnostics

#ifdef _DEBUG
void CHexView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CHexView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CPoemDoc* CHexView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPoemDoc)));
	return (CPoemDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHexView message handlers

void CHexView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	m_rectPrint = pInfo->m_rectDraw; 
	CSize sizeTotal(m_rectPrint.Width(), -m_rectPrint.Height());
	CSize sizePage(sizeTotal.cx / 2, sizeTotal.cy / 2); 
	CSize sizeLine(sizeTotal.cx / 100, sizeTotal.cy / 100); 
	SetScrollSizes(MM_TWIPS, sizeTotal, sizePage, sizeLine); 
	CScrollView::OnPrint(pDC, pInfo);
}
