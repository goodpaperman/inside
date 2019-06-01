// DemoDoc.cpp : implementation of the CDemoDoc class
//

#include "stdafx.h"
#include "Demo.h"

#include "DemoDoc.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoDoc

const OLECHAR* CDemoDoc::s_szSub = L"sub"; 

IMPLEMENT_DYNCREATE(CDemoDoc, COleDocument)

BEGIN_MESSAGE_MAP(CDemoDoc, COleDocument)
	//{{AFX_MSG_MAP(CDemoDoc)
	ON_COMMAND(ID_EDIT_CLEAR_ALL, OnEditClearAll)
	//}}AFX_MSG_MAP
	// Enable default OLE container implementation
    //ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, COleDocument::OnUpdatePasteMenu)
    //ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE_LINK, COleDocument::OnUpdatePasteLinkMenu)
    //ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_CONVERT, COleDocument::OnUpdateObjectVerbMenu)
    //ON_COMMAND(ID_OLE_EDIT_CONVERT, COleDocument::OnEditConvert)
    //ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, COleDocument::OnUpdateEditLinksMenu)
    //ON_COMMAND(ID_OLE_EDIT_LINKS, COleDocument::OnEditLinks)
    //ON_UPDATE_COMMAND_UI_RANGE(ID_OLE_VERB_FIRST, ID_OLE_VERB_LAST, COleDocument::OnUpdateObjectVerbMenu)
END_MESSAGE_MAP()

BEGIN_INTERFACE_MAP(CDemoDoc, CDocument)
    INTERFACE_PART(CDemoDoc, IID_IOleClientSite, OleClientSite) 
    INTERFACE_PART(CDemoDoc, IID_IAdviseSink, AdviseSink) 
END_INTERFACE_MAP()

STDMETHODIMP_(ULONG) CDemoDoc::XOleClientSite::AddRef()
{
    METHOD_PROLOGUE(CDemoDoc, OleClientSite) 
    return pThis->InternalAddRef(); 
}

STDMETHODIMP_(ULONG) CDemoDoc::XOleClientSite::Release()
{
    METHOD_PROLOGUE(CDemoDoc, OleClientSite)
    return pThis->InternalRelease(); 
}

STDMETHODIMP CDemoDoc::XOleClientSite::QueryInterface(REFIID iid, LPVOID* ppvObj)
{
    ITrace(iid, "CDemoDoc::XOleClientSite::QueryInterface"); 
    METHOD_PROLOGUE(CDemoDoc, OleClientSite)
    return pThis->InternalQueryInterface(&iid, ppvObj); 
}

STDMETHODIMP CDemoDoc::XOleClientSite::SaveObject()
{
    METHOD_PROLOGUE(CDemoDoc, OleClientSite)
    ASSERT_VALID(pThis); 
    LPPERSISTSTORAGE lpPersistStorage; 
    pThis->m_lpOleObj->QueryInterface(IID_IPersistStorage, (void**)&lpPersistStorage); 
    ASSERT(lpPersistStorage != NULL); 

    HRESULT hr = NOERROR; 
    if(lpPersistStorage->IsDirty() == NOERROR)
    {
        hr = ::OleSave(lpPersistStorage, pThis->m_pTempStgSub, TRUE); 
        if(hr != NOERROR)
            hr = lpPersistStorage->SaveCompleted(NULL); 

        pThis->SetModifiedFlag();
    }

    lpPersistStorage->Release();
    pThis->UpdateAllViews(NULL); 
    return hr; 
}

STDMETHODIMP CDemoDoc::XOleClientSite::GetMoniker(DWORD dwAssign, DWORD dwWhichMoniker, LPMONIKER* ppMoniker)
{
    return E_NOTIMPL; 
}

STDMETHODIMP CDemoDoc::XOleClientSite::GetContainer(LPOLECONTAINER* ppContainer)
{
    return E_NOTIMPL; 
}

STDMETHODIMP CDemoDoc::XOleClientSite::ShowObject()
{
    METHOD_PROLOGUE(CDemoDoc, OleClientSite)
    ASSERT_VALID(pThis); 
    pThis->UpdateAllViews(NULL); 
    return NOERROR; 
}

STDMETHODIMP CDemoDoc::XOleClientSite::OnShowWindow(BOOL fShow)
{
    METHOD_PROLOGUE(CDemoDoc, OleClientSite) 
    ASSERT_VALID(pThis); 
    pThis->m_bHatch = fShow; 
    pThis->UpdateAllViews(NULL); 
    return NOERROR; 
}

STDMETHODIMP CDemoDoc::XOleClientSite::RequestNewObjectLayout()
{
    return E_NOTIMPL; 
}

STDMETHODIMP_(ULONG) CDemoDoc::XAdviseSink::AddRef()
{
    METHOD_PROLOGUE(CDemoDoc, AdviseSink)
    return pThis->InternalAddRef(); 
}

STDMETHODIMP_(ULONG) CDemoDoc::XAdviseSink::Release()
{
    METHOD_PROLOGUE(CDemoDoc, AdviseSink) 
    return pThis->InternalRelease(); 
}

