// DemoView.cpp : implementation of the CDemoView class
//

#include "stdafx.h"
#include "Demo.h"

#include "DemoDoc.h"
#include "CntrItem.h"
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
    //ON_WM_DESTROY()
    //ON_WM_SETFOCUS()
    //ON_WM_SIZE()
    //ON_COMMAND(ID_CANCEL_EDIT_CNTR, OnCancelEditCntr)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, OnUpdateEditCopy)
	ON_COMMAND(ID_EDIT_COPY_TO, OnEditCopyTo)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY_TO, OnUpdateEditCopy)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, OnUpdateEditCopy)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, OnUpdateEditPaste)
	ON_COMMAND(ID_EDIT_PASTE_FROM, OnEditPasteFrom)
	ON_COMMAND(ID_OLE_INSERT_NEW, OnEditInsertObject)
	ON_UPDATE_COMMAND_UI(ID_OLE_INSERT_NEW, OnUpdateEditInsertObject)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoView construction/destruction

CDemoView::CDemoView() : m_sizeTotal(20000, 25000), 
						 m_rectTracker(0, 0, 0, 0) 
{
	//m_pSelection = NULL;
	// TODO: add construction code here
	m_cfObjDesc = ::RegisterClipboardFormat(CF_OBJECTDESCRIPTOR); 
	m_cfEmbedded = ::RegisterClipboardFormat(CF_EMBEDDEDOBJECT); 
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
	// TODO: also draw all OLE items in the document

	// Draw the selection at an arbitrary position.  This code should be
	//  removed once your real drawing code is implemented.  This position
	//  corresponds exactly to the rectangle returned by CDemoCntrItem,
	//  to give the effect of in-place editing.

	// TODO: remove this code when final draw code is complete.
	if(pDoc->m_lpOleObj != NULL)
		VERIFY(::OleDraw(pDoc->m_lpOleObj, DVASPECT_CONTENT, pDC->GetSafeHdc(), m_rectTracker) == S_OK); 

	m_tracker.m_rect = m_rectTracker; 
	pDC->LPtoDP(m_tracker.m_rect); 
	if(pDoc->m_bHatch)
		m_tracker.m_nStyle |= CRectTracker::hatchInside; 
	else 
		m_tracker.m_nStyle &= ~CRectTracker::hatchInside; 

	m_tracker.Draw(pDC); 

    //if (m_pSelection == NULL)
    //{
    //    POSITION pos = pDoc->GetStartPosition();
    //    m_pSelection = (CDemoCntrItem*)pDoc->GetNextClientItem(pos);
    //}
    //if (m_pSelection != NULL)
    //    m_pSelection->Draw(pDC, CRect(10, 10, 210, 210));
}

