
#include "MyApp.h"

CMyApp theApp; 

BOOL CMyApp::InitInstance()
{
	m_pMainWnd = new CMyFrame(); 
	m_pMainWnd->ShowWindow(m_nCmdShow); 
	m_pMainWnd->UpdateWindow(); 
	return TRUE; 
}

BEGIN_MESSAGE_MAP(CMyFrame, CFrameWnd)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()

CMyFrame::CMyFrame()
{
	Create(NULL, "MYAPP Application"); 
}

void CMyFrame::OnLButtonDown(UINT nFlags, CPoint point)
{
	TRACE("Entering CMyFrame::OnLButtonDown - %lx, %d, %d \n", 
		(long)nFlags, point.x, point.y); 
}

void CMyFrame::OnPaint()
{
	CPaintDC dc(this); 
	dc.TextOut(0, 0, "Hello, world!"); 
}