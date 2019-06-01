// DemoView.cpp : implementation of the CDemoView class
//

#include "stdafx.h"
#include "Demo.h"
#include "mainfrm.h"

#include "DemoDoc.h"
#include "DemoView.h"
#include "Utility.h"
#include "SheetConfig.h"
#include "BlockSock.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CBlockingSocket g_sListen;//ȫ�ּ�������
/////////////////////////////////////////////////////////////////////////////
// CDemoView

IMPLEMENT_DYNCREATE(CDemoView, CEditView)

BEGIN_MESSAGE_MAP(CDemoView, CEditView)
	//{{AFX_MSG_MAP(CDemoView)
 ON_COMMAND(ID_INTERNET_START_SERVER, OnInternetStartServer)
 ON_UPDATE_COMMAND_UI(ID_INTERNET_START_SERVER, OnUpdateInternetStartServer)
 ON_COMMAND(ID_INTERNET_REQUEST_SOCK, OnInternetRequestSocket)
 ON_COMMAND(ID_INTERNET_REQUEST_INET, OnInternetRequestWininet)
 ON_COMMAND(ID_INTERNET_STOP_SERVER, OnInternetStopServer)
 ON_UPDATE_COMMAND_UI(ID_INTERNET_STOP_SERVER, OnUpdateInternetStopServer)
 ON_COMMAND(ID_INTERNET_CONFIGURATION, OnInternetConfiguration)
 ON_UPDATE_COMMAND_UI(ID_INTERNET_CONFIGURATION, OnUpdateInternetConfiguration)
 ON_COMMAND(ID_EDIT_CLEAR_ALL, OnEditClearAll)
 ON_COMMAND(IDC_REQUEST, OnRequest)
 ON_WM_CONTEXTMENU()
	//}}AFX_MSG_MAP
 ON_COMMAND(ID_FILE_PRINT, CEditView::OnFilePrint)
 ON_COMMAND(ID_FILE_PRINT_DIRECT, CEditView::OnFilePrint)
 ON_COMMAND(ID_FILE_PRINT_PREVIEW, CEditView::OnFilePrintPreview)
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

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping
	 cs.style |= ES_READONLY;//ʹ�ĵ�ֻ��
	return bPreCreated;
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
// CDemoView printing

BOOL CDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
 // default CEditView preparation
 return CEditView::OnPreparePrinting(pInfo);
}

void CDemoView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
 // Default CEditView begin printing.
 CEditView::OnBeginPrinting(pDC, pInfo);
}

void CDemoView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
 // Default CEditView end printing
 CEditView::OnEndPrinting(pDC, pInfo);
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView diagnostics

#ifdef _DEBUG
void CDemoView::AssertValid() const
{
	CEditView::AssertValid();
}

