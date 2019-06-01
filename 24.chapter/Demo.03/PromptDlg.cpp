// PromptDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "PromptDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPromptDlg dialog


CPromptDlg::CPromptDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPromptDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPromptDlg)
	m_lValue = 0;
	m_strValue = _T("");
	//}}AFX_DATA_INIT
}


void CPromptDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPromptDlg)
	DDX_Text(pDX, IDC_LONG, m_lValue);
	DDX_Text(pDX, IDC_STRING, m_strValue);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPromptDlg, CDialog)
	//{{AFX_MSG_MAP(CPromptDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPromptDlg message handlers
