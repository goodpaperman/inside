// MyMonikerFile.cpp: implementation of the CMyMonikerFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Demo.h"
#include "MyMonikerFile.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyMonikerFile::CMyMonikerFile()
{

}

CMyMonikerFile::~CMyMonikerFile()
{

}


void CMyMonikerFile::OnDataAvailable(DWORD dwSize, DWORD bscfFlag)
{
    try
    {
        UINT nBytesRead = Read(m_buf, 4095); 
        TRACE("nBytesRead = %d\n", nBytesRead); 
        m_buf[nBytesRead] = '\0'; 
        SendMessage(m_hwndEdit, EM_SETSEL, (WPARAM)999999, 1000000); 
        SendMessage(m_hwndEdit, EM_REPLACESEL, (WPARAM)0, (LPARAM)m_buf); 
    }
    catch(CFileException* pe)
    {
        TRACE("File exception %d\n", pe->m_cause); 
        pe->Delete(); 
    }
}