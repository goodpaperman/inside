
// PostThread.cpp (uses MFC Wininet calls)

#include "stdafx.h"

#define MAXBUF 50000
#define WM_POSTCOMPLETE (WM_USER + 6)


CString g_strFile = "/scripts/ex31a.dll"; 
CString g_strServerName = "localhost"; 
CString g_strParameters; 

UINT PostThreadProc(LPVOID pParam)
{
    CInternetSession session; 
    CHttpConnection* pConnection = NULL; 
    CHttpFile* pFile = NULL; 
    char* buffer = new char[MAXBUF]; 
    UINT nBytesRead = 0; 
    DWORD dwStatusCode; 
    BOOL bOK = FALSE; 
    
    try
    {
        pConnection = session.GetHttpConnection(g_strServerName, (INTERNET_PORT)80); 
        pFile = pConnection->OpenRequest(0, g_strFile + "?ProcessTimesheet", 
            NULL, 1, NULL, NULL, INTERNET_FLAG_KEEP_CONNECTION | 
            INTERNET_FLAG_RELOAD); 
        pFile->SendRequest(NULL, 0, (LPVOID)(const char*)g_strParameters, g_strParameters.GetLength()); 
        pFile->QueryInfoStatusCode(dwStatusCode); 
        if(dwStatusCode == 200)
        {
            bOK = TRUE; 
            nBytesRead = pFile->Read(buffer, MAXBUF-1); 
            buffer[nBytesRead] = '\n'; 
            TRACE(buffer); 
            TRACE("\n"); 
        }
    }
    catch(CInternetException* pe)
    {
        char text[100]; 
        pe->GetErrorMessage(text, 99); 
        TRACE("WinInet exception %s\n", text); 
        pe->Delete(); 
    }

    if(pFile)
        delete pFile; 

    if(pConnection)
        delete pConnection; 

    delete[] buffer; 
    ::PostMessage((HWND)pParam, WM_POSTCOMPLETE, (WPARAM)bOK, 0); 
    return 0; 
}