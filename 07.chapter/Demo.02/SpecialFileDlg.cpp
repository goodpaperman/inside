// SpecialFileDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "SpecialFileDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpecialFileDialog dialog


CSpecialFileDialog::CSpecialFileDialog(BOOL bOpenFileDialog, 
									   LPCTSTR lpszDefExt, LPCTSTR lpszFileName, DWORD dwFlags, 
									   LPCTSTR lpszFilter, CWnd* pParentWnd)
	: CFileDialog(bOpenFileDialog, lpszDefExt, lpszFileName, dwFlags, lpszFilter, pParentWnd)
{
	//{{AFX_DATA_INIT(CSpecialFileDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	m_ofn.Flags |= OFN_ENABLETEMPLATE; 
	m_ofn.lpTemplateName = MAKEINTRESOURCE(IDD_FILESPECIAL); 
	m_ofn.lpstrTitle = "Delete File"; 
	m_bDeleteAll = FALSE; 
}


void CSpecialFileDialog::DoDataExchange(CDataExchange* pDX)
{
	CFileDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSpecialFileDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSpecialFileDialog, CFileDialog)
	//{{AFX_MSG_MAP(CSpecialFileDialog)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpecialFileDialog message handlers

BOOL CSpecialFileDialog::OnInitDialog() 
{
	BOOL bRet = CFileDialog::OnInitDialog();
	if(bRet)
	{
		GetParent()->GetDlgItem(IDOK)->SetWindowText("Delete"); 
		HICON hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME); 
		GetParent()->SetIcon(hIcon, TRUE); 
		GetParent()->SetIcon(hIcon, FALSE); 
	}
	
	return bRet; 
}

void CSpecialFileDialog::OnDelete() 
{
	// TODO: Add your control notification handler code here
	m_bDeleteAll = TRUE; 
	GetParent()->GetDlgItem(0x480)->GetWindowText(m_strFileName); 
	GetParent()->SendMessage(WM_COMMAND, IDCANCEL); 
}
