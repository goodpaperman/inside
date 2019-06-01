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
	ON_COMMAND(IDC_CLEAR, OnClear)
	ON_COMMAND(ID_STUDENT_HOME, OnCommandHome)
	ON_COMMAND(ID_STUDENT_END, OnCommandEnd)
	ON_COMMAND(ID_STUDENT_NEXT, OnCommandNext)
	ON_COMMAND(ID_STUDENT_PREV, OnCommandPrev)
	ON_COMMAND(ID_STUDENT_INS, OnCommandIns)
	ON_COMMAND(ID_STUDENT_DEL, OnCommandDel)
	ON_UPDATE_COMMAND_UI(ID_STUDENT_HOME, OnUpdateCommandHome)
	ON_UPDATE_COMMAND_UI(ID_STUDENT_END, OnUpdateCommandEnd)
	ON_UPDATE_COMMAND_UI(ID_STUDENT_NEXT, OnUpdateCommandEnd)
	ON_UPDATE_COMMAND_UI(ID_STUDENT_PREV, OnUpdateCommandHome)
	ON_UPDATE_COMMAND_UI(ID_STUDENT_DEL, OnUpdateCommandDel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoView construction/destruction

CDemoView::CDemoView()
	: CFormView(CDemoView::IDD)
{
	TRACE("Entering CDemoView constructor\n"); 
	//{{AFX_DATA_INIT(CDemoView)
	m_nGrade = 0;
	m_strName = _T("");
	//}}AFX_DATA_INIT
	// TODO: add construction code here

	m_position = NULL; 
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
	DDV_MaxChars(pDX, m_strName, 20); 
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
	TRACE("Entering CDemoView::OnInitialUpdate\n"); 
	m_pList = GetDocument()->GetList(); 
	//UpdateControlsFromDoc(); 

	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
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

//void CDemoView::OnEnter() 
//{
//    // TODO: Add your control notification handler code here
//    CDemoDoc* pDoc = GetDocument(); 
//    UpdateData(TRUE); 
//    pDoc->m_student.m_nGrade = m_nGrade; 
//    pDoc->m_student.m_strName = m_strName; 
//}

//void CDemoView::OnEditClearAll() 
//{
//    // TODO: Add your command handler code here
//    GetDocument()->m_student = CStudent(); 
//    UpdateControlsFromDoc(); 
//}

//void CDemoView::OnUpdateEditClearAll(CCmdUI* pCmdUI) 
//{
//    // TODO: Add your command update UI handler code here
//    pCmdUI->Enable(GetDocument()->m_student != CStudent()); 
//}

//void CDemoView::UpdateControlsFromDoc()
//{
//    CDemoDoc* pDoc = GetDocument(); 
//    m_nGrade = pDoc->m_student.m_nGrade; 
//    m_strName = pDoc->m_student.m_strName; 
//    UpdateData(FALSE); 
//}

void CDemoView::OnClear() 
{
	// TODO: Add your command handler code here
	TRACE("Entering CDemoView::OnClear\n"); 
	ClearEntry(); 
}

void CDemoView::ClearEntry()
{
	m_strName = ""; 
	m_nGrade = 0; 
	UpdateData(FALSE); 
	((CDialog*)this)->GotoDlgCtrl(GetDlgItem(IDC_NAME)); 
}

void CDemoView::OnCommandHome() 
{
	// TODO: Add your command handler code here
	TRACE("Entering CDemoView::OnCommandHome\n"); 
	if(!m_pList->IsEmpty())
	{
		m_position = m_pList->GetHeadPosition(); 
		GetEntry(m_position); 
	}
}

void CDemoView::GetEntry(POSITION position)
{
	if(position)
	{
		CStudent* pStudent = m_pList->GetAt(position); 
		m_strName = pStudent->m_strName; 
		m_nGrade = pStudent->m_nGrade; 
		UpdateData(FALSE); 
	}
	else 
		ClearEntry(); 
}

void CDemoView::OnUpdateCommandHome(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	POSITION pos = m_pList->GetHeadPosition(); 
	pCmdUI->Enable((m_position != NULL) && (pos != m_position)); 
}

void CDemoView::OnCommandEnd() 
{
	// TODO: Add your command handler code here
	TRACE("Entering CDemoView::OnCommandEnd\n"); 
	if(!m_pList->IsEmpty())
	{
		m_position = m_pList->GetTailPosition(); 
		GetEntry(m_position); 
	}
}

void CDemoView::OnUpdateCommandEnd(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	POSITION pos = m_pList->GetTailPosition(); 
	pCmdUI->Enable((m_position!=NULL) && (m_position != pos)); 
}

void CDemoView::OnCommandNext() 
{
	// TODO: Add your command handler code here
	POSITION pos; 
	TRACE("Entering CDemoView::OnCommandNext\n"); 
	if((pos = m_position) != NULL)
	{
		m_pList->GetNext(pos); 
		if(pos)
		{
			GetEntry(pos); 
			m_position = pos; 
		}
	}
}

void CDemoView::OnCommandPrev() 
{
	// TODO: Add your command handler code here
	POSITION pos = m_position; 
	TRACE("Entering CDemoView::OnCommandPrev\n"); 
	if(pos != NULL)
	{
		m_pList->GetPrev(pos); 
		if(pos)
		{
			GetEntry(pos); 
			m_position = pos; 
		}
	}
}

void CDemoView::OnCommandIns() 
{
	// TODO: Add your command handler code here
	TRACE("Entering CDemoView::OnCommandIns\n"); 
	InsertEntry(m_position); 
	GetDocument()->SetModifiedFlag(); 
	GetDocument()->UpdateAllViews(this); 
}

void CDemoView::InsertEntry(POSITION position)
{
	if(UpdateData(TRUE))
	{
		CStudent* pStudent = new CStudent; 
		pStudent->m_strName = m_strName; 
		pStudent->m_nGrade = m_nGrade; 
		m_position = m_pList->InsertAfter(m_position, pStudent); 
	}
}

void CDemoView::OnCommandDel() 
{
	// TODO: Add your command handler code here
	POSITION pos = m_position; 
	TRACE("Entering CDemoView::OnCommandDel\n"); 
	if(pos != NULL)
	{
		m_pList->GetNext(pos); 
		if(pos == NULL)
		{
			pos = m_pList->GetHeadPosition(); 
			if(pos == m_position)
				pos = NULL; 
		}

		GetEntry(pos); 
		CStudent* ps = m_pList->GetAt(m_position); 
		m_pList->RemoveAt(m_position); 
		delete ps; 
		m_position = pos; 
		GetDocument()->SetModifiedFlag(); 
		GetDocument()->UpdateAllViews(this); 
	}
}

void CDemoView::OnUpdateCommandDel(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_position != NULL); 
}

void CDemoView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	TRACE("Entering CDemoView::OnUpdate\n"); 
	m_position = m_pList->GetHeadPosition(); 
	GetEntry(m_position); 	
}
