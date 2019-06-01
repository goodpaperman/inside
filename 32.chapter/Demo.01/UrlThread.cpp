
#include "stdafx.h"

CString g_strURL = "http://localhost/test.txt"; 
volatile BOOL g_bThreadStarted = FALSE; 
CEvent g_eKill; 


void LogInternetException(LPVOID pParam, CInternetException* pe)
{ // pParam holds the HWND for the destination window (in another thread)
 CString strGmt = CTime::GetCurrentTime().FormatGmt("%m/%d/%y %H:%M:% GMT");
 char text1[300], text2[100];
 wsprintf(text1, "CLIENT ERROR: WinInet error #%d -- %s\r\n   ",
  pe->m_dwError, (const char*) strGmt);
 pe->GetErrorMessage(text2, 99);
 strcat(text1, text2);
 if(pe->m_dwError == 12152) {
  strcat(text1, "  URL not found?\r\n");
 }
 ::SendMessage((HWND) pParam, EM_SETSEL, (WPARAM) 65534, 65535);
 ::SendMessage((HWND) pParam, EM_REPLACESEL, (WPARAM) 0, (LPARAM) text1);
}


UINT UrlThreadProc(LPVOID pParam)
{
    g_bThreadStarted = TRUE; 
    CString strLine; 
    CInternetSession session; 
    CStdioFile* pFile1 = NULL; 

    try
    {
        pFile1 = session.OpenURL(g_strURL, 0, INTERNET_FLAG_TRANSFER_BINARY | 
            INTERNET_FLAG_KEEP_CONNECTION); 

        while(::WaitForSingleObject(g_eKill.m_hObject, 0) != WAIT_OBJECT_0)
        {
            if(pFile1->ReadString(strLine) == FALSE)
                break; 

            strLine += '\n'; 
            ::SendMessage((HWND)pParam, EM_SETSEL, (WPARAM)999999, 1000000); 
            ::SendMessage((HWND)pParam, EM_REPLACESEL, (WPARAM)0, (LPARAM)(const char*)strLine); 
            Sleep(250); 
        }
    }
    catch(CInternetException* e)
    {
        LogInternetException(pParam, e); 
        e->Delete(); 
    }

    if(pFile1 != NULL)
        delete pFile1; 

    g_bThreadStarted = FALSE; 
    ::PostMessage((HWND)pParam, EM_SETSEL, (WPARAM)999999, (LPARAM)1000000); 
    return 0; 
}
