// Ex32bView.cpp : implementation of the CEx32bView class
//

#include "stdafx.h"
#include "Ex32b.h"

#include "Ex32bDoc.h"
#include "CntrItem.h"
#include "Ex32bView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx32bView

IMPLEMENT_DYNCREATE(CEx32bView, CValidForm)

BEGIN_MESSAGE_MAP(CEx32bView, CValidForm)
	//{{AFX_MSG_MAP(CEx32bView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	ON_WM_DESTROY()
	ON_WM_SETFOCUS()
	ON_WM_SIZE()
	ON_COMMAND(ID_OLE_INSERT_NEW, OnInsertObject)
	ON_COMMAND(ID_CANCEL_EDIT_CNTR, OnCancelEditCntr)
	ON_COMMAND(ID_CANCEL_EDIT_SRVR, OnCancelEditSrvr)
	//}}AFX_MSG_MAP
    ON_COMMAND(IDCANCEL, OnCancel) 
    ON_COMMAND(IDC_SUBMIT, OnSubmit) 
    ON_MESSAGE(WM_POSTCOMPLETE, OnPostComplete) 
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx32bView construction/destruction

CEx32bView::CEx32bView()
	: CValidForm(CEx32bView::IDD)
{
	//{{AFX_DATA_INIT(CEx32bView)
	m_dHours = 0.0;
	m_nJob = 0;
	m_strName = _T("");
	m_nPeriod = 0;
	//}}AFX_DATA_INIT
	m_pSelection = NULL;
	// TODO: add construction code here

}

CEx32bView::~CEx32bView()
{
}

void CEx32bView::DoDataExchange(CDataExchange* pDX)
{
	CValidForm::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEx32bView)
	DDX_Text(pDX, IDC_HOURS, m_dHours);
	DDV_MinMaxDouble(pDX, m_dHours, 0.1, 100.);
	DDX_Text(pDX, IDC_JOB, m_nJob);
	DDV_MinMaxInt(pDX, m_nJob, 1, 20);
	DDX_CBString(pDX, IDC_NAME, m_strName);
	DDV_MaxChars(pDX, m_strName, 10);
	DDX_Text(pDX, IDC_PERIOD, m_nPeriod);
	//}}AFX_DATA_MAP
}

void CEx32bView::ValidateDlgItem(CDataExchange* pDX, UINT nID)
{
    ASSERT(this); 
    switch(nID)
    {
    case IDC_NAME:
        DDX_CBString(pDX, IDC_NAME, m_strName); 
        DDV_MaxChars(pDX, m_strName, 10); 
        if(m_strName.IsEmpty())
        {
            AfxMessageBox("Must supply an employee name"); 
            pDX->Fail(); 
        }
        break; 
    case IDC_HOURS:
        DDX_Text(pDX, IDC_HOURS, m_dHours); 
        DDV_MinMaxDouble(pDX, m_dHours, 0.1, 100.); 
        break; 
    case IDC_JOB:
        DDX_Text(pDX, IDC_JOB, m_nJob); 
        DDV_MinMaxInt(pDX, m_nJob, 1, 20); 
        break; 
    default:
        break; 
    }
}

BOOL CEx32bView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CValidForm::PreCreateWindow(cs);
}

void CEx32bView::OnInitialUpdate()
{
	CValidForm::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();


	// TODO: remove this code when final selection model code is written
	m_pSelection = NULL;    // initialize selection

	//Active documents should always be activated
	COleDocument* pDoc = (COleDocument*) GetDocument();
	if (pDoc != NULL)
	{
		// activate the first one
		POSITION posItem = pDoc->GetStartPosition();
		if (posItem != NULL)
		{
			CDocItem* pItem = pDoc->GetNextItem(posItem);

			// only if it's an Active document
			COleDocObjectItem *pDocObjectItem =
				DYNAMIC_DOWNCAST(COleDocObjectItem, pItem);

			if (pDocObjectItem != NULL)
			{
				pDocObjectItem->DoVerb(OLEIVERB_SHOW, this);
			}
		}
	}
}

void CEx32bView::OnDestroy()
{
	// Deactivate the item on destruction; this is important
	// when a splitter view is being used.
   CValidForm::OnDestroy();
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != NULL && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
   }
}


/////////////////////////////////////////////////////////////////////////////
// OLE Client support and commands

BOOL CEx32bView::IsSelected(const CObject* pDocItem) const
{
	// The implementation below is adequate if your selection consists of
	//  only CEx32bCntrItem objects.  To handle different selection
	//  mechanisms, the implementation here should be replaced.

	// TODO: implement this function that tests for a selected OLE client item

	return pDocItem == m_pSelection;
}

