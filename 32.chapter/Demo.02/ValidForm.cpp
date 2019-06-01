// ValidForm.cpp : implementation file
//

#include "stdafx.h"
#include "Ex32b.h"
#include "ValidForm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CValidForm

IMPLEMENT_DYNCREATE(CValidForm, CFormView)

CValidForm::CValidForm(UINT nID)
	: CFormView(nID)
{
	//{{AFX_DATA_INIT(CValidForm)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CValidForm::~CValidForm()
{
}

void CValidForm::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CValidForm)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CValidForm, CFormView)
	//{{AFX_MSG_MAP(CValidForm)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CValidForm diagnostics

#ifdef _DEBUG
void CValidForm::AssertValid() const
{
	CFormView::AssertValid();
}

void CValidForm::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CValidForm message handlers

BOOL CValidForm::OnCommand(WPARAM wParam, LPARAM lParam) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CFormView::OnCommand(wParam, lParam);
}
