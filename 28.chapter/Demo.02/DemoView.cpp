// DemoView.cpp : implementation of the CDemoView class
//

#include "stdafx.h"
#include "Demo.h"

#include "DemoSet.h"
#include "DemoDoc.h"
#include "DemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoView

IMPLEMENT_DYNCREATE(CDemoView, CRecordView)

BEGIN_MESSAGE_MAP(CDemoView, CRecordView)
	//{{AFX_MSG_MAP(CDemoView)
	ON_COMMAND(ID_RECORD_ADD, OnRecordAdd)
	ON_COMMAND(ID_RECORD_CLEARFIELDS, OnRecordClearfields)
	ON_COMMAND(ID_RECORD_DELETE, OnRecordDelete)
	ON_UPDATE_COMMAND_UI(ID_RECORD_DELETE, OnUpdateRecordDelete)
	ON_COMMAND(ID_RECORD_UPDATE, OnRecordUpdate)
	ON_UPDATE_COMMAND_UI(ID_RECORD_UPDATE, OnUpdateRecordUpdate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoView construction/destruction

CDemoView::CDemoView()
	: CRecordView(CDemoView::IDD)
{
	//{{AFX_DATA_INIT(CDemoView)
	m_pSet = NULL;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CDemoView::~CDemoView()
{
}

void CDemoView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDemoView)
	DDX_FieldText(pDX, IDC_ID, m_pSet->m_InstructorID, m_pSet);
	DDX_FieldText(pDX, IDC_NAME, m_pSet->m_Name, m_pSet);
	DDX_FieldText(pDX, IDC_ROOM, m_pSet->m_RoomNo, m_pSet);
	//}}AFX_DATA_MAP
}

BOOL CDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CDemoView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_demoSet;
	CRecordView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CDemoView diagnostics

#ifdef _DEBUG
void CDemoView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDemoView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDemoDoc* CDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDemoDoc)));
	return (CDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDemoView database support
CRecordset* CDemoView::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// CDemoView message handlers

void CDemoView::OnRecordAdd() 
{
	// TODO: Add your command handler code here
	m_pSet->AddNew(); 
    UpdateData(TRUE); 
    if(m_pSet->CanUpdate())
        m_pSet->Update(); 

    if(!m_pSet->IsEOF())
        m_pSet->MoveLast(); 

    m_pSet->Requery(); 
    UpdateData(FALSE); 
}

void CDemoView::OnRecordClearfields() 
{
	// TODO: Add your command handler code here
	m_pSet->SetFieldNull(NULL); 
    UpdateData(FALSE); 
}

void CDemoView::OnRecordDelete() 
{
	// TODO: Add your command handler code here
	CRecordsetStatus status; 
    try
    {
        m_pSet->Delete(); 
    }
    catch(CDBException* e)
    {
        AfxMessageBox(e->m_strError); 
        e->Delete(); 
        m_pSet->MoveFirst(); 
        UpdateData(FALSE); 
        return; 
    }

    m_pSet->GetStatus(status); 
    if(status.m_lCurrentRecord == 0)
        m_pSet->MoveFirst(); 
    else 
        m_pSet->MoveNext(); 

    UpdateData(FALSE); 
}

void CDemoView::OnUpdateRecordDelete(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(!m_pSet->IsEOF()); 
}

void CDemoView::OnRecordUpdate() 
{
	// TODO: Add your command handler code here
	m_pSet->Edit(); 
    UpdateData(TRUE); 
    if(m_pSet->CanUpdate())
        m_pSet->Update(); 
}

void CDemoView::OnUpdateRecordUpdate(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
    pCmdUI->Enable(!m_pSet->IsEOF()); 	
}

BOOL CDemoView::OnMove(UINT nIDMoveCommand) 
{
	// TODO: Add your specialized code here and/or call the base class
	switch(nIDMoveCommand)
    {
        case ID_RECORD_PREV:
            m_pSet->MovePrev(); 
            if(!m_pSet->IsBOF())
                break; 
        case ID_RECORD_FIRST:
            m_pSet->MoveFirst(); 
            break; 
        case ID_RECORD_NEXT:
            m_pSet->MoveNext(); 
            if(!m_pSet->IsEOF())
                break; 
            if(!m_pSet->CanScroll())
            {
                m_pSet->SetFieldNull(NULL); 
                break; 
            }
        case ID_RECORD_LAST:
            m_pSet->MoveLast(); 
            break; 
        default:
            ASSERT(FALSE); 
    }
    
    UpdateData(FALSE); 
    return TRUE; 
}
