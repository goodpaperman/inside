// DemoView.cpp : implementation of the CDemoView class
//

#include "stdafx.h"
#include "Demo.h"

#include "DemoDoc.h"
#include "DemoView.h"
#include "Interface.h"

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
	ON_COMMAND(ID_VIEW_TEST_SPACESHIP, OnTestSpaceship)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
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
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView printing

BOOL CDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
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

void CDemoView::OnTestSpaceship() 
{
	// TODO: Add your command handler code here
	CLSID clsid; 
	LPCLASSFACTORY pClf; 
	LPUNKNOWN pUnk; 
	IMotion* pMot; 
	IVisual* pVis; 
	HRESULT hr; 

	if((hr = ::CLSIDFromProgID(L"Demo.Spaceship", &clsid)) != NOERROR)
	{
		TRACE("unable to find Program ID -- error = %x\n", hr); 
		return ;
	}

	if((hr = ::CoGetClassObject(clsid, CLSCTX_INPROC_SERVER, 
		NULL, IID_IClassFactory, (void**)&pClf)) != NOERROR)
	{
		TRACE("unable to find CLSID -- error = %x\n", hr); 
		return ;
	}

	pClf->CreateInstance(NULL, IID_IUnknown, (void**)&pUnk); 
	pUnk->QueryInterface(IID_IMotion, (void**)&pMot); 
	pMot->QueryInterface(IID_IVisual, (void**)&pVis); 

	TRACE("main: pUnk = %p, pMot = %p, pVis = %p\n", pUnk, pMot, pVis); 
	pMot->Fly(); 
	int nPos = pMot->GetPosition(); 
	TRACE("nPos = %d\n", nPos); 
	pVis->Display(); 
	
	pClf->Release(); 
	pUnk->Release(); 
	pMot->Release(); 
	pVis->Release(); 
	AfxMessageBox("Test succeeded. See Debug window for output."); 
}
