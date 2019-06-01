// DemoView.cpp : implementation of the CDemoView class
//

#include "stdafx.h"
#include "Demo.h"

#include "DemoDoc.h"
#include "DemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoView

IMPLEMENT_DYNCREATE(CDemoView, CView)

BEGIN_MESSAGE_MAP(CDemoView, CView)
	//{{AFX_MSG_MAP(CDemoView)
    ON_COMMAND(ID_BANK_LOAD, OnBankLoad)
    ON_UPDATE_COMMAND_UI(ID_BANK_LOAD, OnUpdateBankLoad)
    ON_COMMAND(ID_UNLOAD_BANK, OnUnloadBank)
    ON_UPDATE_COMMAND_UI(ID_UNLOAD_BANK, OnUpdateUnloadBank)
    ON_COMMAND(ID_TEST_BANK, OnTestBank)
    ON_UPDATE_COMMAND_UI(ID_TEST_BANK, OnUpdateTestBank)
    ON_COMMAND(ID_LOAD_DLL, OnLoadDll)
    ON_UPDATE_COMMAND_UI(ID_LOAD_DLL, OnUpdateLoadDll)
    ON_COMMAND(ID_UNLOAD_DLL, OnUnloadDll)
    ON_UPDATE_COMMAND_UI(ID_UNLOAD_DLL, OnUpdateUnloadDll)
    ON_COMMAND(ID_GET_DLL_DATA, OnGetDllData)
    ON_UPDATE_COMMAND_UI(ID_GET_DLL_DATA, OnUpdateGetDllData)
    ON_COMMAND(ID_LOAD_CLOCK, OnLoadClock)
    ON_UPDATE_COMMAND_UI(ID_LOAD_CLOCK, OnUpdateLoadClock)
    ON_COMMAND(ID_UNLOAD_CLOCK, OnUnloadClock)
    ON_UPDATE_COMMAND_UI(ID_UNLOAD_CLOCK, OnUpdateUnloadClock)
    ON_COMMAND(ID_CREATE_CLOCK_ALARM, OnCreateClockAlarm)
    ON_UPDATE_COMMAND_UI(ID_CREATE_CLOCK_ALARM, OnUpdateCreateClockAlarm)
    ON_COMMAND(ID_REFRESH_CLOCK_TIME, OnRefreshClockTime)
    ON_UPDATE_COMMAND_UI(ID_REFRESH_CLOCK_TIME, OnUpdateRefreshClockTime)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoView construction/destruction

CDemoView::CDemoView()
{
	// TODO: add construction code here

}

CDemoView::~CDemoView()
{
}

BOOL CDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView drawing

