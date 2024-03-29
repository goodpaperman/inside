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
	CDemoDlg dlg; 
	dlg.m_strName = "Shakespeare, Will"; 
	dlg.m_nSsn = 307806636; 
	dlg.m_nCat = 1; 
	dlg.m_strBio = "This person is not a well - motivated tech writer"; 
	dlg.m_bInsLife = TRUE; 
	dlg.m_bInsDis = FALSE; 
	dlg.m_bInsMed = TRUE; 
	dlg.m_strDept = "Documentation"; 
	dlg.m_strSkill = "Writer"; 
	dlg.m_nLang = 0; 
	dlg.m_strEduc = "College"; 
	dlg.m_nLoyal = dlg.m_nRely = 50; 
	int ret = dlg.DoModal(); 

	TRACE("DoModal return = %d\n", ret); 
	TRACE("name = %s, ssn = %d, cat = %d\n", 
		dlg.m_strName, dlg.m_nSsn, dlg.m_nCat); 
	TRACE("dept = %s, skill = %s, lang = %d, educ = %s\n", 
		dlg.m_strDept, dlg.m_strSkill, dlg.m_nLang, dlg.m_strEduc); 
	TRACE("life = %d, dis = %d, med = %d, bio = %s\n", 
		dlg.m_bInsLife, dlg.m_bInsDis, dlg.m_bInsMed, dlg.m_strBio); 
	TRACE("loyalty = %d, reliability = %d\n", 
		dlg.m_nLoyal, dlg.m_nRely); 
}