void CDemoView::OnInitialUpdate()
{
	//CScrollView::OnInitialUpdate();


	// TODO: remove this code when final selection model code is written
	//m_pSelection = NULL;    // initialize selection

    //CSize sizeTotal;
    //// TODO: calculate the total size of this view
    //sizeTotal.cx = sizeTotal.cy = 100;
    //SetScrollSizes(MM_TEXT, sizeTotal);

	m_rectTracker = CRect(1000, -1000, 5000, -5000); 
	m_tracker.m_nStyle = CRectTracker::solidLine | CRectTracker::resizeOutside; 
	SetScrollSizes(MM_HIMETRIC, m_sizeTotal); 
	CScrollView::OnInitialUpdate(); 
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView printing

BOOL CDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	pInfo->SetMaxPage(1);
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

//void CDemoView::OnDestroy()
//{
//    // Deactivate the item on destruction; this is important
//    // when a splitter view is being used.
//   CScrollView::OnDestroy();
//   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
//   if (pActiveItem != NULL && pActiveItem->GetActiveView() == this)
//   {
//      pActiveItem->Deactivate();
//      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
//   }
//}


/////////////////////////////////////////////////////////////////////////////
// OLE Client support and commands

//BOOL CDemoView::IsSelected(const CObject* pDocItem) const
//{
//    // The implementation below is adequate if your selection consists of
//    //  only CDemoCntrItem objects.  To handle different selection
//    //  mechanisms, the implementation here should be replaced.

//    // TODO: implement this function that tests for a selected OLE client item

//    return pDocItem == m_pSelection;
//}

//void CDemoView::OnInsertObject()
//{
//    // Invoke the standard Insert Object dialog box to obtain information
//    //  for new CDemoCntrItem object.
//    COleInsertDialog dlg;
//    if (dlg.DoModal() != IDOK)
//        return;

//    BeginWaitCursor();

//    CDemoCntrItem* pItem = NULL;
//    TRY
//    {
//        // Create new item connected to this document.
//        CDemoDoc* pDoc = GetDocument();
//        ASSERT_VALID(pDoc);
//        pItem = new CDemoCntrItem(pDoc);
//        ASSERT_VALID(pItem);

//        // Initialize the item from the dialog data.
//        if (!dlg.CreateItem(pItem))
//            AfxThrowMemoryException();  // any exception will do
//        ASSERT_VALID(pItem);
        
//        if (dlg.GetSelectionType() == COleInsertDialog::createNewItem)
//            pItem->DoVerb(OLEIVERB_SHOW, this);

//        ASSERT_VALID(pItem);

//        // As an arbitrary user interface design, this sets the selection
//        //  to the last item inserted.

//        // TODO: reimplement selection as appropriate for your application

//        m_pSelection = pItem;   // set selection to last inserted item
//        pDoc->UpdateAllViews(NULL);
//    }
//    CATCH(CException, e)
//    {
//        if (pItem != NULL)
//        {
//            ASSERT_VALID(pItem);
//            pItem->Delete();
//        }
//        AfxMessageBox(IDP_FAILED_TO_CREATE);
//    }
//    END_CATCH

//    EndWaitCursor();
//}

// The following command handler provides the standard keyboard
//  user interface to cancel an in-place editing session.  Here,
//  the container (not the server) causes the deactivation.
//void CDemoView::OnCancelEditCntr()
//{
//    // Close any in-place active item on this view.
//    COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
//    if (pActiveItem != NULL)
//    {
//        pActiveItem->Close();
//    }
//    ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
//}

//// Special handling of OnSetFocus and OnSize are required for a container
////  when an object is being edited in-place.
//void CDemoView::OnSetFocus(CWnd* pOldWnd)
//{
//    COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
//    if (pActiveItem != NULL &&
//        pActiveItem->GetItemState() == COleClientItem::activeUIState)
//    {
//        // need to set focus to this item if it is in the same view
//        CWnd* pWnd = pActiveItem->GetInPlaceWindow();
//        if (pWnd != NULL)
//        {
//            pWnd->SetFocus();   // don't call the base class
//            return;
//        }
//    }

//    CScrollView::OnSetFocus(pOldWnd);
//}

//void CDemoView::OnSize(UINT nType, int cx, int cy)
//{
//    CScrollView::OnSize(nType, cx, cy);
//    COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
//    if (pActiveItem != NULL)
//        pActiveItem->SetItemRects();
//}

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

void CDemoView::OnEditCopy() 
{
	// TODO: Add your command handler code here
	COleDataSource* pSource = SaveObject(); 
	if(pSource)
		pSource->SetClipboard(); 
}

void CDemoView::OnUpdateEditCopy(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(GetDocument()->m_lpOleObj != NULL); 
}

void CDemoView::OnEditCopyTo() 
{
	// TODO: Add your command handler code here
	CFileDialog dlg(FALSE, "stg", "*.stg"); 
	if(dlg.DoModal() != IDOK)
		return; 

	CDemoDoc* pDoc = GetDocument(); 
	LPSTORAGE pStgRoot; 
	VERIFY(::StgCreateDocfile(dlg.GetPathName().AllocSysString(), 
		STGM_READWRITE | STGM_SHARE_EXCLUSIVE | STGM_CREATE, 0, &pStgRoot) == S_OK); 
	ASSERT(pStgRoot != NULL); 

	LPSTORAGE pStgSub; 
	VERIFY(pStgRoot->CreateStorage(CDemoDoc::s_szSub, 
		STGM_CREATE | STGM_READWRITE | STGM_SHARE_EXCLUSIVE, 0, 0, &pStgSub) == S_OK); 
	ASSERT(pStgSub != NULL); 

	LPPERSISTSTORAGE pPS = NULL; 
	VERIFY(pDoc->m_lpOleObj->QueryInterface(IID_IPersistStorage, (void**)&pPS) == S_OK); 
	VERIFY(::OleSave(pPS, pStgSub, FALSE) == S_OK); 
	pPS->SaveCompleted(NULL); 
	pPS->Release(); 

	pStgSub->Release(); 
	pStgRoot->Release(); 
}

void CDemoView::OnEditCut() 
{
	// TODO: Add your command handler code here
	OnEditCopy(); 
	GetDocument()->OnEditClearAll(); 
}

void CDemoView::OnEditPaste() 
{
	// TODO: Add your command handler code here
	CDemoDoc* pDoc = GetDocument(); 
	COleDataObject dataObject; 
	VERIFY(dataObject.AttachClipboard()); 
	pDoc->DeleteContents(); 
	DoPasteObjectDescriptor(&dataObject);
	DoPasteObject(&dataObject); 
	SetViewAdvise(); 
	GetSize(); 
	pDoc->SetModifiedFlag(); 
	pDoc->UpdateAllViews(NULL); 
}

void CDemoView::OnUpdateEditPaste(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	COleDataObject dataObject; 
	if(dataObject.AttachClipboard() && dataObject.IsDataAvailable(m_cfEmbedded))
		pCmdUI->Enable(TRUE); 
	else 
		pCmdUI->Enable(FALSE); 
}

void CDemoView::OnEditPasteFrom() 
{
	// TODO: Add your command handler code here
	CDemoDoc* pDoc = GetDocument(); 
	CFileDialog dlg(TRUE, "stg", "*.stg"); 
	if(dlg.DoModal() != IDOK)
		return; 

	LPSTORAGE pStgRoot; 
	VERIFY(::StgOpenStorage(dlg.GetPathName().AllocSysString(), NULL, 
		STGM_READ | STGM_SHARE_EXCLUSIVE, NULL, 0, &pStgRoot) == S_OK); 
	ASSERT(pStgRoot != NULL); 

	LPSTORAGE pStgSub; 
	VERIFY(pStgRoot->OpenStorage(CDemoDoc::s_szSub, NULL, 
		STGM_READ | STGM_SHARE_EXCLUSIVE, NULL, 0, &pStgSub)); 
	ASSERT(pStgSub != NULL); 

	VERIFY(pStgSub->CopyTo(NULL, NULL, NULL, pDoc->m_pTempStgRoot)); 
	LPOLECLIENTSITE pClientSite = (LPOLECLIENTSITE)pDoc->GetInterface(&IID_IOleClientSite); 
	ASSERT(pClientSite != NULL);
	pDoc->DeleteContents(); 

	VERIFY(::OleLoad(pDoc->m_pTempStgSub, IID_IOleObject, pClientSite, (void**)&pDoc->m_lpOleObj) == S_OK); 
	SetViewAdvise(); 
	pStgSub->Release(); 
	pStgRoot->Release(); 
	GetSize(); 
	pDoc->SetModifiedFlag(); 
	pDoc->UpdateAllViews(NULL); 
}

void CDemoView::OnEditInsertObject()
{
	CDemoDoc* pDoc = GetDocument(); 
	COleInsertDialog dlg; 
	if(dlg.DoModal() == IDCANCEL)
		return; 

	LPOLECLIENTSITE pClientSite = (LPOLECLIENTSITE)pDoc->GetInterface(&IID_IOleClientSite); 
	ASSERT(pClientSite != NULL); 
	pDoc->DeleteContents(); 
	VERIFY(::OleCreate(dlg.GetClassID(), IID_IOleObject, OLERENDER_DRAW, NULL, 
		pClientSite, pDoc->m_pTempStgSub, (void**)&pDoc->m_lpOleObj) == S_OK); 
	SetViewAdvise(); 

	pDoc->m_lpOleObj->DoVerb(OLEIVERB_SHOW, NULL, pClientSite, 0, NULL, NULL); 
	SetNames(); 
	pDoc->SetModifiedFlag(); 
	GetSize(); 
	pDoc->UpdateAllViews(NULL); 
}

void CDemoView::OnUpdateEditInsertObject(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(GetDocument()->m_lpOleObj == NULL); 
}

void CDemoView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_tracker.Track(this, point, FALSE, NULL))
	{
		CClientDC dc(this); 
		OnPrepareDC(&dc); 
		m_rectTracker = m_tracker.m_rect; 
		dc.DPtoLP(m_rectTracker);
		GetDocument()->UpdateAllViews(NULL); 
	}

	CScrollView::OnLButtonDown(nFlags, point);
}

