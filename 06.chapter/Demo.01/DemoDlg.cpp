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
	m_strBio = _T("");
	m_nCat = -1;
	m_strDept = _T("");
	m_bInsDis = FALSE;
	m_strEduc = _T("");
	m_bInsLife = FALSE;
	m_nLoyal = 0;
	m_bInsMed = FALSE;
	m_strName = _T("");
	m_nRely = 0;
	m_strSkill = _T("");
	m_nSsn = 0;
	m_nLang = -1;
	//}}AFX_DATA_INIT
}


void CDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDemoDlg)
	DDX_Text(pDX, IDC_BIO, m_strBio);
	DDX_Radio(pDX, IDC_CAT, m_nCat);
	DDX_LBString(pDX, IDC_DEPT, m_strDept);
	DDX_Check(pDX, IDC_DIS, m_bInsDis);
	DDX_CBString(pDX, IDC_EDUC, m_strEduc);
	DDX_Check(pDX, IDC_LIFE, m_bInsLife);
	DDX_Scroll(pDX, IDC_LOYAL, m_nLoyal);
	DDX_Check(pDX, IDC_MED, m_bInsMed);
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDX_Scroll(pDX, IDC_RELY, m_nRely);
	DDX_CBString(pDX, IDC_SKILL, m_strSkill);
	DDX_Text(pDX, IDC_SSN, m_nSsn);
	DDV_MinMaxInt(pDX, m_nSsn, 0, 999999999);
	DDX_CBIndex(pDX, IDC_LANG, m_nLang);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CDemoDlg)
	ON_BN_CLICKED(IDC_SPECIAL, OnSpecial)
	ON_BN_CLICKED(IDC_OK, OnBtnOK)
	ON_WM_HSCROLL()
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoDlg message handlers

void CDemoDlg::OnSpecial() 
{
	// TODO: Add your control notification handler code here
	TRACE("CDemoDlg::OnSpecial\n"); 
}

BOOL CDemoDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CListBox* pLB = (CListBox*)GetDlgItem(IDC_DEPT); 
	pLB->InsertString(-1, "Documentation"); 
	pLB->InsertString(-1, "Accounting"); 
	pLB->InsertString(-1, "Human Relations"); 
	pLB->InsertString(-1, "Security"); 

	CScrollBar* pSB = (CScrollBar*)GetDlgItem(IDC_LOYAL); 
	pSB->SetScrollRange(nMin, nMax); 
	pSB = (CScrollBar*)GetDlgItem(IDC_RELY); 
	pSB->SetScrollRange(nMin, nMax); 

	m_hYellowBrush = CreateSolidBrush(RGB(255, 255, 0)); 
	m_hRedBrush = CreateSolidBrush(RGB(255, 0, 0)); 
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDemoDlg::OnOK() 
{
	// TODO: Add extra validation here	
	//CDialog::OnOK();
	TRACE("CDemoDialog::OnOK\n"); 
}

void CDemoDlg::OnBtnOK() 
{
	// TODO: Add your control notification handler code here
	TRACE("CDemoDialog::OnBtnOK\n"); 
	CDialog::OnOK(); 
}

void CDemoDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	int nTemp1 = pScrollBar->GetScrollPos(); 
	int nTemp2 = (nMax - nMin) / 10; 
	
	switch(nSBCode)
	{
		case SB_THUMBPOSITION:
			pScrollBar->SetScrollPos(nPos); 
			break; 
		case SB_LINELEFT:
			nTemp1 -= nTemp2; 
			if(nTemp1 < nMin)
				nTemp1 = nMin; 
			pScrollBar->SetScrollPos(nTemp1); 
			break; 
		case SB_LINERIGHT:
			nTemp1 += nTemp2; 
			if(nTemp2 > nMax)
				nTemp2 = nMax; 
			pScrollBar->SetScrollPos(nTemp1); 
			break; 
	}
}

HBRUSH CDemoDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	if(nCtlColor == CTLCOLOR_EDIT)
	{
		pDC->SetBkColor(RGB(255, 255, 0)); 
		return m_hYellowBrush; 
	}
	else if(nCtlColor == CTLCOLOR_DLG)
	{
		pDC->SetBkColor(RGB(255, 0, 0)); 
		return m_hRedBrush; 
	}

	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	return hbr;
}

void CDemoDlg::OnPaint() 
{
	//CPaintDC dc(this); // device context for painting
	CWnd* pWnd = GetDlgItem(IDC_STATIC1); 
	CDC* pControlDC = pWnd->GetDC(); 
    //pWnd->Invalidate(); 
    //pWnd->UpdateWindow(); 
	pControlDC->SelectStockObject(BLACK_BRUSH); 
	pControlDC->Rectangle(0, 0, 10, 10); 
	pWnd->ReleaseDC(pControlDC); 
}
