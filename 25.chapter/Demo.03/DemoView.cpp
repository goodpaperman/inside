// DemoView.cpp : implementation of the CDemoView class
//

#include "stdafx.h"
#include "Demo.h"

#include "DemoDoc.h"
#include "DemoView.h"
#include "cdib.h"

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
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, OnUpdateEditCopy)
	ON_COMMAND(ID_EDIT_COPY_TO, OnEditCopyTo)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, OnUpdateEditPaste)
	ON_COMMAND(ID_EDIT_PASTE_FROM, OnEditPasteFrom)
	ON_WM_LBUTTONDOWN()
	ON_WM_SETCURSOR()
	ON_WM_SETFOCUS()
	ON_MESSAGE(WM_VIEWPALETTECHANGED, OnViewPaletteChanged) 
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY_TO, OnUpdateEditCopy)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, OnUpdateEditCopy)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoView construction/destruction

CDemoView::CDemoView() : m_sizeTotal(800, 1050),  // 8 by 10.5 inches
						 m_rectTracker(50, 50, 250, 250), 
						 m_rectTrackerEnter(50, 50, 250, 250), 
						 m_dragOffset(0, 0) 
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

	CDib& dib = GetDocument()->m_dib; 
	m_tracker.m_rect = m_rectTracker; 
	pDC->LPtoDP(m_tracker.m_rect); 
	m_tracker.Draw(pDC); 
	dib.Draw(pDC, m_rectTracker.TopLeft(), m_rectTracker.Size()); 
}

void CDemoView::OnInitialUpdate()
{
	SetScrollSizes(MM_TEXT, m_sizeTotal); 
	m_tracker.m_nStyle = CRectTracker::solidLine | CRectTracker::resizeOutside; 
	m_dropTarget.Register(this); 
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

void CDemoView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pDC->IsPrinting())
	{
		int nHsize = pDC->GetDeviceCaps(HORZSIZE) * 1000 / 254; 
		int nVsize = pDC->GetDeviceCaps(VERTSIZE) * 1000 / 254; 
		pDC->SetMapMode(MM_ANISOTROPIC); 
		pDC->SetWindowExt(nHsize, nVsize); 
		pDC->SetViewportExt(pDC->GetDeviceCaps(HORZRES), pDC->GetDeviceCaps(VERTRES)); 
	}
	else 
		CScrollView::OnPrepareDC(pDC, pInfo);
}

COleDataSource* CDemoView::SaveDib()
{
	CDib& dib = GetDocument()->m_dib; 
	if(dib.GetSizeImage() > 0)
	{
		COleDataSource* pSource = new COleDataSource(); 
		int nHeaderSize = dib.GetSizeHeader(); 
		int nImageSize = dib.GetSizeImage(); 
		HGLOBAL hHeader = ::GlobalAlloc(GMEM_SHARE, nHeaderSize + nImageSize); 
		LPVOID pHeader = ::GlobalLock(hHeader); 
		ASSERT(pHeader != NULL); 
		LPVOID pImage = (LPBYTE)pHeader + nHeaderSize; 
		memcpy(pHeader, dib.m_lpBMIH, nHeaderSize); 
		memcpy(pImage, dib.m_lpImage, nImageSize); 
		::GlobalUnlock(hHeader); 
		pSource->CacheGlobalData(CF_DIB, hHeader); 
		return pSource; 
	}

	return NULL; 
}

void CDemoView::OnEditCopy() 
{
	// TODO: Add your command handler code here
	COleDataSource* pSource = SaveDib(); 
	if(pSource)
		pSource->SetClipboard(); 
}

void CDemoView::OnUpdateEditCopy(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CDib& dib = GetDocument()->m_dib; 
	pCmdUI->Enable(dib.GetSizeImage() > 0L); 
}

void CDemoView::OnEditCopyTo() 
{
	// TODO: Add your command handler code here
	CDib& dib = GetDocument()->m_dib; 
	CFileDialog dlg(FALSE, "bmp", "*.bmp"); 
	if(dlg.DoModal() != IDOK)
		return; 

	BeginWaitCursor(); 
	dib.CopyToMapFile(dlg.GetPathName()); 
	EndWaitCursor(); 
}

void CDemoView::OnEditCut() 
{
	// TODO: Add your command handler code here
	OnEditCopy(); 
	GetDocument()->OnEditClearAll(); 
}

BOOL CDemoView::DoPasteDib(COleDataObject* pDataObject)
{
	if(!pDataObject->IsDataAvailable(CF_DIB))
	{
		TRACE("CF_DIB format is unavailable\n"); 
		return FALSE; 
	}

	CDemoDoc* pDoc = GetDocument(); 
	HGLOBAL hDib = pDataObject->GetGlobalData(CF_DIB); 
	ASSERT(hDib != NULL); 
	LPVOID lpDib = ::GlobalLock(hDib); 
	ASSERT(lpDib != NULL); 
	pDoc->m_dib.AttachMemory(lpDib, TRUE, hDib); 
	pDoc->SetModifiedFlag(); 
	pDoc->UpdateAllViews(NULL); 
	return TRUE; 
}

void CDemoView::OnEditPaste() 
{
	// TODO: Add your command handler code here
	CDemoDoc* pDoc = GetDocument(); 
	COleDataObject dataObject; 
	VERIFY(dataObject.AttachClipboard()); 
	DoPasteDib(&dataObject); 
	CClientDC dc(this); 
	pDoc->m_dib.UsePalette(&dc); 
	pDoc->SetModifiedFlag(); 
	pDoc->UpdateAllViews(NULL); 
}