void CDemoView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_tracker.HitTest(point) == CRectTracker::hitNothing)
		return; 

	CDemoDoc* pDoc = GetDocument(); 
	if(pDoc->m_lpOleObj != NULL)
	{
		LPOLECLIENTSITE pClientSite = (LPOLECLIENTSITE)pDoc->GetInterface(&IID_IOleClientSite); 
		ASSERT(pClientSite != NULL); 
		VERIFY(pDoc->m_lpOleObj->DoVerb(OLEIVERB_OPEN, NULL, pClientSite, 0, GetSafeHwnd(), CRect(0, 0, 0, 0)) == S_OK); 
		SetNames(); 
		pDoc->SetModifiedFlag(); 
	}

	//CScrollView::OnLButtonDblClk(nFlags, point);
}

BOOL CDemoView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_tracker.SetCursor(pWnd, nHitTest))
		return TRUE; 
	else 
		return CScrollView::OnSetCursor(pWnd, nHitTest, message);
}


void CDemoView::SetViewAdvise()
{
	CDemoDoc* pDoc = GetDocument(); 
	if(pDoc->m_lpOleObj != NULL) 
	{
		LPVIEWOBJECT2 pViewObj; 
		pDoc->m_lpOleObj->QueryInterface(IID_IViewObject2, (void**)&pViewObj); 
		LPADVISESINK pAdviseSink = (LPADVISESINK)pDoc->GetInterface(&IID_IAdviseSink); 
		VERIFY(pViewObj->SetAdvise(DVASPECT_CONTENT, 0, pAdviseSink) == S_OK); 
		pViewObj->Release();  
	}
}

