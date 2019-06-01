// DemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "DemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoDlg dialog


CDemoDlg::CDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDemoDlg)
	m_strEdit1 = _T("");
	//}}AFX_DATA_INIT

	m_pView = NULL; 
}

CDemoDlg::CDemoDlg(CView* pView)
{
	m_pView = pView; 
}


void CDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDemoDlg)
	DDX_Text(pDX, IDC_EDIT1, m_strEdit1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CDemoDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoDlg message handlers

BOOL CDemoDlg::Create()
{
	return CDialog::Create(CDemoDlg::IDD); 
}

void CDemoDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	if(m_pView != NULL)
		m_pView->PostMessage(WM_GOODBYE, IDCANCEL); 
	else 
		CDialog::OnCancel(); 
}

void CDemoDlg::OnOK() 
{
	// TODO: Add extra validation here
	if(m_pView != NULL)
	{
		UpdateData(TRUE); 
		m_pView->PostMessage(WM_GOODBYE, IDOK); 
	}
	else 
		CDialog::OnOK();
}
