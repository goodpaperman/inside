// ValidForm.cpp : implementation file
//

#include "stdafx.h"
#include "Ex32b.h"
#include "valform.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CValidForm

IMPLEMENT_DYNAMIC(CValidForm, CFormView)

CValidForm::CValidForm(UINT nID)
	: CFormView(nID)
{
	//{{AFX_DATA_INIT(CValidForm)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
    m_bValidationOn = TRUE; 
}

BEGIN_MESSAGE_MAP(CValidForm, CFormView)
	//{{AFX_MSG_MAP(CValidForm)
		// NOTE - the ClassWizard will add and remove mapping macros here.
        ON_MESSAGE(WM_VALIDATE, OnValidate) 
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CValidForm message handlers

BOOL CValidForm::OnCommand(WPARAM wParam, LPARAM lParam) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(m_bValidationOn)
    {
        UINT notificationCode = (UINT)HIWORD(wParam); 
        switch(notificationCode)
        {
        case EN_KILLFOCUS:
        case LBN_KILLFOCUS:
        case CBN_KILLFOCUS:
            CWnd* pFocus = CWnd::GetFocus(); 
            if(pFocus && (pFocus->GetParent() == this))
            {
                if(pFocus->GetDlgCtrlID() != IDCANCEL)
                {
                    BOOL rtn = PostMessage(WM_VALIDATE, wParam); 
                    TRACE("posted message, rtn = %d\n", rtn); 
                }
            }
            break; 
        }
    }

	return CFormView::OnCommand(wParam, lParam);
}

LONG CValidForm::OnValidate(UINT wParam, LONG lParam)
{
    CDataExchange dx(this, TRUE); 
    m_bValidationOn = FALSE;
    UINT controlID = (UINT)LOWORD(wParam); 
    try
    {
        ValidateDlgItem(&dx, controlID); 
    }
    catch(CUserException* pUE)
    {
        pUE->Delete(); 
    }
    m_bValidationOn = TRUE; 
    return 0; 
}

void CValidForm::ValidateDlgItem(CDataExchange* pDX, UINT ID)
{
}