void CDemoView::SetNames()
{
	CDemoDoc* pDoc = GetDocument(); 
	CString strApp = AfxGetApp()->m_pszAppName; 
	if(pDoc->m_lpOleObj != NULL)
		pDoc->m_lpOleObj->SetHostNames(strApp.AllocSysString(), NULL); 
}

void CDemoView::GetSize()
{
	CDemoDoc* pDoc = GetDocument(); 
	if(pDoc->m_lpOleObj != NULL)
	{
		SIZEL size; 
		pDoc->m_lpOleObj->GetExtent(DVASPECT_CONTENT, &size); 
		m_rectTracker.right = m_rectTracker.left + size.cx; 
		m_rectTracker.bottom = m_rectTracker.top - size.cy; 
	}
}

BOOL CDemoView::DoPasteObject(COleDataObject* pDataObject)
{
	if(!pDataObject->IsDataAvailable(m_cfEmbedded))
		return FALSE; 

	CDemoDoc* pDoc = GetDocument(); 
	LPOLECLIENTSITE pClientSite = (LPOLECLIENTSITE)pDoc->GetInterface(&IID_IOleClientSite); 
	ASSERT(pClientSite != NULL); 
	VERIFY(::OleCreateFromData(pDataObject->m_lpDataObject, IID_IOleObject, OLERENDER_DRAW, 
		NULL, pClientSite, pDoc->m_pTempStgSub, (void**)&pDoc->m_lpOleObj) == S_OK); 
	return TRUE; 
}