void CDemoView::OnUpdateEditPaste(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	COleDataObject dataObject; 
	BOOL bAvail = dataObject.AttachClipboard() && dataObject.IsDataAvailable(CF_DIB); 
	pCmdUI->Enable(bAvail); 
}

void CDemoView::OnEditPasteFrom() 
{
	// TODO: Add your command handler code here
	CDemoDoc* pDoc = GetDocument(); 
	CFileDialog dlg(TRUE, "bmp", "*.bmp"); 
	if(dlg.DoModal() != IDOK)
		return; 

	if(pDoc->m_dib.AttachMapFile(dlg.GetPathName(), TRUE))
	{
		CClientDC dc(this); 
		pDoc->m_dib.SetSystemPalette(&dc); 
		pDoc->m_dib.UsePalette(&dc); 
		pDoc->SetModifiedFlag(); 
		pDoc->UpdateAllViews(NULL); 
	}
}

void CDemoView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CDemoDoc* pDoc = GetDocument(); 
	if(m_tracker.HitTest(point) == CRectTracker::hitMiddle)
	{
		COleDataSource* pSource = SaveDib(); 
		if(pSource)
		{
			CClientDC dc(this); 
			OnPrepareDC(&dc); 
			CPoint topLeft = m_rectTracker.TopLeft(); 
			dc.LPtoDP(&topLeft); 
			m_dragOffset = point - topLeft; 
			pDoc->m_bDragHere = TRUE; 
			DROPEFFECT dropEffect = pSource->DoDragDrop(DROPEFFECT_MOVE | DROPEFFECT_COPY, CRect(0, 0, 0, 0)); 
			if(dropEffect == DROPEFFECT_MOVE && pDoc->m_bDragHere)
				pDoc->OnEditClearAll(); 
			pDoc->m_bDragHere = FALSE; 
			delete pSource; 
		}
	}
	else if(m_tracker.Track(this, point, FALSE, NULL))
	{
		CClientDC dc(this); 
		OnPrepareDC(&dc); 
		m_rectTracker = m_tracker.m_rect; 
		dc.DPtoLP(m_rectTracker); 
	}

	Invalidate(); 
	CScrollView::OnLButtonDown(nFlags, point);
}

BOOL CDemoView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_tracker.SetCursor(pWnd, nHitTest))
		return TRUE; 

	return CScrollView::OnSetCursor(pWnd, nHitTest, message);
}

void CDemoView::OnSetFocus(CWnd* pOldWnd) 
{
	CScrollView::OnSetFocus(pOldWnd);
	
	// TODO: Add your message handler code here
	AfxGetApp()->m_pMainWnd->SendMessage(WM_PALETTECHANGED, (UINT)GetSafeHwnd()); 
}

LONG CDemoView::OnViewPaletteChanged(UINT wParam, LONG lParam)
{
	CClientDC dc(this); 
	GetDocument()->m_dib.UsePalette(&dc, wParam); 
	Invalidate(); 
	return 0; 
}

DROPEFFECT CDemoView::OnDragEnter(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point) 
{
	// TODO: Add your specialized code here and/or call the base class
	m_rectTrackerEnter = m_rectTracker; 
	CClientDC dc(this); 
	OnPrepareDC(&dc); 
	dc.DrawFocusRect(m_rectTracker); 
	return OnDragOver(pDataObject, dwKeyState, point); 
	//return CScrollView::OnDragEnter(pDataObject, dwKeyState, point);
}

DROPEFFECT CDemoView::OnDragOver(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(!pDataObject->IsDataAvailable(CF_DIB))
		return DROPEFFECT_NONE; 

	MoveTrackRect(point); 
	if((dwKeyState & MK_CONTROL) == MK_CONTROL)
		return DROPEFFECT_COPY; 

	if((dwKeyState & MK_ALT) == MK_ALT)
		return DROPEFFECT_MOVE; 

	return DROPEFFECT_MOVE; 
	//return CScrollView::OnDragOver(pDataObject, dwKeyState, point);
}

void CDemoView::OnDragLeave() 
{
	// TODO: Add your specialized code here and/or call the base class
	CClientDC dc(this); 
	OnPrepareDC(&dc); 
	dc.DrawFocusRect(m_rectTracker); 
	m_rectTracker = m_rectTrackerEnter; 
	CScrollView::OnDragLeave();
}

BOOL CDemoView::OnDrop(COleDataObject* pDataObject, DROPEFFECT dropEffect, CPoint point) 
{
	// TODO: Add your specialized code here and/or call the base class
	BOOL bRet; 
	CDemoDoc* pDoc = GetDocument(); 
	MoveTrackRect(point); 
	if(pDoc->m_bDragHere)
	{
		pDoc->m_bDragHere = FALSE; 
		bRet = TRUE; 
	}
	else 
		bRet = DoPasteDib(pDataObject); 

	return bRet; 
	//return CScrollView::OnDrop(pDataObject, dropEffect, point);
}

void CDemoView::MoveTrackRect(CPoint point)
{
	CClientDC dc(this); 
	OnPrepareDC(&dc); 
	dc.DrawFocusRect(&m_rectTracker); 
	dc.LPtoDP(&m_rectTracker); 
	CSize sizeTrack = m_rectTracker.Size(); 
	CPoint newTopLeft = point - m_dragOffset; 
	m_rectTracker = CRect(newTopLeft, sizeTrack); 
	m_tracker.m_rect = m_rectTracker; 
	dc.DPtoLP(m_rectTracker); 
	dc.DrawFocusRect(m_rectTracker); 
}
