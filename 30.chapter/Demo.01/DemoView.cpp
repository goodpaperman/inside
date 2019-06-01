// DemoView.cpp : implementation of the CDemoView class
//

#include "stdafx.h"
#include "Demo.h"

#include "DemoDoc.h"
#include "DemoView.h"
#include "blocksock.h" 

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
	ON_COMMAND(ID_START_SERVER, OnStartServer)
	ON_COMMAND(ID_START_CLIENT, OnStartClient)
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

CBlockingSocket g_sListen; 
void CDemoView::OnStartServer() 
{
	// TODO: Add your command handler code here
	try
    {
        CSockAddr saServer(INADDR_ANY, 80); 
        g_sListen.Create(); 
        g_sListen.Bind(saServer); 
        g_sListen.Listen(); 
        AfxBeginThread(ServerThreadProc, GetSafeHwnd()); 
    }
    catch(CBlockingSocketException* e)
    {
        g_sListen.Cleanup(); 
        e->ReportError(); 
        e->Delete(); 
    }
}

UINT ServerThreadProc(LPVOID pParam)
{
    CSockAddr saClient; 
    CHttpBlockingSocket sConnect; 
    char request[100]; 
    char headers[] = "HTTP/1.0 200 OK\r\n"
        "Server: Inside Visual C++ SOCK01\r\n"
        "Date: Thu, 05 Sep 1996 17:33:12 GMT \r\n"
        "Content-Type: text/html\r\n"
        "Accept-Ranges: bytes\r\n"
        "Content-Length: 187\r\n"
        "\r\n"; 
    char html[] = 
        "<html><head><title>Inside Visual C++ Server</title></head>\r\n"
        "<body><body background = \"usa.jpg\">\r\n"
        "<h1><center>This is a custom home page</center></h1><p>\r\n"
        "</body></html>\r\n\r\n"; 

    try
    {
        if(!g_sListen.Accept(sConnect, saClient))
            return 0; 

        AfxBeginThread(ServerThreadProc, pParam); 
        sConnect.ReadHttpHeaderLine(request, 100, 10); 
        TRACE("SERVER: %s", request); 
        if(strnicmp(request, "GET", 3) == 0)
        {
            do
            {
                sConnect.ReadHttpHeaderLine(request, 100, 10); 
                TRACE("SERVER: %s", request); 
            }while(strcmp(request, "\r\n")); 
            sConnect.Write(headers, strlen(headers), 10); 
            sConnect.Write(html, strlen(html), 10); 
        }
        else 
            TRACE("SERVER: not a GET\n"); 

        sConnect.Close(); 
    }
    catch(CBlockingSocketException* e)
    {
        e->ReportError(); 
        e->Delete(); 
    }
    return 0; 
}

void CDemoView::PostNcDestroy() 
{
	// TODO: Add your specialized code here and/or call the base class
	try
    {
        g_sListen.Close(); 
        Sleep(300); 
        WSACleanup(); 
    }
    catch(CUserException* e)
    {
        e->ReportError(); 
        e->Delete(); 
    }

	CView::PostNcDestroy();
}

void CDemoView::OnStartClient() 
{
	// TODO: Add your command handler code here
	AfxBeginThread(ClientSocketThreadProc, GetSafeHwnd()); 
}

CString g_strServerName = "localhost"; 
UINT ClientSocketThreadProc(LPVOID pParam)
{
    CHttpBlockingSocket sClient; 
    char* buffer = new char[100]; 
    int nBytesReceived = 0; 
    char request[] = "GET/ HTTP/1.0\r\n"; 
    char headers[] = 
        "User-Agent: Mozilla/1.22(Windows; U; 32bit)\r\n"
        "Accept:*/*\r\n"
        "Accept: image/gif\r\n"
        "Accept: image/x - xbitmap\r\n"
        "Accept: image/jpeg \r\n"
        "\r\n"; 

    CSockAddr saServer, saClient; 
    try
    {
        sClient.Create(); 
        saServer = CBlockingSocket::GetHostByName(g_strServerName, 80); 
        sClient.Connect(saServer); 
        sClient.Write(request, strlen(request), 10); 
        sClient.Write(headers, strlen(headers), 10); 
        do
        {
            nBytesReceived = sClient.ReadHttpHeaderLine(buffer, 100, 10); 
            TRACE("CLIENT: %s", buffer); 
        }while(strcmp(buffer, "\r\n")); 

        nBytesReceived = sClient.ReadHttpResponse(buffer, 100, 10); 
        TRACE("CLIENT: %s", buffer); 
        if(nBytesReceived == 0)
            AfxMessageBox("No response received."); 
        else 
        {
            buffer[nBytesReceived] = '\0'; 
            AfxMessageBox(buffer); 
        }
    }
    catch(CBlockingSocketException* e)
    {
        e->ReportError(); 
        e->Delete(); 
    }

    sClient.Close(); 
    delete []buffer; 
    return 0; 
}
