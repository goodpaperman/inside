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

    TEXTMETRIC tm; 
    pDC->GetTextMetrics(&tm); 
    int nLineHeight = tm.tmHeight + tm.tmExternalLeading; 
    CPoint ptText(0, 0); 
    int y = 0; 
    CString str; 
    if(m_pSet->IsBOF())
        return; 

    m_pSet->MoveFirst(); 
    while(!m_pSet->IsEOF())
    {
        str.Format("%ld", m_pSet->m_StudentID); 
        pDC->TextOut(ptText.x, ptText.y, str); 
        pDC->TextOut(ptText.x + 1000, ptText.y, m_pSet->m_Name); 
        str.Format("%d", m_pSet->m_GradYear); 
        pDC->TextOut(ptText.x  + 4000, ptText.y, str); 
        //str.Format("%d", m_pSet->m_CourseID); 
        pDC->TextOut(ptText.x + 5000, ptText.y, m_pSet->m_CourseID); //str);
        //str.Format("%f", m_pSet->m_Grade); 
        pDC->TextOut(ptText.x + 6000, ptText.y, m_pSet->m_Grade); //str); 
        m_pSet->MoveNext(); 
        ptText.y -= nLineHeight; 
    }
}

void CDemoView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal(8000, 10500);
	// TODO: calculate the total size of this view
	SetScrollSizes(MM_HIENGLISH, sizeTotal);

    m_pSet = &GetDocument()->m_DemoSet; 
    m_pSet->m_strFilter = "[Student].[StudentID] = [Enrollment].[StudentID]"; 
    if(m_pSet->IsOpen())
        m_pSet->Close(); 
    m_pSet->Open(); 
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
