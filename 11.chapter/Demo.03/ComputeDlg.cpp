// ComputeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "ComputeDlg.h"
#include "HMS.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CComputeDlg dialog

CEvent g_eventStart; 
CEvent g_eventKill; 
int g_nCount = 0; 
#define WM_THREADFINISHED (WM_USER + 200)
UINT ComputeThreadProc(LPVOID pParam); 


CComputeDlg::CComputeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CComputeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CComputeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CComputeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CComputeDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CComputeDlg, CDialog)
	//{{AFX_MSG_MAP(CComputeDlg)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_START, OnStart)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_THREADFINISHED, OnThreadFinished)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CComputeDlg message handlers

BOOL CComputeDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	AfxBeginThread(ComputeThreadProc, GetSafeHwnd()); 	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

UINT ComputeThreadProc(LPVOID pParam)
{
	volatile int nTemp; 
	::WaitForSingleObject(g_eventStart, INFINITE); 
	TRACE("starting computation\n"); 
	for(g_nCount = 0; g_nCount<CComputeDlg::nMaxCount; g_nCount++)
    {
		for(nTemp=0; nTemp<100000; nTemp++)
			; 

		if(::WaitForSingleObject(g_eventKill, 0) == WAIT_OBJECT_0)
			break; 
    }

	::PostMessage((HWND)pParam, WM_THREADFINISHED, 0, 0); 
	g_nCount = 0; 
	return 0; 
}


void CComputeDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CProgressCtrl* pBar = (CProgressCtrl*)GetDlgItem(IDC_PROGRESS1); 
	pBar->SetPos(g_nCount * 100 / nMaxCount); 
}

void CComputeDlg::OnStart() 
{
	// TODO: Add your control notification handler code here
	m_nTimer = SetTimer(1, 100, NULL); 
	ASSERT(m_nTimer != 0); 
	GetDlgItem(IDC_START)->EnableWindow(FALSE); 
	g_eventStart.SetEvent(); 
}

void CComputeDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	if(g_nCount == 0)
		g_eventStart.SetEvent(); 

	g_eventKill.SetEvent(); 
}

LRESULT CComputeDlg::OnThreadFinished(WPARAM wParam, LPARAM lParam)
{
	CDialog::OnOK(); 
	return 0; 
}