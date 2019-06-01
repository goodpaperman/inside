// MyMonikerFile.h: interface for the CMyMonikerFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYMONIKERFILE_H__91E91086_71D5_4831_B2EB_47B830EC7B0F__INCLUDED_)
#define AFX_MYMONIKERFILE_H__91E91086_71D5_4831_B2EB_47B830EC7B0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMyMonikerFile : public CAsyncMonikerFile  
{
public:
	CMyMonikerFile();
	virtual ~CMyMonikerFile();
	virtual void OnDataAvailable(DWORD dwSize, DWORD bscfFlag);

    BYTE m_buf[4096]; 
    HWND m_hwndEdit; 
};

#endif // !defined(AFX_MYMONIKERFILE_H__91E91086_71D5_4831_B2EB_47B830EC7B0F__INCLUDED_)
