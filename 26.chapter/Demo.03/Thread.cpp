#include "StdAfx.h"
#include "Thread.h"
#include "IText.h"

CLSID g_clsid; 
int g_nIndent = 0; 
const char* g_szBlanks = "    "; 
const char* g_szRootStorageName = "\\direct.stg"; 

UINT WriteThreadProc(LPVOID pParam)
{
	USES_CONVERSION; 
	LPSTORAGE pStgRoot = NULL; 
	g_nIndent = 0; 
	::CoInitialize(NULL); 
	::CLSIDFromProgID(L"Demo.Text", &g_clsid); 

	VERIFY(::StgCreateDocfile(T2COLE(g_szRootStorageName), 
		STGM_READWRITE | STGM_SHARE_EXCLUSIVE | STGM_CREATE, 0, &pStgRoot) == S_OK); 
	ReadDirectory("\\", pStgRoot); 
	pStgRoot->Release(); 
	AfxMessageBox("Write Complete"); 
	return 0; 
}

void ReadDirectory(const char* szPath, LPSTORAGE pStg)
{
	USES_CONVERSION; 
	WIN32_FIND_DATA fData; 
	char szNewPath[MAX_PATH]; 
	char szStorageName[100]; 
	char szStreamName[100]; 
	char szData[81]; 
	char* pch = NULL; 

	LPSTORAGE pSubStg = NULL; 
	LPSTREAM pStream = NULL; 
	LPPERSISTSTREAM pPersistStream = NULL; 

	strcpy(szNewPath, szPath); 
	strcat(szNewPath, "*.*"); 
	HANDLE h = ::FindFirstFile(szNewPath, &fData); 
	if(h == INVALID_HANDLE_VALUE)
		return; 

	g_nIndent ++; 
	do
	{
		if(!strcmp(fData.cFileName, "..") ||
			!strcmp(fData.cFileName, "."))
			continue; 
		
		while((pch = strchr(fData.cFileName, '!')) != NULL)
			*pch = '|'; 

		if(fData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			strcpy(szNewPath, szPath); 
			strcat(szNewPath, fData.cFileName); 
			strcat(szNewPath, "\\"); 

			strcpy(szStorageName, fData.cFileName); 
			szStorageName[31] = '\0'; 
			TRACE("%0.*sStorage = %s\n", (g_nIndent-1)*4, g_szBlanks, szStorageName); 
			VERIFY(pStg->CreateStorage(T2COLE(szStorageName), 
				STGM_CREATE | STGM_READWRITE | STGM_SHARE_EXCLUSIVE, 0, 0, &pSubStg) == S_OK); 
			ASSERT(pSubStg != NULL); 
			ReadDirectory(szNewPath, pSubStg); 
			pSubStg->Release(); 
		}
		else 
		{
			if((pch = strchr(fData.cFileName, '.')) != NULL)
			{
				if(!strcmp(pch, ".txt"))
				{
					strcpy(szStreamName, fData.cFileName); 
					strcpy(szNewPath, szPath); 
					strcat(szNewPath, szStreamName); 
					szStreamName[32] = '\0'; 
					TRACE("%0.*sStream = %s\n", (g_nIndent-1)*4, g_szBlanks, szNewPath); 

					CStdioFile file(szNewPath, CFile::modeRead); 
					if(file.ReadString(szData, 80))
					{
						TRACE("%s\n", szData); 
						VERIFY(pStg->CreateStream(T2COLE(szStreamName), 
							STGM_CREATE | STGM_READWRITE | STGM_SHARE_EXCLUSIVE, 0, 0, &pStream) == S_OK); 
						ASSERT(pStream != NULL); 

						IText text; 
						VERIFY(text.CreateDispatch(g_clsid)); 
						text.m_lpDispatch->QueryInterface(IID_IPersistStream, (void**)&pPersistStream); 
						ASSERT(pPersistStream != NULL); 
						text.SetText(COleVariant(szData)); 
						pPersistStream->Save(pStream, TRUE); 
						pPersistStream->Release(); 
						//pStream->Write(szData, strlen(szData) + 1, NULL); 
						pStream->Release(); 
					}
				}
			}
		}

	}while(::FindNextFile(h, &fData)); 
	g_nIndent --; 
}

