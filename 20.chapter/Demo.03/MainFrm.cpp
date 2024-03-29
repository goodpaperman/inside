// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Demo.h"

#include "MainFrm.h"
#include "StringView.h"
#include "HexView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	ON_WM_CREATE()	
	ON_COMMAND(ID_VIEW_STRINGVIEW, OnViewStringview)
	ON_COMMAND(ID_VIEW_HEXVIEW, OnViewHexview)
	ON_UPDATE_COMMAND_UI(ID_VIEW_STRINGVIEW, OnUpdateViewStringview)
	ON_UPDATE_COMMAND_UI(ID_VIEW_HEXVIEW, OnUpdateViewHexview)
	//}}AFX_MSG_MAP
	// Global help commands
	ON_COMMAND(ID_HELP_FINDER, CFrameWnd::OnHelpFinder)
	ON_COMMAND(ID_HELP, CFrameWnd::OnHelp)
	ON_COMMAND(ID_CONTEXT_HELP, CFrameWnd::OnContextHelp)
	ON_COMMAND(ID_DEFAULT_HELP, CFrameWnd::OnHelpFinder)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers



void CMainFrame::OnViewStringview() 
{
	// TODO: Add your command handler code here
	SwitchToView(STRING); 	
}

void CMainFrame::OnViewHexview() 
{
	// TODO: Add your command handler code here
	SwitchToView(HEX); 
}

void CMainFrame::OnUpdateViewStringview(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(!GetActiveView()->IsKindOf(RUNTIME_CLASS(CStringView))); 
}

void CMainFrame::OnUpdateViewHexview(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(!GetActiveView()->IsKindOf(RUNTIME_CLASS(CHexView))); 
}

void CMainFrame::SwitchToView(eView nView)
{
	CView* pOldActiveView = GetActiveView(); 
	CView* pNewActiveView = (CView*)GetDlgItem(nView); 
	if(pNewActiveView == NULL)
	{
		switch(nView)
		{
			case STRING:
				pNewActiveView = (CView*)RUNTIME_CLASS(CStringView)->CreateObject(); 
				break; 
			case HEX:
				pNewActiveView = (CView*)RUNTIME_CLASS(CHexView)->CreateObject(); 
				break; 
		}

		CCreateContext context; 
		context.m_pCurrentDoc = pOldActiveView->GetDocument();
		pNewActiveView->Create(NULL, NULL,  WS_BORDER, CFrameWnd::rectDefault, this, nView, &context); 
		pNewActiveView->OnInitialUpdate(); 
	}

	SetActiveView(pNewActiveView); 
	pNewActiveView->ShowWindow(SW_SHOW); 
	pOldActiveView->ShowWindow(SW_HIDE); 
	pOldActiveView->SetDlgCtrlID(pOldActiveView->GetRuntimeClass() == RUNTIME_CLASS(CStringView) ? STRING : HEX); 
	pNewActiveView->SetDlgCtrlID(AFX_IDW_PANE_FIRST); 
	RecalcLayout(); 
}