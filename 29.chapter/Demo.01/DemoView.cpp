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

IMPLEMENT_DYNCREATE(CDemoView, CRowView)

BEGIN_MESSAGE_MAP(CDemoView, CRowView)
	//{{AFX_MSG_MAP(CDemoView)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CRowView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CRowView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRowView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoView construction/destruction

CDemoView::CDemoView()
{
	// TODO: add construction code here
    m_nSelectRow = 0; 
    m_pSet = NULL; 
    m_nCharWidth = 0; 
}

CDemoView::~CDemoView()
{
}

BOOL CDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRowView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView drawing

void CDemoView::OnDraw(CDC* pDC)
{
	CDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CDemoView::OnInitialUpdate()
{
	CRowView::OnInitialUpdate();

    //CSize sizeTotal;
    //// TODO: calculate the total size of this view
    //sizeTotal.cx = sizeTotal.cy = 100;
    //SetScrollSizes(MM_TEXT, sizeTotal);
    KillTimer(0); 
    SetTimer(0, 1000, NULL); 
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
	CRowView::AssertValid();
}

void CDemoView::Dump(CDumpContext& dc) const
{
	CRowView::Dump(dc);
}

CDemoDoc* CDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDemoDoc)));
	return (CDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDemoView message handlers

void CDemoView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	CDemoDoc* pDoc = GetDocument(); 
    m_pSet = pDoc->m_pRecordset;     
}

void CDemoView::GetRowWidthHeight(CDC* pDC, int& nRowWidth, int& nRowHeight)
{
    TEXTMETRIC tm = { 0 }; 
    pDC->GetTextMetrics(&tm); 
    nRowHeight = tm.tmHeight + tm.tmExternalLeading; 

    CRect rect; 
    GetClientRect(&rect); 
    nRowWidth = rect.Width(); 
    m_nCharWidth = tm.tmAveCharWidth; 
}

int CDemoView::GetActiveRow()
{
    return m_nSelectRow; 
}

void CDemoView::ChangeSelectionNextRow(BOOL bNext)
{
}

void CDemoView::ChangeSelectionToRow(int nRow)
{
}

int CDemoView::GetRowCount()
{
    return GetDocument()->m_nRowCount; 
}

void CDemoView::OnDrawRow(CDC* pDC, int nRow, int y, BOOL bSelected)
{
    int x =0; 
    int i; 
    CDemoDoc* pDoc = GetDocument(); 
    if(m_pSet == NULL)
        return; 

    if(nRow == 0)
    {
        for(i=0; i<pDoc->m_nFields; i++)
        {
            pDC->TextOut(x, y, pDoc->m_arrayFieldName[i]); 
            x += pDoc->m_arrayFieldSize[i] * m_nCharWidth; 
        }
    }
    else 
    {
        try
        {
            m_pSet->SetAbsolutePosition(nRow-1); 
            if(m_pSet->GetAbsolutePosition() == (nRow - 1))
                DrawDataRow(pDC, y); 
        }
        catch(CDaoException* e)
        {
            if(e->m_pErrorInfo->m_lErrorCode == 3167)
            {
                pDC->TextOut(0, y, "**RECORD DELETED**");
            }
            else 
            {
                m_pSet->MoveLast(); 
                pDoc->m_nRowCount = m_pSet->GetAbsolutePosition() + 2; 
            }
            e->Delete(); 
        }
    }
}

void CDemoView::DrawDataRow(CDC* pDC, int y)
{
    int x = 0; 
    CString strTime; 
    COleVariant var; 
    CString str; 
    CDemoDoc* pDoc = GetDocument(); 
    for(int i=0; i<pDoc->m_nFields; i++)
    {
        var = m_pSet->GetFieldValue(i); 
        switch(var.vt)
        {
        case VT_BSTR:
            str = (LPCSTR)var.bstrVal; 
            break; 
        case VT_I2:
            str.Format("%d", (int)var.iVal); 
            break; 
        case VT_I4:
            str.Format("%d", var.lVal); 
            break; 
        case VT_R4:
            str.Format("%10.2f", (double)var.fltVal); 
            break; 
        case VT_R8:
            str.Format("%10.2f", var.dblVal); 
            break; 
        case VT_CY:
            str = COleCurrency(var).Format(); 
            break; 
        case VT_DATE:
            str = COleDateTime(var).Format(); 
            break; 
        case VT_BOOL:
            str = (var.boolVal == 0) ? "FALSE" : "TRUE"; 
            break; 
        case VT_NULL:
            str = "-----"; 
            break; 
        default:
            str.Format("Unknown type %d\n", var.vt); 
        }

        pDC->TextOut(x, y, str); 
        x += pDoc->m_arrayFieldSize[i] * m_nCharWidth; 
    }
}

void CDemoView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	Invalidate(); 
	CRowView::OnTimer(nIDEvent);
}