void CEx32bView::OnInsertObject()
{
	// Invoke the standard Insert Object dialog box to obtain information
	//  for new CEx32bCntrItem object.
	COleInsertDialog dlg;
	if (dlg.DoModal(COleInsertDialog::DocObjectsOnly) != IDOK)
		return;

	BeginWaitCursor();

	CEx32bCntrItem* pItem = NULL;
	TRY
	{
		// Create new item connected to this document.
		CEx32bDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pItem = new CEx32bCntrItem(pDoc);
		ASSERT_VALID(pItem);

		// Initialize the item from the dialog data.
		if (!dlg.CreateItem(pItem))
			AfxThrowMemoryException();  // any exception will do
		ASSERT_VALID(pItem);
		
		pItem->DoVerb(OLEIVERB_SHOW, this);

		ASSERT_VALID(pItem);

		// As an arbitrary user interface design, this sets the selection
		//  to the last item inserted.

		// TODO: reimplement selection as appropriate for your application

		m_pSelection = pItem;   // set selection to last inserted item
		pDoc->UpdateAllViews(NULL);
	}
	CATCH(CException, e)
	{
		if (pItem != NULL)
		{
			ASSERT_VALID(pItem);
			pItem->Delete();
		}
		AfxMessageBox(IDP_FAILED_TO_CREATE);
	}
	END_CATCH

	EndWaitCursor();
}

// The following command handler provides the standard keyboard
//  user interface to cancel an in-place editing session.  Here,
//  the container (not the server) causes the deactivation.
void CEx32bView::OnCancelEditCntr()
{
	// Close any in-place active item on this view.
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL)
	{
		pActiveItem->Close();
	}
	ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
}

// Special handling of OnSetFocus and OnSize are required for a container
//  when an object is being edited in-place.
void CEx32bView::OnSetFocus(CWnd* pOldWnd)
{
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL &&
		pActiveItem->GetItemState() == COleClientItem::activeUIState)
	{
		// need to set focus to this item if it is in the same view
		CWnd* pWnd = pActiveItem->GetInPlaceWindow();
		if (pWnd != NULL)
		{
			pWnd->SetFocus();   // don't call the base class
			return;
		}
	}

	CValidForm::OnSetFocus(pOldWnd);
}

void CEx32bView::OnSize(UINT nType, int cx, int cy)
{
	CValidForm::OnSize(nType, cx, cy);
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL)
		pActiveItem->SetItemRects();
}

/////////////////////////////////////////////////////////////////////////////
// OLE Server support

// The following command handler provides the standard keyboard
//  user interface to cancel an in-place editing session.  Here,
//  the server (not the container) causes the deactivation.
void CEx32bView::OnCancelEditSrvr()
{
	GetDocument()->OnDeactivateUI(FALSE);
}

/////////////////////////////////////////////////////////////////////////////
// CEx32bView diagnostics

#ifdef _DEBUG
void CEx32bView::AssertValid() const
{
	CValidForm::AssertValid();
}

void CEx32bView::Dump(CDumpContext& dc) const
{
	CValidForm::Dump(dc);
}

CEx32bDoc* CEx32bView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx32bDoc)));
	return (CEx32bDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx32bView message handlers

void CEx32bView::OnCancel()
{
    m_dHours = 0; 
    m_strName = ""; 
    m_nJob = 0; 
    m_nPeriod = 0; 
    UpdateData(FALSE); 
}

extern CString g_strParameters; 
extern UINT PostThreadProc(LPVOID pParam); 

void CEx32bView::OnSubmit()
{
    if(UpdateData(TRUE))
    {
        GetDlgItem(IDC_SUBMIT)->EnableWindow(FALSE);
        CString strHours, strJob, strPeriod; 
        strPeriod.Format("%d", m_nPeriod); 
        strHours.Format("%3.2f", m_dHours); 
        strJob.Format("%d", m_nJob); 
        g_strParameters = "Period = " + strPeriod + 
            "&Employee = " + m_strName + 
            "&Hours = " + strHours + 
            "&Job = " + strJob + "\r\n"; 
        AfxBeginThread(PostThreadProc, GetSafeHwnd(), THREAD_PRIORITY_NORMAL); 
    }
}

LONG CEx32bView::OnPostComplete(UINT wParam, LONG lParam)
{
    if(wParam == 0)
        AfxMessageBox("Server did not accept the transaction"); 
    else 
        OnCancel(); 

    GetDlgItem(IDC_SUBMIT)->EnableWindow(TRUE); 
    return 0; 
}