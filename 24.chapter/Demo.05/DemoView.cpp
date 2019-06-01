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
	ON_COMMAND(ID_LOAD_EXCEL, OnLoadExcel)
	ON_UPDATE_COMMAND_UI(ID_LOAD_EXCEL, OnUpdateLoadExcel)
	ON_COMMAND(ID_EXECUTE_EXCEL, OnExecuteExcel)
	ON_UPDATE_COMMAND_UI(ID_EXECUTE_EXCEL, OnUpdateExecuteExcel)
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
	if(!m_bank.CreateDispatch("Demo.Bank"))
		AfxMessageBox("Demo.Bank component not found."); 
}

void CDemoView::OnUpdateBankLoad(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_bank.m_lpDispatch == NULL); 
}

void CDemoView::OnUnloadBank() 
{
	// TODO: Add your command handler code here
	m_bank.ReleaseDispatch(); 
}

void CDemoView::OnUpdateUnloadBank(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_bank.m_lpDispatch != NULL); 
}

void CDemoView::OnTestBank() 
{
	// TODO: Add your command handler code here
	m_bank.Deposit(20.0); 
	m_bank.Withdrawal(15.0); 
	TRACE("new balance = %f\n", m_bank.GetBalance()); 
}

void CDemoView::OnUpdateTestBank(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_bank.m_lpDispatch != NULL); 
}

void CDemoView::OnLoadDll() 
{
	// TODO: Add your command handler code here
	if(!m_auto.CreateDispatch("Demo.Auto"))
	{
		AfxMessageBox("Demo.Auto component not found."); 
		return; 
	}

	m_auto.SetTextData(COleVariant("test")); 
	m_auto.SetLongData(79); 
	
    // {E3EA3678-AE8D-43B6-B418-7E3A1CD7CC2D}
    static const IID IID_IDemoAuto =
    { 0xe3ea3678, 0xae8d, 0x43b6, { 0xb4, 0x18, 0x7e, 0x3a, 0x1c, 0xd7, 0xcc, 0x2d } };
	LPDISPATCH p; 
	HRESULT hr = m_auto.m_lpDispatch->QueryInterface(IID_IDemoAuto, (void**)&p); 
	TRACE("OnLoadDll -- QueryInterface result = %x\n", hr); 
	p->Release(); 
}

void CDemoView::OnUpdateLoadDll(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_auto.m_lpDispatch == NULL); 
}

void CDemoView::OnUnloadDll() 
{
	// TODO: Add your command handler code here
	m_auto.ReleaseDispatch(); 
}

void CDemoView::OnUpdateUnloadDll(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_auto.m_lpDispatch != NULL); 
}

void CDemoView::OnGetDllData() 
{
	// TODO: Add your command handler code here
	m_auto.DisplayDialog(); 
	COleVariant vaData = m_auto.GetTextData(); 
	ASSERT(vaData.vt == VT_BSTR); 
	CString strTextData = vaData.bstrVal; 
	long lData = m_auto.GetLongData(); 
	TRACE("CDemoView::OnGetDllData -- long = %ld, text = %s\n", lData, strTextData); 
}

void CDemoView::OnUpdateGetDllData(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_auto.m_lpDispatch != NULL); 
}

void CDemoView::OnLoadClock() 
{
	// TODO: Add your command handler code here
	if(!m_clock.CreateDispatch("Demo.Document"))
	{
		AfxMessageBox("Demo.Document component not found."); 
		return; 
	}

	m_clock.SetFigure(0, COleVariant("XII")); 
	m_clock.SetFigure(1, COleVariant("III")); 
	m_clock.SetFigure(2, COleVariant("VI")); 
	m_clock.SetFigure(3, COleVariant("IX")); 
	OnRefreshClockTime(); 
	m_clock.ShowWin(); 
}

void CDemoView::OnUpdateLoadClock(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_clock.m_lpDispatch == NULL); 
}

void CDemoView::OnUnloadClock() 
{
	// TODO: Add your command handler code here
	m_clock.ReleaseDispatch(); 
}

void CDemoView::OnUpdateUnloadClock(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_clock.m_lpDispatch != NULL); 
}

void CDemoView::OnCreateClockAlarm() 
{
	// TODO: Add your command handler code here
	COleDateTime dt(1995, 12, 23, 12, 45, 30); 
	LPDISPATCH pAlarm = m_clock.CreateAlarm(dt); 
	m_alarm.AttachDispatch(pAlarm); 
	m_clock.RefreshWin(); 
}

void CDemoView::OnUpdateCreateClockAlarm(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_clock.m_lpDispatch != NULL); 
}

void CDemoView::OnRefreshClockTime() 
{
	// TODO: Add your command handler code here
	COleDateTime now = COleDateTime::GetCurrentTime(); 
	m_clock.SetTime(now); 
	m_clock.RefreshWin(); 
}

void CDemoView::OnUpdateRefreshClockTime(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_clock.m_lpDispatch != NULL); 
}

