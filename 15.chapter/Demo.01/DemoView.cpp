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

IMPLEMENT_DYNCREATE(CDemoView, CFormView)

BEGIN_MESSAGE_MAP(CDemoView, CFormView)
	//{{AFX_MSG_MAP(CDemoView)
	ON_BN_CLICKED(IDC_ENTER, OnEnter)
	ON_COMMAND(ID_EDIT_CLEAR_ALL, OnEditClearAll)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CLEAR_ALL, OnUpdateEditClearAll)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoView construction/destruction

CDemoView::CDemoView()
	: CFormView(CDemoView::IDD)
{
	//{{AFX_DATA_INIT(CDemoView)
	m_nGrade = 0;
	m_strName = _T("");
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CDemoView::~CDemoView()
{
}

void CDemoView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDemoView)
	DDX_Text(pDX, IDC_GRADE, m_nGrade);
	DDV_MinMaxInt(pDX, m_nGrade, 0, 100);
	DDX_Text(pDX, IDC_NAME, m_strName);
	//}}AFX_DATA_MAP
}

BOOL CDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CDemoView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	UpdateControlsFromDoc(); 
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView diagnostics

#ifdef _DEBUG
void CDemoView::AssertValid() const
{
	CFormView::AssertValid();
}

void CDemoView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDemoDoc* CDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDemoDoc)));
	return (CDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDemoView message handlers

void CDemoView::OnEnter() 
{
	// TODO: Add your control notification handler code here
	CDemoDoc* pDoc = GetDocument(); 
	UpdateData(TRUE); 
	pDoc->m_student.m_nGrade = m_nGrade; 
	pDoc->m_student.m_strName = m_strName; 
}

void CDemoView::OnEditClearAll() 
{
	// TODO: Add your command handler code here
	GetDocument()->m_student = CStudent(); 
	UpdateControlsFromDoc(); 
}

void CDemoView::OnUpdateEditClearAll(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(GetDocument()->m_student != CStudent()); 
}

void CDemoView::UpdateControlsFromDoc()
{
	CDemoDoc* pDoc = GetDocument(); 
	m_nGrade = pDoc->m_student.m_nGrade; 
	m_strName = pDoc->m_student.m_strName; 
	UpdateData(FALSE); 
}