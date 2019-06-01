// TableSelect.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "TableSelect.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTableSelect dialog


CTableSelect::CTableSelect(CDaoDatabase* pDatabase, CWnd* pParent /*=NULL*/)
	: CDialog(CTableSelect::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTableSelect)
	m_strSelection = _T("");
	//}}AFX_DATA_INIT
    m_pDatabase = pDatabase; 
}


void CTableSelect::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTableSelect)
	DDX_LBString(pDX, IDC_TABLES, m_strSelection);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTableSelect, CDialog)
	//{{AFX_MSG_MAP(CTableSelect)
	ON_LBN_DBLCLK(IDC_TABLES, OnDblclkTables)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTableSelect message handlers

BOOL CTableSelect::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CListBox* pList = (CListBox*)GetDlgItem(IDC_TABLES); 
    int nTables = m_pDatabase->GetTableDefCount(); 
    
    CDaoTableDefInfo tdi; 
    for(int n = 0; n < nTables; n++)
    {
        m_pDatabase->GetTableDefInfo(n, tdi); 
        if(tdi.m_strName.Left(4) != "MSys")
            pList->AddString(tdi.m_strName); 
    }

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CTableSelect::OnDblclkTables() 
{
	// TODO: Add your control notification handler code here
	OnOK(); 
}