void CDemoView::OnLoadExcel() 
{
	// TODO: Add your command handler code here
	LPDISPATCH pDisp; 
	LPUNKNOWN pUnk; 
	CLSID clsid; 
	TRACE("Entering CDemoView::OnLoadExcel\n"); 
	
	BeginWaitCursor(); 
	::CLSIDFromProgID(L"Excel.Application.11", &clsid); 
	if(::GetActiveObject(clsid, NULL, &pUnk) == S_OK)
	{
		VERIFY(pUnk->QueryInterface(IID_IDispatch, (void**)&pDisp) == S_OK); 
		m_app.AttachDispatch(pDisp); 
		pUnk->Release(); 
		TRACE("attach complete\n"); 
	}
	else 
	{
		if(!m_app.CreateDispatch("Excel.Application.11"))
			AfxMessageBox("Excel program not found"); 
		else 
			TRACE("attach complete\n"); 
	}
	EndWaitCursor(); 
}

void CDemoView::OnUpdateLoadExcel(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_app.m_lpDispatch == NULL); 
}

void CDemoView::OnExecuteExcel() 
{
	// TODO: Add your command handler code here
	CWnd* pWnd = CWnd::FindWindow("XLMAIN", NULL); 
	if(pWnd != NULL)
	{
		TRACE("Excel window found\n"); 
		pWnd->ShowWindow(SW_SHOWNORMAL); 
		pWnd->UpdateWindow(); 
		pWnd->BringWindowToTop(); 
	}

    //LPDISPATCH pWorkbooks; 
    //VARIANT va; 
	m_app.SetSheetsInNewWorkbook(COleVariant((short)1)); 
    //va = m_app.Workbooks(COleVariant((short)0)); //m_app.GetThisWorkbook(); //m_app.GetActiveWorkbook(); //m_app.Workbooks(COleVariant((short)1)); 
    //VERIFY(pWorkbooks = va.pdispVal); 
    //m_workbooks.AttachDispatch(pWorkbooks); 

    //LPDISPATCH pWorkbook = NULL; 
    //if(m_workbooks.GetCount().intVal == 0)
    //    pWorkbook = m_workbooks.Add().pdispVal; 

    //LPDISPATCH pWorksheets = m_app.Worksheets().pdispVal; 
    //ASSERT(pWorksheets != NULL); 
    //m_worksheets.AttachDispatch(pWorksheets); 

	//LPDISPATCH pWorksheet = m_app.GetActiveSheet().pdispVal; 
    //LPDISPATCH pWorksheet = m_worksheets.Item(COleVariant((short)1)).pdispVal; 
    //m_worksheet.AttachDispatch(pWorksheet); 
	//m_worksheet.Select();

    LPDISPATCH pRange; 
    //VERIFY(pRange = m_worksheet.Range(COleVariant("A1")).pdispVal); 
	VERIFY(pRange = m_app.GetActiveCell().pdispVal); 
    m_range[0].AttachDispatch(pRange); 
	//m_range[1] = m_range[2] = m_range[3] = m_range[4] = m_range[0]; 

    //VERIFY(pRange = m_worksheet.Range(COleVariant("A2")).pdispVal); 
    //m_range[1].AttachDispatch(pRange); 

    //VERIFY(pRange = m_worksheet.Range(COleVariant("A3")).pdispVal); 
    //m_range[2].AttachDispatch(pRange); 

    //VERIFY(pRange = m_app.GetActiveCell().pdispVal); //Range(COleVariant("A3"), COleVariant("C5")).pdispVal); //m_worksheet.Range(COleVariant("A3"), COleVariant("C5")).pdispVal); 
    //m_range[3].AttachDispatch(pRange); 

    //VERIFY(pRange = m_worksheet.Range(COleVariant("A6")).pdispVal); 
    //m_range[4].AttachDispatch(pRange);
    //m_range[4].SetValue(COleVariant(COleDateTime(1994, 4, 24, 15, 47, 8))); 

    //COleVariant vaTimeDate = m_range[4].GetValue(); 
    //TRACE("returned date type = %d\n", vaTimeDate.vt); 

    //COleVariant vaTemp; 
    //vaTemp.ChangeType(VT_BSTR, &vaTimeDate); 
    //CString str = vaTemp.bstrVal; 
    //TRACE("date = %s\n", (const char*)str); 

    //m_range[0].SetValue(COleVariant("test string")); 
    //COleVariant vaResult0 = m_range[0].GetValue(); 
    //if(vaResult0.vt == VT_BSTR)
    //{
    //    CString str = vaResult0.bstrVal; 
    //    TRACE("vaResult0 = %s\n", (const char*)str); 
    //}

    m_range[0].SetValue(COleVariant(3.14159)); 
    COleVariant vaResult1 = m_range[0].GetValue(); 
    if(vaResult1.vt == VT_R8)
        TRACE("vaResult1 = %f\n", vaResult1.dblVal); 

    //m_range[2].SetFormula(COleVariant("=$A1*2.0")); 
    //COleVariant vaResult2 = m_range[2].GetValue(); 
    //if(vaResult2.vt == VT_R8)
    //    TRACE("vaResult2 = %f\n", vaResult2.dblVal); 

    //COleVariant vaResult3 = m_range[2].GetFormula(); 
    //if(vaResult3.vt == VT_BSTR)
    //{
    //    CString str = vaResult3.bstrVal; 
    //    TRACE("vaResult3 = %s\n", (const char*)str); 
    //}

    //m_range[3].FillRight(); 
    //m_range[3].FillDown(); 

    //if(pWorkbook)
    //    pWorkbook->Release(); 


}

void CDemoView::OnUpdateExecuteExcel(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_app.m_lpDispatch != NULL); 
}
