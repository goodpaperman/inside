// DemoView.cpp : implementation of the CDemoView class
//

#include "stdafx.h"
#include "Demo.h"

#include "DemoDoc.h"
#include "DemoView.h"
#include <math.h>

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
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
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

/////////////////////////////////////////////////////////////////////////////
// CDemoView drawing

void CDemoView::OnDraw(CDC* pDC)
{
	CDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	CRect rect; 
	GetClientRect(&rect); 

    pDC->SetMapMode(MM_ISOTROPIC); 
    pDC->SetWindowExt(200, 200); 
    pDC->SetViewportExt(rect.Width(), -rect.Height()); 
    pDC->SetViewportOrg(rect.Width()/2, rect.Height()/2); //(rect.Width()/2, rect.Height()/2); 

	COleDateTime dt(pDoc->m_vaTime); 
	
	const int nPos1 = 70; 
	const int nPos2 = 80; 
	const int nPos3 = 90; 
	const double PI = 3.1415926535897262; 
	CPen pen(PS_SOLID, 2, RGB(0, 0, 0)); 
	CPen* pOldPen = NULL; 
	for(int i=0; i<60; i++)
	{
		double angle = i * 360 / 60 * PI / 180; 
		if(i % 5 == 0)
		{
			pOldPen = pDC->SelectObject(&pen); 
			pDC->MoveTo(nPos1*sin(angle), nPos1*cos(angle)); 
			pDC->LineTo(nPos3*sin(angle), nPos3*cos(angle)); 
			pDC->SelectObject(pOldPen); 
		}
		else 
		{
    		pDC->MoveTo(nPos2*sin(angle), nPos2*cos(angle)); 
    		pDC->LineTo(nPos3*sin(angle), nPos3*cos(angle)); 
		}
	}

	double angle = (double)dt.GetSecond() / 60 * 360 * PI / 180; 
	pDC->MoveTo(0, 0); 
	pDC->LineTo(nPos3*sin(angle), nPos3*cos(angle)); 

	angle = (double)dt.GetMinute() / 60 * 360 * PI / 180; 
	pDC->MoveTo(0, 0); 
	pDC->LineTo(nPos1*sin(angle), nPos1*cos(angle)); 

	pOldPen = pDC->SelectObject(&pen); 
	angle = (double)dt.GetHour() / 12 * 360 * PI / 180; 
	pDC->MoveTo(0, 0); 
	pDC->LineTo(60*sin(angle), 60*cos(angle)); 
	pDC->SelectObject(pOldPen); 

	CSize size = pDC->GetTextExtent(pDoc->m_strFigure[0]); 
	pDC->TextOut(-size.cx/2, 100, pDoc->m_strFigure[0]); 
	size = pDC->GetTextExtent(pDoc->m_strFigure[1]); 
	pDC->TextOut(90, size.cy/2, pDoc->m_strFigure[1]); 
	size = pDC->GetTextExtent(pDoc->m_strFigure[2]);
	pDC->TextOut(-size.cx/2, -90, pDoc->m_strFigure[2]); 
	size = pDC->GetTextExtent(pDoc->m_strFigure[3]); 
	pDC->TextOut(-100, size.cy/2, pDoc->m_strFigure[3]); 

	if(pDoc->m_pAlarm)
	{
		COleDateTime time(pDoc->m_pAlarm->m_time); 
		angle = (double)time.GetHour() / 12 * 360 * PI / 180; 
		pDC->TextOut(nPos1*sin(angle), nPos1*cos(angle), "A"); 
	}
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