void CDemoView::OnDraw(CDC* pDC)
{
	CDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView diagnostics

#ifdef _DEBUG
void CDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDemoDoc* CDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDemoDoc)));
	return (CDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDemoView message handlers

void CDemoView::OnBankLoad() 
{
    // TODO: Add your command handler code here
    if(m_bank.CreateInstance(__uuidof(Bank)) != S_OK)
        AfxMessageBox("Bank component not found."); 
}

void CDemoView::OnUpdateBankLoad(CCmdUI* pCmdUI) 
{
    // TODO: Add your command update UI handler code here
    pCmdUI->Enable(m_bank.GetInterfacePtr() == NULL); 
}

void CDemoView::OnUnloadBank() 
{
    // TODO: Add your command handler code here
    m_bank.Release(); 
}

void CDemoView::OnUpdateUnloadBank(CCmdUI* pCmdUI) 
{
    // TODO: Add your command update UI handler code here
    pCmdUI->Enable(m_bank.GetInterfacePtr() != NULL); 
}

void CDemoView::OnTestBank() 
{
    // TODO: Add your command handler code here
	try
	{
        m_bank->Deposit(20.0); 
        m_bank->Withdrawal(15.0); 
        TRACE("new balance = %f\n", m_bank->GetBalance()); 
	}
	catch(_com_error& e)
	{
		AfxMessageBox(e.ErrorMessage()); 
	}
}

void CDemoView::OnUpdateTestBank(CCmdUI* pCmdUI) 
{
    // TODO: Add your command update UI handler code here
    pCmdUI->Enable(m_bank.GetInterfacePtr() != NULL); 
}

void CDemoView::OnLoadDll() 
{
    // TODO: Add your command handler code here
    if(m_auto.CreateInstance(__uuidof(Auto)) != S_OK)
    {
        AfxMessageBox("Auto component not found."); 
        return; 
    }
}

void CDemoView::OnUpdateLoadDll(CCmdUI* pCmdUI) 
{
    // TODO: Add your command update UI handler code here
    pCmdUI->Enable(m_auto.GetInterfacePtr() == NULL); 
}

void CDemoView::OnUnloadDll() 
{
    // TODO: Add your command handler code here
    m_auto.Release(); 
}

void CDemoView::OnUpdateUnloadDll(CCmdUI* pCmdUI) 
{
    // TODO: Add your command update UI handler code here
    pCmdUI->Enable(m_auto.GetInterfacePtr() != NULL); 
}

void CDemoView::OnGetDllData() 
{
    // TODO: Add your command handler code here
	try
	{
        m_auto->DisplayDialog();
        COleVariant vaData = m_auto->GetTextData(); 
        ASSERT(vaData.vt == VT_BSTR); 
        CString strTextData = vaData.bstrVal; 
        long lData = m_auto->GetLongData(); 
        TRACE("CDemoView::OnGetDllData -- long = %ld, text = %s\n", lData, strTextData); 
	}
	catch(_com_error& e)
	{
		AfxMessageBox(e.ErrorMessage()); 
	}
}

void CDemoView::OnUpdateGetDllData(CCmdUI* pCmdUI) 
{
    // TODO: Add your command update UI handler code here
    pCmdUI->Enable(m_auto.GetInterfacePtr() != NULL); 
}

void CDemoView::OnLoadClock() 
{
    // TODO: Add your command handler code here
    if(m_clock.CreateInstance(__uuidof(Document)) != S_OK)
    {
        AfxMessageBox("Clock component not found."); 
        return; 
    }

	try
	{
        m_clock->PutFigure(0, COleVariant("XII")); 
        m_clock->PutFigure(1, COleVariant("III")); 
        m_clock->PutFigure(2, COleVariant("VI")); 
        m_clock->PutFigure(3, COleVariant("IX")); 
        OnRefreshClockTime(); 
        m_clock->ShowWin(); 
	}
	catch(_com_error& e)
	{
		AfxMessageBox(e.ErrorMessage()); 
	}
}

void CDemoView::OnUpdateLoadClock(CCmdUI* pCmdUI) 
{
    // TODO: Add your command update UI handler code here
    pCmdUI->Enable(m_clock.GetInterfacePtr() == NULL); 
}

void CDemoView::OnUnloadClock() 
{
    // TODO: Add your command handler code here
    m_clock.Release(); 
}

void CDemoView::OnUpdateUnloadClock(CCmdUI* pCmdUI) 
{
    // TODO: Add your command update UI handler code here
    pCmdUI->Enable(m_clock.GetInterfacePtr() != NULL); 
}

void CDemoView::OnCreateClockAlarm() 
{
    // TODO: Add your command handler code here
	try
	{
    	COleDateTime dt(1995, 12, 23, 12, 45, 30); 
        LPDISPATCH pAlarm = m_clock->CreateAlarm(dt); 
        m_alarm.Attach((IAlarm*)pAlarm); 
        m_clock->RefreshWin(); 
	}
	catch(_com_error& e)
	{
		AfxMessageBox(e.ErrorMessage()); 
	}
}

void CDemoView::OnUpdateCreateClockAlarm(CCmdUI* pCmdUI) 
{
    // TODO: Add your command update UI handler code here
    pCmdUI->Enable(m_clock.GetInterfacePtr() != NULL); 
}

void CDemoView::OnRefreshClockTime() 
{
    // TODO: Add your command handler code here
    COleDateTime now = COleDateTime::GetCurrentTime(); 
	try
	{
    	m_clock->PutTime(now); 
        m_clock->RefreshWin(); 
	}
	catch(_com_error& e)
	{
		AfxMessageBox(e.ErrorMessage()); 
	}
}

void CDemoView::OnUpdateRefreshClockTime(CCmdUI* pCmdUI) 
{
    // TODO: Add your command update UI handler code here
    pCmdUI->Enable(m_clock.GetInterfacePtr() != NULL); 
}