void CDemoView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CDemoDoc* CDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDemoDoc)));
	return (CDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDemoView message handlers

void CDemoView::OnInternetStartServer() 
{
 try {
  CSockAddr saServer;
  if(g_strIPServer.IsEmpty()) { // first or only IP
   saServer = CSockAddr(INADDR_ANY, (USHORT) g_nPortServer);//ָ���������׽���
  }
  else { // if our computer has multiple IP addresses...
   saServer = CSockAddr(g_strIPServer, (USHORT) g_nPortServer);//ָ���������׽���
  }
  g_sListen.Create();
  g_sListen.Bind(saServer);
  g_sListen.Listen();//��ʼ����
  g_bListening = TRUE;//����״̬Ϊ��
  g_nConnection = 0;
  AfxBeginThread(ServerThreadProc, GetSafeHwnd(), THREAD_PRIORITY_NORMAL);//THREAD_PRIORITY_NORMAL�趨���ȼ�
 }
 catch(CBlockingSocketException* e) {
  g_sListen.Cleanup();//ע��������Cleanup()������Close(),Ϊ���������
  LogBlockingSocketException(GetSafeHwnd(), "VIEW:", e);
  e->Delete();
 }
}

void CDemoView::OnUpdateInternetStartServer(CCmdUI* pCmdUI) 
{
 pCmdUI->Enable(!g_bListening);
}

void CDemoView::OnInternetRequestSocket() 
{
 AfxBeginThread(ClientSocketThreadProc, GetSafeHwnd(), THREAD_PRIORITY_NORMAL);
}

void CDemoView::OnInternetRequestWininet() 
{
 AfxBeginThread(ClientWinInetThreadProc, GetSafeHwnd(), THREAD_PRIORITY_NORMAL);
}

void CDemoView::OnInternetStopServer() 
{
 try {
  if(g_bListening) {
   g_sListen.Close();//ֹͣ����
  }
 }
 catch(CBlockingSocketException* e) {
  LogBlockingSocketException(GetSafeHwnd(), "VIEW:", e);
  e->Delete();
 }
}

void CDemoView::OnUpdateInternetStopServer(CCmdUI* pCmdUI) 
{
 pCmdUI->Enable(g_bListening);
}


void CDemoView::OnInternetConfiguration() 
{
 CSheetConfig sh("Configuration");//��ʼ�����Ա�Ի���
 sh.m_pageServer.m_strDirect = g_strDirect;
 sh.m_pageServer.m_strDefault = g_strDefault;
 sh.m_pageServer.m_nPortServer = g_nPortServer;
 sh.m_pageClient.m_strServerIP = g_strServerIP;
 sh.m_pageClient.m_nPort = g_nPort;
 sh.m_pageClient.m_strServerName = g_strServerName;
 sh.m_pageClient.m_strFile = g_strFile;
 sh.m_pageClient.m_strProxy = g_strProxy;
 sh.m_pageClient.m_bUseProxy = g_bUseProxy;
 sh.m_pageAdv.m_strIPClient = g_strIPClient;
 sh.m_pageAdv.m_strIPServer = g_strIPServer;

 if(sh.DoModal() == IDOK) //��ʾ���Ա�Ի���
 {
  g_strDirect = sh.m_pageServer.m_strDirect;
  g_strDefault = sh.m_pageServer.m_strDefault;
  g_nPortServer = sh.m_pageServer.m_nPortServer;
  g_strServerIP = sh.m_pageClient.m_strServerIP;
  g_nPort = sh.m_pageClient.m_nPort;
  g_strServerName = sh.m_pageClient.m_strServerName;
  if(sh.m_pageClient.m_strFile.IsEmpty()) {
   g_strFile = "/";
  }
  else {
   g_strFile = sh.m_pageClient.m_strFile;
  }
  g_strProxy = sh.m_pageClient.m_strProxy;
  g_bUseProxy = sh.m_pageClient.m_bUseProxy;
  g_strIPClient = sh.m_pageAdv.m_strIPClient;
  g_strIPServer = sh.m_pageAdv.m_strIPServer;

  if(!g_strIPClient.IsEmpty() && g_bUseProxy) {
   AfxMessageBox("Warning: you can't assign a client IP address if "
    "you are using a proxy server");
  }
  if(!g_strServerIP.IsEmpty() && g_bUseProxy) {
   AfxMessageBox("Warning: you must specify the server by name if "
    "you are using a proxy server");
  }
  if(g_strServerIP.IsEmpty() && g_strServerName.IsEmpty()) {
   AfxMessageBox("Warning: you must specify either a server name or "
    "a server IP address");
  }
  if(!g_strServerIP.IsEmpty() && !g_strServerName.IsEmpty()) {
   AfxMessageBox("Warning: you cannot specify both a server name "
    "and a server IP address");
  }
  ::SetCurrentDirectory(g_strDirect);//������ǰĿ¼����Ϊg_strDirect
 }
}

void CDemoView::OnUpdateInternetConfiguration(CCmdUI* pCmdUI) 
{
 pCmdUI->Enable(!g_bListening);//�ڷǼ���״̬�²ſɸ�������
}

void CDemoView::OnEditClearAll() 
{
 SetWindowText("");//����ı�
}

void CDemoView::OnRequest() 
{
 CWnd& rBar = ((CMainFrame*) AfxGetApp()->m_pMainWnd)->m_wndDialogBar;//�õ��Ի���������ַ
 rBar.GetDlgItemText(IDC_URL, g_strURL);
 TRACE("CDemoView::OnRequest -- URL = %s\n", (const char*) g_strURL);
 AfxBeginThread(ClientUrlThreadProc, GetSafeHwnd(), THREAD_PRIORITY_NORMAL);//�������߳�
}

void CDemoView::OnContextMenu(CWnd* pWnd, CPoint point) //ʵ���Ҽ������˵�
{
 // clear-all menu activated on right button
 CMenu menu;
 menu.LoadMenu(IDR_CONTEXT_MENU);
 menu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON,
  point.x, point.y, this);
}

