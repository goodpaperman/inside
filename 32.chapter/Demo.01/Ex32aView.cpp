// Ex32aView.cpp : implementation of the CEx32aView class
//

#include "stdafx.h"
#include "Ex32a.h"

#include "Ex32aDoc.h"
#include "CntrItem.h"
#include "Ex32aView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx32aView

IMPLEMENT_DYNCREATE(CEx32aView, CRichEditView)

BEGIN_MESSAGE_MAP(CEx32aView, CRichEditView)
	//{{AFX_MSG_MAP(CEx32aView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	ON_WM_DESTROY()
	ON_COMMAND(ID_CANCEL_EDIT_SRVR, OnCancelEditSrvr)
	//}}AFX_MSG_MAP
    ON_COMMAND(IDC_START, OnStart)
    ON_COMMAND(IDC_STOP, OnStop) 
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx32aView construction/destruction

CEx32aView::CEx32aView()
{
	// TODO: add construction code here

}

CEx32aView::~CEx32aView()
{
}

BOOL CEx32aView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRichEditView::PreCreateWindow(cs);
}

void CEx32aView::OnInitialUpdate()
{
	CRichEditView::OnInitialUpdate();

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

	// Set the printing margins (720 twips = 1/2 inch).
	SetMargins(CRect(720, 720, 720, 720));
}

void CEx32aView::OnDestroy()
{
	// Deactivate the item on destruction; this is important
	// when a splitter view is being used.
   CRichEditView::OnDestroy();
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != NULL && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
   }
}


/////////////////////////////////////////////////////////////////////////////
// OLE Server support

// The following command handler provides the standard keyboard
//  user interface to cancel an in-place editing session.  Here,
//  the server (not the container) causes the deactivation.
void CEx32aView::OnCancelEditSrvr()
{
	GetDocument()->OnDeactivateUI(FALSE);
}

/////////////////////////////////////////////////////////////////////////////
// CEx32aView diagnostics

#ifdef _DEBUG
void CEx32aView::AssertValid() const
{
	CRichEditView::AssertValid();
}

void CEx32aView::Dump(CDumpContext& dc) const
{
	CRichEditView::Dump(dc);
}

CEx32aDoc* CEx32aView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx32aDoc)));
	return (CEx32aDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx32aView message handlers

extern volatile BOOL g_bThreadStarted; 
extern CEvent g_eKill; 
extern UINT UrlThreadProc(LPVOID pParam); 

void CEx32aView::OnStart()
{
    if(!g_bThreadStarted)        
        AfxBeginThread(UrlThreadProc, GetSafeHwnd()); 
}

void CEx32aView::OnStop()
{
    if(g_bThreadStarted)
        g_eKill.SetEvent(); 
}