UINT ReadThreadProc(LPVOID pParam)
{
	USES_CONVERSION; 
	LPSTORAGE pStgRoot = NULL; 
	g_nIndent = 0; 
	::CoInitialize(NULL); 
	::CLSIDFromProgID(L"Demo.Text", &g_clsid); 

	if(::StgOpenStorage(T2COLE(g_szRootStorageName), NULL, 
		STGM_READ | STGM_SHARE_EXCLUSIVE, NULL, 0, &pStgRoot) == S_OK)
	{
		ASSERT(pStgRoot != NULL); 
		ReadStorage(pStgRoot); 
		pStgRoot->Release(); 
	}
	else 
		AfxMessageBox("Storage file not available or not readable"); 

	AfxMessageBox("Read Complete"); 
	return 0; 
}

void ReadStorage(LPSTORAGE pStg)
{
	USES_CONVERSION; 
	LPSTORAGE pSubStg = NULL; 
	LPSTREAM pStream = NULL; 
	LPENUMSTATSTG pEnum = NULL; 
	//LPMALLOC pMalloc = NULL; 
	LPPERSISTSTREAM pPersistStream = NULL; 
	STATSTG statstg; 
    //ULONG nLength; 
    //BYTE buffer[101]; 

	g_nIndent++; 
	//::CoGetMalloc(MEMCTX_TASK, &pMalloc); 
	if(pStg->EnumElements(0, NULL, 0, &pEnum) != NOERROR)
	{
		ASSERT(FALSE); 
		return; 
	}

	while(pEnum->Next(1, &statstg, NULL) == NOERROR)
	{
		if(statstg.type == STGTY_STORAGE)
		{
			VERIFY(pStg->OpenStorage(statstg.pwcsName, NULL, 
				STGM_READ | STGM_SHARE_EXCLUSIVE, NULL, 0, &pSubStg) == S_OK); 
			ASSERT(pSubStg != NULL); 
			//TRACE("%0.*sStorage = %s\n", (g_nIndent-1)*4, g_szBlanks, OLE2CT(statstg.pwcsName)); 
			ReadStorage(pSubStg); 
			pSubStg->Release(); 
		}
		else if(statstg.type == STGTY_STREAM)
		{
			VERIFY(pStg->OpenStream(statstg.pwcsName, NULL, 
				STGM_READ | STGM_SHARE_EXCLUSIVE, 0, &pStream) == S_OK); 
			ASSERT(pStream != NULL); 
			//TRACE("%0.*sStream = %s\n", (g_nIndent-1)*4, g_szBlanks, OLE2CT(statstg.pwcsName)); 
			IText text; 
			VERIFY(text.CreateDispatch(g_clsid)); 
			text.m_lpDispatch->QueryInterface(IID_IPersistStream, (void**)&pPersistStream); 
			ASSERT(pPersistStream != NULL); 
			pPersistStream->Load(pStream); 
			pPersistStream->Release(); 
			COleVariant va = text.GetText(); 
			ASSERT(va.vt == VT_BSTR); 
			CString str = va.bstrVal; 
			TRACE("%s\n", str); 
            //pStream->Read(buffer, 100, &nLength); 
            //buffer[nLength] = '\0'; 
            //TRACE("%s\n", buffer); 
			pStream->Release(); 
		}
		else 
			ASSERT(FALSE); 

		::CoTaskMemFree(statstg.pwcsName); 
		//pMalloc->Free(statstg.pwcsName); 
	}

	//pMalloc->Release(); 
	pEnum->Release(); 
	g_nIndent--; 
}

