// Page1.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "Property.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CView* g_pView; 

/////////////////////////////////////////////////////////////////////////////
// CPage1 dialog


CPage1::CPage1(CWnd* pParent /*=NULL*/)
	: CPropertyPage(CPage1::IDD)
{
	//{{AFX_DATA_INIT(CPage1)
	m_nFont = -1;
	//}}AFX_DATA_INIT
}


void CPage1::DoDataExchange(CDataExchange* pDX)
{
	TRACE("Entering CPage1::DoDataExchange - - %d\n", 
		pDX->m_bSaveAndValidate); 
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage1)
	DDX_Radio(pDX, IDC_FONT, m_nFont);
	//}}AFX_DATA_MAP
}

BOOL CPage1::OnApply()
{
	TRACE("CPage1::OnApply\n"); 
	g_pView->SendMessage(WM_USERAPPLY); 
	return TRUE; 
}

BOOL CPage1::OnCommand(WPARAM wParam, LPARAM lParam)
{
	SetModified(TRUE); 
	return CPropertyPage::OnCommand(wParam, lParam); 
}


BEGIN_MESSAGE_MAP(CPage1, CPropertyPage)
	//{{AFX_MSG_MAP(CPage1)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage1 message handlers

/////////////////////////////////////////////////////////////////////////////
// CPage2 dialog


CPage2::CPage2(CWnd* pParent /*=NULL*/)
	: CPropertyPage(CPage2::IDD)
{
	//{{AFX_DATA_INIT(CPage2)
	m_bBold = FALSE;
	m_bItalic = FALSE;
	m_bUnderline = FALSE;
	//}}AFX_DATA_INIT
}


void CPage2::DoDataExchange(CDataExchange* pDX)
{
	TRACE("Entering CPage2::DoDataExchange - - %d\n", 
		pDX->m_bSaveAndValidate); 
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage2)
	DDX_Check(pDX, IDC_BOLD, m_bBold);
	DDX_Check(pDX, IDC_ITALIC, m_bItalic);
	DDX_Check(pDX, IDC_UNDERLINE, m_bUnderline);
	//}}AFX_DATA_MAP
}

BOOL CPage2::OnCommand(WPARAM wParam, LPARAM lParam)
{
	SetModified(TRUE); 
	return CPropertyPage::OnCommand(wParam, lParam); 
}


BEGIN_MESSAGE_MAP(CPage2, CPropertyPage)
	//{{AFX_MSG_MAP(CPage2)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage2 message handlers


/////////////////////////////////////////////////////////////////////////////
// CPage3 dialog


CPage3::CPage3(CWnd* pParent /*=NULL*/)
	: CPropertyPage(CPage3::IDD)
{
	//{{AFX_DATA_INIT(CPage3)
	m_nColor = -1;
	//}}AFX_DATA_INIT
}


void CPage3::DoDataExchange(CDataExchange* pDX)
{
	TRACE("Entering CPage3::DoDataExchange - - %d\n", 
		pDX->m_bSaveAndValidate); 
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage3)
	DDX_Radio(pDX, IDC_COLOR, m_nColor);
	//}}AFX_DATA_MAP
}

BOOL CPage3::OnCommand(WPARAM wParam, LPARAM lParam)
{
	SetModified(TRUE); 
	return CPropertyPage::OnCommand(wParam, lParam); 
}


BEGIN_MESSAGE_MAP(CPage3, CPropertyPage)
	//{{AFX_MSG_MAP(CPage3)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage3 message handlers


/////////////////////////////////////////////////////////////////////////////
// CPage4 dialog


CPage4::CPage4(CWnd* pParent /*=NULL*/)
	: CPropertyPage(CPage4::IDD)
{
	//{{AFX_DATA_INIT(CPage4)
	m_nFontSize = 0;
	//}}AFX_DATA_INIT
}


void CPage4::DoDataExchange(CDataExchange* pDX)
{
	TRACE("Entering CPage4::DoDataExchange - - %d\n", 
		pDX->m_bSaveAndValidate); 
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage4)
	DDX_Text(pDX, IDC_FONTSIZE, m_nFontSize);
	DDV_MinMaxInt(pDX, m_nFontSize, 8, 24);
	//}}AFX_DATA_MAP
}

BOOL CPage4::OnCommand(WPARAM wParam, LPARAM lParam)
{
	SetModified(TRUE); 
	return CPropertyPage::OnCommand(wParam, lParam); 
}


BEGIN_MESSAGE_MAP(CPage4, CPropertyPage)
	//{{AFX_MSG_MAP(CPage4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage4 message handlers

BOOL CPage4::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here
	((CSpinButtonCtrl*)GetDlgItem(IDC_SPIN1))->SetRange(8, 24); 
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
/////////////////////////////////////////////////////////////////////////////
// CFontSheet

IMPLEMENT_DYNAMIC(CFontSheet, CPropertySheet)

CFontSheet::CFontSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
}

CFontSheet::CFontSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_page1); 
	AddPage(&m_page2); 
	AddPage(&m_page3); 
	AddPage(&m_page4); 
}

CFontSheet::~CFontSheet()
{
}


BEGIN_MESSAGE_MAP(CFontSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CFontSheet)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFontSheet message handlers
