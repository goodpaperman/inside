// ChildFrm.cpp : implementation of the CChildFrame class
//

#include "stdafx.h"
#include "Demo.h"

#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildFrame

IMPLEMENT_DYNAMIC(CChildFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)
	//{{AFX_MSG_MAP(CChildFrame)
		ON_COMMAND(ID_FILE_CLOSE, OnFileClose)
	ON_WM_PAINT()
		ON_WM_SETFOCUS()
		ON_WM_CREATE()
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChildFrame construction/destruction

CChildFrame::CChildFrame()
{
	// TODO: add member initialization code here
	
}

CChildFrame::~CChildFrame()
{
}



/////////////////////////////////////////////////////////////////////////////
// CChildFrame diagnostics

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWnd::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CChildFrame message handlers
void CChildFrame::OnFileClose() 
{
	// To close the frame, just send a WM_CLOSE, which is the equivalent
	// choosing close from the system menu.

	SendMessage(WM_CLOSE);
}

void CChildFrame::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	dc.TextOut(0, 0, "Hello world!"); 
}

void CChildFrame::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	if(AfxMessageBox("OK to close window?", MB_YESNO) == IDYES)
		CMDIChildWnd::OnClose();
}
