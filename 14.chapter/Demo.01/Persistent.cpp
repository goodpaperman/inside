// Persistent.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "Persistent.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPersistentFrame

const CRect CPersistentFrame::s_rectDefault(10, 10, 500, 400); 
const char CPersistentFrame::s_profileHeading[] = "Window size"; 
const char CPersistentFrame::s_profileRect[] = "Rect"; 
const char CPersistentFrame::s_profileIcon[] = "icon"; 
const char CPersistentFrame::s_profileMax[] = "max"; 
const char CPersistentFrame::s_profileTool[] = "tool"; 
const char CPersistentFrame::s_profileStatus[] = "status"; 

IMPLEMENT_DYNAMIC(CPersistentFrame, CFrameWnd)

CPersistentFrame::CPersistentFrame()
{
	m_bFirstTime = TRUE; 
}

CPersistentFrame::~CPersistentFrame()
{
}


BEGIN_MESSAGE_MAP(CPersistentFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CPersistentFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	ON_WM_DESTROY() 
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPersistentFrame message handlers

void CPersistentFrame::OnDestroy()
{
	CString strText; 
	BOOL bIconic, bMaximized; 
	WINDOWPLACEMENT wndpl; 
	wndpl.length = sizeof(WINDOWPLACEMENT); 
	BOOL bRet = GetWindowPlacement(&wndpl); 

	if(wndpl.showCmd == SW_SHOWNORMAL)
	{
		bIconic = FALSE; 
		bMaximized = FALSE; 
	}
	else if(wndpl.showCmd == SW_SHOWMAXIMIZED)
	{
		bIconic = FALSE; 
		bMaximized = TRUE; 
	}
	else if(wndpl.showCmd == SW_SHOWMINIMIZED)
	{
		bIconic = TRUE; 
		if(wndpl.flags)
			bMaximized = TRUE; 
		else 
			bMaximized = FALSE; 
	}

	strText.Format("%04d %04d %04d %04d", 
		wndpl.rcNormalPosition.left, 
		wndpl.rcNormalPosition.top, 
		wndpl.rcNormalPosition.right, 
		wndpl.rcNormalPosition.bottom); 

	AfxGetApp()->WriteProfileString(s_profileHeading, s_profileRect, strText); 
	AfxGetApp()->WriteProfileInt(s_profileHeading, s_profileIcon, bIconic); 
	AfxGetApp()->WriteProfileInt(s_profileHeading, s_profileMax, bMaximized); 
	SaveBarState(AfxGetApp()->m_pszProfileName); 

	CFrameWnd::OnDestroy(); 
}

void CPersistentFrame::ActivateFrame(int nCmdShow)
{
	CString strText; 
	BOOL bIconic, bMaximized; 
	UINT flags; 
	WINDOWPLACEMENT wndpl; 
	CRect rect; 

	if(m_bFirstTime)
	{
		m_bFirstTime = FALSE; 
		strText = AfxGetApp()->GetProfileString(s_profileHeading, s_profileRect); 
		if(!strText.IsEmpty())
		{
			rect.left = atoi((const char*)strText); 
			rect.top = atoi((const char*)strText+5); 
			rect.right = atoi((const char*)strText+10); 
			rect.bottom = atoi((const char*)strText+15); 
		}
		else 
			rect = s_rectDefault; 

		bIconic = AfxGetApp()->GetProfileInt(s_profileHeading, s_profileIcon, 0); 
		bMaximized = AfxGetApp()->GetProfileInt(s_profileHeading, s_profileMax, 0); 

		if(bIconic)
		{
			nCmdShow = SW_SHOWMINNOACTIVE; 
			if(bMaximized)
				flags = WPF_RESTORETOMAXIMIZED; 
			else 
				flags = WPF_SETMINPOSITION; 
		}
		else 
		{
			if(bMaximized)
			{
				nCmdShow = SW_SHOWMAXIMIZED; 
				flags = WPF_RESTORETOMAXIMIZED; 
			}
			else 
			{
				nCmdShow = SW_NORMAL; 
				flags = WPF_SETMINPOSITION; 
			}
		}

		wndpl.length = sizeof(WINDOWPLACEMENT); 
		wndpl.showCmd = nCmdShow; 
		wndpl.flags = flags; 
		wndpl.ptMinPosition = CPoint(0, 0); 
		wndpl.ptMaxPosition = CPoint(-::GetSystemMetrics(SM_CXBORDER), 
			-::GetSystemMetrics(SM_CYBORDER)); 
		wndpl.rcNormalPosition = rect; 
		LoadBarState(AfxGetApp()->m_pszProfileName); 
		BOOL bRet = SetWindowPlacement(&wndpl); 
	}

	CFrameWnd::ActivateFrame(nCmdShow); 
}


