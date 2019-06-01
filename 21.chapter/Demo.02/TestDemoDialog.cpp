// TestDemoDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "TestDemoDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestDemoDialog dialog


CTestDemoDialog::CTestDemoDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CTestDemoDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestDemoDialog)
	m_dInput = 0.0;
	m_dOutput = 0.0;
	//}}AFX_DATA_INIT
}


void CTestDemoDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestDemoDialog)
	DDX_Text(pDX, IDC_INPUT, m_dInput);
	DDX_Text(pDX, IDC_OUTPUT, m_dOutput);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTestDemoDialog, CDialog)
	//{{AFX_MSG_MAP(CTestDemoDialog)
	ON_BN_CLICKED(IDC_COMPUTE, OnCompute)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestDemoDialog message handlers

void CTestDemoDialog::OnCompute() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE); 
	m_dOutput = DemoSquareRoot(m_dInput); 
	UpdateData(FALSE); 
}
