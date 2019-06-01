// TestDemo2Dialog.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "TestDemo2Dialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestDemo2Dialog dialog


CTestDemo2Dialog::CTestDemo2Dialog(CWnd* pParent /*=NULL*/)
	: CDialog(CTestDemo2Dialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestDemo2Dialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	m_nState = OFF; 
	DemoEntry(); 
}


void CTestDemo2Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestDemo2Dialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTestDemo2Dialog, CDialog)
	//{{AFX_MSG_MAP(CTestDemo2Dialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
	ON_CONTROL(0, IDC_RYG, OnClickedRyg) 
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestDemo2Dialog message handlers

void CTestDemo2Dialog::OnClickedRyg()
{
	switch(m_nState)
	{
		case OFF:
			m_nState = RED; 
			break; 
		case RED:
			m_nState = YELLOW; 
			break; 
		case YELLOW:
			m_nState = GREEN; 
			break; 
		case GREEN:
			m_nState = OFF; 
			break; 
	}

	GetDlgItem(IDC_RYG)->SendMessage(RYG_SETSTATE, m_nState); 
	return; 
}