BOOL CDemoView::DoPasteObjectDescriptor(COleDataObject* pDataObject)
{
	STGMEDIUM stg; 
	FORMATETC fmt; 
	CDemoDoc* pDoc = GetDocument(); 
	if(!pDataObject->IsDataAvailable(m_cfObjDesc))
		return FALSE; 

	SETFORMATETC(fmt, m_cfObjDesc, DVASPECT_CONTENT, NULL, TYMED_HGLOBAL, -1); 
	VERIFY(pDataObject->GetData(m_cfObjDesc, &stg, &fmt)); 
	return TRUE; 
}

COleDataSource* CDemoView::SaveObject()
{
	CDemoDoc* pDoc = GetDocument(); 
	if(pDoc->m_lpOleObj != NULL)
	{
		COleDataSource* pSource = new COleDataSource(); 
		FORMATETC fmte; 
		SETFORMATETC(fmte, m_cfEmbedded, DVASPECT_CONTENT, NULL, TYMED_ISTORAGE, -1); 
		STGMEDIUM stgm; 
		stgm.tymed = TYMED_ISTORAGE; 
		stgm.pstg = pDoc->m_pTempStgSub; 
		stgm.pUnkForRelease = NULL; 
		pDoc->m_pTempStgSub->AddRef(); 
		pDoc->m_pTempStgRoot->AddRef(); 
		pSource->CacheData(m_cfEmbedded, &stgm, &fmte); 

		MakeMetafilePict(pSource); 

		HGLOBAL hObjDesc = ::GlobalAlloc(GMEM_SHARE, sizeof(OBJECTDESCRIPTOR)); 
		LPOBJECTDESCRIPTOR pObjDesc = (LPOBJECTDESCRIPTOR)::GlobalLock(hObjDesc); 
		pObjDesc->cbSize = sizeof(OBJECTDESCRIPTOR); 
		pObjDesc->clsid  = CLSID_NULL; 
		pObjDesc->dwDrawAspect = 0; 
		pObjDesc->dwStatus = 0; 
		pObjDesc->dwFullUserTypeName = 0; 
		pObjDesc->dwSrcOfCopy = 0; 
		pObjDesc->sizel.cx = 0; 
		pObjDesc->sizel.cy = 0; 
		pObjDesc->pointl.x = 0; 
		pObjDesc->pointl.y = 0; 
		::GlobalUnlock(hObjDesc); 
		pSource->CacheGlobalData(m_cfObjDesc, hObjDesc); 
		return pSource; 
	}

	return NULL; 
}

BOOL CDemoView::MakeMetafilePict(COleDataSource* pSource)
{
	CDemoDoc* pDoc = GetDocument(); 
	COleDataObject dataObject; 
	LPDATAOBJECT pDataObj; 
	VERIFY(pDoc->m_lpOleObj->QueryInterface(IID_IDataObject, (void**)&pDataObj) == S_OK); 
	dataObject.Attach(pDataObj); 
	FORMATETC fmtem; 
	SETFORMATETC(fmtem, CF_METAFILEPICT, DVASPECT_CONTENT, NULL, TYMED_MFPICT, -1); 
	if(!dataObject.IsDataAvailable(CF_METAFILEPICT, &fmtem))
		return FALSE; 

	STGMEDIUM stgmm; 
	VERIFY(dataObject.GetData(CF_METAFILEPICT, &stgmm, &fmtem)); 
	pSource->CacheData(CF_METAFILEPICT, &stgmm, &fmtem); 
	return TRUE; 
}