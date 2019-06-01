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

double CDemoDlg::dValue[5] = { 4.0, 5.6, 8.0, 11.0, 16.0 }; 


CDemoDlg::CDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDemoDlg)
	m_dSpin = 0.0;
	//}}AFX_DATA_INIT

	m_nProgress = 0; 
	m_nSlider1 = 0; 
	m_nSlider2 = 0; 
}


void CDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDemoDlg)
	DDX_Text(pDX, IDC_EDIT1, m_dSpin);
	DDV_MinMaxDouble(pDX, m_dSpin, 0., 10.);
	//}}AFX_DATA_MAP

	if(pDX->m_bSaveAndValidate)
	{
		TRACE("updating trackbar data members.\n"); 
		CSliderCtrl* pSlider1 = (CSliderCtrl*)GetDlgItem(IDC_SLIDER1); 
		m_nSlider1 = pSlider1->GetPos(); 

		CSliderCtrl* pSlider2 = (CSliderCtrl*)GetDlgItem(IDC_SLIDER2); 
		m_nSlider2 = pSlider2->GetPos(); 
	}
}


BEGIN_MESSAGE_MAP(CDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CDemoDlg)
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, OnItemchangedList1)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, OnSelchangedTree1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoDlg message handlers

BOOL CDemoDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CProgressCtrl* pProg = (CProgressCtrl*)GetDlgItem(IDC_PROGRESS1); 
	pProg->SetRange(0, 100); 
	pProg->SetPos(m_nProgress); 

	CSliderCtrl* pSlider1 = (CSliderCtrl*)GetDlgItem(IDC_SLIDER1); 
	pSlider1->SetRange(0, 100); 
	pSlider1->SetPos(m_nSlider1); 

	CString strText1; 
	strText1.Format("%d", pSlider1->GetPos()); 
	SetDlgItemText(IDC_STATIC_SLIDER1, strText1); 

	CSliderCtrl* pSlider2 = (CSliderCtrl*)GetDlgItem(IDC_SLIDER2); 
	pSlider2->SetRange(0, 4); 
	pSlider2->SetPos(m_nSlider2); 

	CString strText2; 
	strText2.Format("%3.1f", dValue[pSlider2->GetPos()]); 
	SetDlgItemText(IDC_STATIC_SLIDER2, strText2); 

	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN1); 
	pSpin->SetRange(0, 100); 
	pSpin->SetPos((int)(m_dSpin*10.0)); 

	HICON hIcon[8]; 
	m_imageList.Create(16, 16, 0, 8, 8); 
	hIcon[0] = AfxGetApp()->LoadIcon(IDI_WHITE); 
	hIcon[1] = AfxGetApp()->LoadIcon(IDI_BLACK); 
	hIcon[2] = AfxGetApp()->LoadIcon(IDI_RED); 
	hIcon[3] = AfxGetApp()->LoadIcon(IDI_BLUE); 
	hIcon[4] = AfxGetApp()->LoadIcon(IDI_YELLOW); 
	hIcon[5] = AfxGetApp()->LoadIcon(IDI_CYAN); 
	hIcon[6] = AfxGetApp()->LoadIcon(IDI_PURPLE); 
	hIcon[7] = AfxGetApp()->LoadIcon(IDI_GREEN); 
	for(int n=0; n<8; n++)
		m_imageList.Add(hIcon[n]); 

	static char* color[] = 
	{
		"white", "black", "red", 
		"blue", "yellow", "cyan", 
		"purple", "green"
	}; 

	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST1); 
	pList->SetImageList(&m_imageList, LVSIL_SMALL); 
	for(n=0; n<8; n++)
		pList->InsertItem(n, color[n], n); 

	pList->SetBkColor(RGB(0, 255, 255)); 
	pList->SetTextBkColor(RGB(0, 255, 255)); 

	CTreeCtrl* pTree = (CTreeCtrl*)GetDlgItem(IDC_TREE1); 
	pTree->SetImageList(&m_imageList, TVSIL_NORMAL); 
	
	TV_INSERTSTRUCT tv; 
	tv.hParent = NULL; 
	tv.hInsertAfter = TVI_LAST; 
	tv.item.mask = TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_TEXT; 
	tv.item.hItem = NULL; 
	tv.item.state = 0; 
	tv.item.stateMask = 0; 
	tv.item.cchTextMax = 6; 
	tv.item.iSelectedImage = 1; 
	tv.item.cChildren = 0; 
	tv.item.lParam = 0; 

	tv.item.pszText = "Homer"; 
	tv.item.iImage = 2; 
	HTREEITEM hDad = pTree->InsertItem(&tv); 

	tv.item.pszText = "Marge"; 
	HTREEITEM hMom = pTree->InsertItem(&tv); 

	tv.hParent = hDad; 
	tv.item.pszText = "Bart"; 
	tv.item.iImage = 3; 
	pTree->InsertItem(&tv); 

	tv.item.pszText = "Lisa"; 
	pTree->InsertItem(&tv); 

	tv.hParent = hMom; 
	tv.item.pszText = "Bart"; 
	tv.item.iImage = 4; 
	pTree->InsertItem(&tv); 

	tv.item.pszText = "Lisa"; 
	pTree->InsertItem(&tv); 

	tv.item.pszText = "Dilbert"; 
	HTREEITEM hOther = pTree->InsertItem(&tv); 

	tv.hParent = hOther; 
	tv.item.pszText = "Dogbert"; 
	tv.item.iImage = 7; 
	pTree->InsertItem(&tv); 

	tv.item.pszText = "Ratbert"; 
	pTree->InsertItem(&tv); 

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDemoDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	CSliderCtrl* pSlider = (CSliderCtrl*)pScrollBar; 
	CString strText; 
	switch(pSlider->GetDlgCtrlID())
	{
		case IDC_SLIDER1:
        	strText.Format("%d", pSlider->GetPos()); 
        	SetDlgItemText(IDC_STATIC_SLIDER1, strText); 
        	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
			break; 
		case IDC_SLIDER2:
			strText.Format("%3.1f", dValue[pSlider->GetPos()]); 
			SetDlgItemText(IDC_STATIC_SLIDER2, strText); 
			break; 
	}
}

void CDemoDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	if(nSBCode == SB_ENDSCROLL)
		return; 

	if(pScrollBar->GetDlgCtrlID() == IDC_SPIN1)
	{
		CString strValue; 
		strValue.Format("%3.1f", (double)nPos / 10.0); 
		((CSpinButtonCtrl*)pScrollBar)->GetBuddy()->SetWindowText(strValue); 
	}
}

void CDemoDlg::OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST1); 
	int nSelected = pNMListView->iItem; 
	if(nSelected >= 0)
	{
		CString strItem = pList->GetItemText(nSelected, 0); 
		SetDlgItemText(IDC_STATIC_LIST1, strItem); 
	}

	*pResult = 0;
}

void CDemoDlg::OnSelchangedTree1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	CTreeCtrl* pTree = (CTreeCtrl*)GetDlgItem(IDC_TREE1); 
	HTREEITEM hSelected = pNMTreeView->itemNew.hItem; 
	if(hSelected != NULL)
	{
		char text[31]; 
		TV_ITEM item; 
		item.mask = TVIF_HANDLE | TVIF_TEXT; 
		item.hItem = hSelected; 
		item.pszText = text; 
		item.cchTextMax = 30; 
		VERIFY(pTree->GetItem(&item)); 
		SetDlgItemText(IDC_STATIC_TREE1, text); 
	}

	*pResult = 0;
}
