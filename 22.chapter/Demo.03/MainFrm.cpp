// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Demo.h"

#include "MainFrm.h"
#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	ON_WM_QUERYENDSESSION()
	ON_COMMAND(ID_WINDOW_CLOSE_ALL, OnWindowCloseAll)
	ON_UPDATE_COMMAND_UI(ID_WINDOW_CLOSE_ALL, OnUpdateWindowCloseAll)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	//}}AFX_MSG_MAP
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
	m_nChild = 0; 
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
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
	if( !CMDIFrameWnd::PreCreateWindow(cs) )
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
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	if(CloseAllChildWindows())
		CMDIFrameWnd::OnClose();
}

BOOL CMainFrame::OnQueryEndSession() 
{
	return CloseAllChildWindows(); 
}

void CMainFrame::OnWindowCloseAll() 
{
	// TODO: Add your command handler code here
	CloseAllChildWindows(); 
}

void CMainFrame::OnUpdateWindowCloseAll(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(MDIGetActive() != NULL); 
}

BOOL CMainFrame::CloseAllChildWindows()
{
	CChildFrame* pChild; 
	CChildFrame* pPrevChild = NULL; 
	while((pChild = (CChildFrame*)MDIGetActive()) != NULL)
	{
		if(pChild == pPrevChild)
			return FALSE; 

		pPrevChild = pChild; 
		pChild->SendMessage(WM_CLOSE); 
	}

	return TRUE; 
}

void CMainFrame::OnFileNew() 
{
	// TODO: Add your command handler code here
	BOOL bMaximized = FALSE; 
	CChildFrame* pActiveChild = (CChildFrame*)MDIGetActive(&bMaximized); 
	CChildFrame* pChild = new CChildFrame(); 
	pChild->LoadFrame(IDR_DEMOTYPE, WS_CHILD | WS_VISIBLE | WS_OVERLAPPEDWINDOW | (bMaximized ? WS_MAXIMIZE : 0), this); 

	CString strTitle; 
	strTitle.Format("Child Window %d", m_nChild++); 
	pChild->SetWindowText(strTitle); 
}

void CMainFrame::CreateInitialChild()
{
	OnFileNew(); 
}