STDMETHODIMP CDemoDoc::XAdviseSink::QueryInterface(REFIID iid, LPVOID* ppvObj)
{
    ITrace(iid, "CDemoDoc::XAdviseSink::QueryInterface"); 
    METHOD_PROLOGUE(CDemoDoc, AdviseSink) 
    return pThis->InternalQueryInterface(&iid, ppvObj); 
}

STDMETHODIMP_(void) CDemoDoc::XAdviseSink::OnDataChange(LPFORMATETC lpFormatEtc, LPSTGMEDIUM lpStgMedium)
{
    METHOD_PROLOGUE(CDemoDoc, AdviseSink) 
    ASSERT_VALID(pThis); 
}

STDMETHODIMP_(void) CDemoDoc::XAdviseSink::OnViewChange(DWORD aspects, LONG /*lindex*/)
{
    METHOD_PROLOGUE(CDemoDoc, AdviseSink)
    ASSERT_VALID(pThis); 
    pThis->UpdateAllViews(NULL); 
}

STDMETHODIMP_(void) CDemoDoc::XAdviseSink::OnRename(LPMONIKER /*lpMoniker*/)
{
}

STDMETHODIMP_(void) CDemoDoc::XAdviseSink::OnSave()
{
    METHOD_PROLOGUE(CDemoDoc, AdviseSink) 
    ASSERT_VALID(pThis); 
    pThis->UpdateAllViews(NULL); 
}

STDMETHODIMP_(void) CDemoDoc::XAdviseSink::OnClose()
{
    METHOD_PROLOGUE(CDemoDoc, AdviseSink) 
    ASSERT_VALID(pThis); 
    pThis->UpdateAllViews(NULL); 
}

/////////////////////////////////////////////////////////////////////////////
// CDemoDoc construction/destruction

CDemoDoc::CDemoDoc()
{
	// Use OLE compound files
	EnableCompoundFile();

	// TODO: add one-time construction code here
    m_lpOleObj = NULL; 
    m_pTempStgRoot = NULL; 
    m_pTempStgSub = NULL; 
    m_bHatch = FALSE; 
}

CDemoDoc::~CDemoDoc()
{
}

BOOL CDemoDoc::OnNewDocument()
{
    //if (!COleDocument::OnNewDocument())
    //    return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
    VERIFY(::StgCreateDocfile(NULL, 
        STGM_READWRITE | STGM_SHARE_EXCLUSIVE | 
        STGM_CREATE | STGM_DELETEONRELEASE, 
        0, &m_pTempStgRoot) == S_OK); 
    ASSERT(m_pTempStgRoot != NULL); 

    VERIFY(m_pTempStgRoot->CreateStorage(OLESTR("sub"), 
        STGM_CREATE | STGM_READWRITE | STGM_SHARE_EXCLUSIVE, 
        0, 0, &m_pTempStgSub) == S_OK); 
    ASSERT(m_pTempStgSub != NULL); 
    return CDocument::OnNewDocument();
}



/////////////////////////////////////////////////////////////////////////////
// CDemoDoc serialization

void CDemoDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}

	// Calling the base class COleDocument enables serialization
	//  of the container document's COleClientItem objects.
	COleDocument::Serialize(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CDemoDoc diagnostics

#ifdef _DEBUG
void CDemoDoc::AssertValid() const
{
	COleDocument::AssertValid();
}

void CDemoDoc::Dump(CDumpContext& dc) const
{
	COleDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDemoDoc commands

void CDemoDoc::OnEditClearAll() 
{
	// TODO: Add your command handler code here
	DeleteContents(); 
    UpdateAllViews(NULL); 
    SetModifiedFlag(); 
    m_bHatch = FALSE; 
}

//void CDemoDoc::OnUpdateEditClearAll(CCmdUI* pCmdUI) 
//{
//    // TODO: Add your command update UI handler code here
    
//}

void CDemoDoc::OnCloseDocument() 
{
	// TODO: Add your specialized code here and/or call the base class
	m_pTempStgSub->Release(); 
    m_pTempStgRoot->Release(); 
	CDocument::OnCloseDocument();
}

void CDemoDoc::DeleteContents() 
{
	// TODO: Add your specialized code here and/or call the base class
	if(m_lpOleObj != NULL)
    {
        m_lpOleObj->Close(OLECLOSE_NOSAVE); 
        m_lpOleObj->Release(); 
        m_lpOleObj = NULL; 
    }
}

BOOL CDemoDoc::SaveModified() 
{
	// TODO: Add your specialized code here and/or call the base class
	return TRUE; 
	//return COleDocument::SaveModified();
}

void ITrace(REFIID iid, const char* str)
{
    OLECHAR* lpszIID; 
    ::StringFromIID(iid, &lpszIID); 
    CString strIID = lpszIID; 
    TRACE("%s - %s\n", (const char*)strIID, (const char*)str); 
    AfxFreeTaskMem(lpszIID); 
}
