// IsamSelect.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "IsamSelect.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIsamSelect dialog


CIsamSelect::CIsamSelect(CWnd* pParent /*=NULL*/)
	: CDialog(CIsamSelect::IDD, pParent)
{
	//{{AFX_DATA_INIT(CIsamSelect)
	m_strDirectory = _T("");
	m_strIsam = _T("");
	//}}AFX_DATA_INIT
}


void CIsamSelect::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIsamSelect)
	DDX_Text(pDX, IDC_DIRECTORY, m_strDirectory);
	DDX_LBString(pDX, IDC_ISAM, m_strIsam);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CIsamSelect, CDialog)
	//{{AFX_MSG_MAP(CIsamSelect)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIsamSelect message handlers

BOOL CIsamSelect::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CListBox* pList = (CListBox*)GetDlgItem(IDC_ISAM); 
    pList->AddString("dBASE III"); 
    pList->AddString("dBASE IV"); 
    pList->AddString("dBASE 5"); 
    pList->AddString("Paradox 3.x"); 
    pList->AddString("Paradox 4.x"); 
    pList->AddString("Paradox 5.x"); 
    pList->AddString("Btrieve"); 
    pList->AddString("FoxPro 2.0"); 
    pList->AddString("FoxPro 2.5"); 
    pList->AddString("FoxPro 3.0"); 
    pList->AddString("FoxPro 4.0"); 
    pList->AddString("FoxPro 5.0"); 
    pList->AddString("FoxPro 7.0"); 
    pList->AddString("Text"); 
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
