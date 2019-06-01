// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Demo.h"

#include "MainFrm.h"

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
	ON_WM_CREATE()
	ON_COMMAND(ID_VIEW_STATUS_BAR, OnViewStatusBar)
	ON_UPDATE_COMMAND_UI(ID_VIEW_STATUS_BAR, OnUpdateViewStatusBar)
	//}}AFX_MSG_MAP
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_LEFT, OnUpdateLeft)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_RIGHT, OnUpdateRight)
END_MESSAGE_MAP()

static UINT indicators[] =
{
    //ID_SEPARATOR,           // status line indicator
    //ID_INDICATOR_CAPS,
    //ID_INDICATOR_NUM,
    //ID_INDICATOR_SCRL,

	ID_SEPARATOR, 
	ID_SEPARATOR, 
	ID_INDICATOR_LEFT, 
	ID_INDICATOR_RIGHT, 
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

    //if (!m_wndStatusBar.Create(this) ||
    //    !m_wndStatusBar.SetIndicators(indicators,
    //      sizeof(indicators)/sizeof(UINT)))
    //{
    //    TRACE0("Failed to create status bar\n");
    //    return -1;      // fail to create
    //}

	if(!m_wndStatusBar.Create(this, WS_CHILD | WS_VISIBLE | CBRS_BOTTOM, ID_MY_STATUS_BAR) ||
		!m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar.\n"); 
		return -1; 
	}

	m_wndStatusBar.SetPaneInfo(0, 0, 0, 50); 
	m_wndStatusBar.SetPaneInfo(1, 0, SBPS_STRETCH, 50); 
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


void CMainFrame::OnViewStatusBar() 
{
	// TODO: Add your command handler code here
	m_wndStatusBar.ShowWindow((m_wndStatusBar.GetStyle() & WS_VISIBLE) == 0); 
	RecalcLayout(); 
}

void CMainFrame::OnUpdateViewStatusBar(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck((m_wndStatusBar.GetStyle() & WS_VISIBLE) != 0); 
}

void CMainFrame::OnUpdateLeft(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(::GetKeyState(VK_LBUTTON) < 0); 
}

void CMainFrame::OnUpdateRight(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(::GetKeyState(VK_RBUTTON) < 0); 
}

