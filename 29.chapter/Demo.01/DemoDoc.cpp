// DemoDoc.cpp : implementation of the CDemoDoc class
//

#include "stdafx.h"
#include "Demo.h"

#include "DemoDoc.h"
#include "MainFrm.h"
#include "TableSelect.h"
#include "IsamSelect.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoDoc

IMPLEMENT_DYNCREATE(CDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CDemoDoc)
	ON_COMMAND(ID_FILE_OPEN_ODBC, OnFileOpenOdbc)
	ON_COMMAND(ID_FILE_OPEN_ISAM, OnFileOpenIsam)
	ON_COMMAND(ID_FILE_OPEN_MDB, OnFileOpenMdb)
	ON_COMMAND(ID_FILE_DISCONNECT, OnFileDisconnect)
	//}}AFX_MSG_MAP
    ON_COMMAND(IDC_REQUERY, OnRequery) 
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoDoc construction/destruction

CDemoDoc::CDemoDoc()
{
	// TODO: add one-time construction code here

}

CDemoDoc::~CDemoDoc()
{
}

BOOL CDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDemoDoc serialization

void CDemoDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
        ar << m_strConnect << m_strDatabase << m_strQuery; 
	}
	else
	{
		// TODO: add loading code here
        ar >> m_strConnect >> m_strDatabase >> m_strQuery; 
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDemoDoc diagnostics

#ifdef _DEBUG
void CDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDemoDoc commands

BOOL CDemoDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// TODO: Add your specialized creation code here
	PutQuery(); 
    switch(m_nDatabaseType)
    {
    case UNK:
        break; 
    case MDB:
        DaoOpenMdb(); 
        break; 
    case ISAM:
        DaoOpenIsam(); 
        break; 
    case ODBC:
        DaoOpenOdbc(); 
        break; 
    }

	return TRUE;
}

void CDemoDoc::OnCloseDocument() 
{
	// TODO: Add your specialized code here and/or call the base class
    m_strQuery.Empty(); 
    PutQuery(); 
    if(m_bConnected)
    {
        delete m_pRecordset; 
        m_database.Close(); 
        m_bConnected = FALSE; 
        m_pRecordset = NULL; 
        m_nRowCount = 0; 
    }

	CDocument::OnCloseDocument();
}

void CDemoDoc::OnFileOpenOdbc() 
{
	// TODO: Add your command handler code here
	m_strConnect.Empty(); 
    m_strQuery.Empty(); 
    DaoOpenOdbc(); 
}

void CDemoDoc::DaoOpenOdbc()
{
    if(m_strConnect.IsEmpty())
        m_strConnect = "ODBC;"; 

    BeginWaitCursor(); 
    
    try
    {
        m_database.Open("", FALSE, TRUE, m_strConnect); 
    }
    catch(CDaoException* e)
    {
        e->ReportError(); 
        e->Delete(); 
        EndWaitCursor(); 
        return; 
    }

    m_strConnect = m_database.GetConnect(); 
    TRACE("database name = %s, connect = %s\n", 
        (const char*)m_strDatabase, 
        (const char*)m_strConnect); 
    
    OpenRecordset(); 
    m_nDatabaseType = ODBC; 
    EndWaitCursor(); 
}

void CDemoDoc::OnFileOpenIsam() 
{
	// TODO: Add your command handler code here
    m_strConnect.Empty(); 
    m_strQuery.Empty(); 
    DaoOpenIsam(); 
}

void CDemoDoc::DaoOpenIsam()
{
    BeginWaitCursor(); 
    
    if(m_strConnect.IsEmpty())
    {
        CIsamSelect isamDlg; 
        if(isamDlg.DoModal() != IDOK)
            return; 

        m_strConnect = isamDlg.m_strIsam + ";DATABASE=" + isamDlg.m_strDirectory; 
        TRACE("m_strConnect = %s\n", (const char*)m_strConnect); 
    }

    try
    {
        m_database.Open("", FALSE, TRUE, m_strConnect); 
    }
    catch(CDaoException* e)
    {
        e->ReportError(); 
        e->Delete(); 
        EndWaitCursor(); 
        return; 
    }

    m_strConnect = m_database.GetConnect(); 
    TRACE("database name = %s, connect = %s\n", 
        (const char*)m_strDatabase, 
        (const char*)m_strConnect); 

    OpenRecordset(); 
    m_nDatabaseType = ISAM; 
    EndWaitCursor(); 
}

void CDemoDoc::OnFileOpenMdb() 
{
	// TODO: Add your command handler code here
	m_strDatabase.Empty(); 
    m_strQuery.Empty(); 
    DaoOpenMdb(); 
}

void CDemoDoc::DaoOpenMdb()
{
    if(m_strDatabase.IsEmpty())
    {
        CFileDialog dlg(TRUE, ".mdb", "*.mdb"); 
        if(dlg.DoModal() == IDCANCEL)
            return; 

        m_strDatabase = dlg.GetPathName(); 
    }

    BeginWaitCursor(); 

    try
    {
        m_database.Open(m_strDatabase, FALSE, TRUE); 
    }
    catch(CDaoException* e)
    {
        e->ReportError(); 
        e->Delete(); 
        EndWaitCursor(); 
        return; 
    }

    m_strDatabase = m_database.GetName(); 
    TRACE("database name = %s, connect = %s\n", 
        (const char*)m_strDatabase, 
        (const char*)m_strConnect); 

    OpenRecordset(); 
    m_nDatabaseType = MDB; 
    EndWaitCursor(); 
}

void CDemoDoc::OnFileDisconnect() 
{
	// TODO: Add your command handler code here
	if(m_bConnected)
    {
        delete m_pRecordset; 
        m_database.Close(); 
        m_bConnected = FALSE; 
        m_pRecordset = NULL; 
        m_nRowCount = 0; 
        UpdateAllViews(NULL); 
    }
}

void CDemoDoc::OpenRecordset()
{
    GetQuery(); 
    if(m_strQuery.IsEmpty())
    {
        CTableSelect tableDlg(&m_database); 
        if(tableDlg.DoModal() != IDOK)
        {
            m_database.Close(); 
            return; 
        }

        m_strQuery.Format("select * form [%s]", tableDlg.m_strSelection); 
        PutQuery(); 
    }

    m_pRecordset = new CDaoRecordset(&m_database); 
    
    try
    {
        m_pRecordset->Open(dbOpenDynaset, m_strQuery, dbReadOnly); 
    }
    catch(CDaoException* e)
    {
        e->ReportError(); 
        e->Delete(); 
        UpdateAllViews(NULL); 
        m_bConnected = FALSE; 
        return; 
    }

    if(!m_pRecordset->IsBOF())
        m_pRecordset->MoveLast(); 

    m_nRowCount = m_pRecordset->GetAbsolutePosition() + 2; 
    TRACE("m_nRowCount = %d\n", m_nRowCount); 
    GetFieldSpecs(); 
    UpdateAllViews(NULL); 
    m_bConnected = TRUE; 
}

void CDemoDoc::OnRequery()
{
    GetQuery(); 
    BeginWaitCursor(); 

    if(m_pRecordset->IsOpen())
        m_pRecordset->Close(); 

    try
    {
        m_pRecordset->Open(dbOpenDynaset, m_strQuery, dbReadOnly); 
    }
    catch(CDaoException* e)
    {
        e->ReportError(); 
        e->Delete(); 
        m_nRowCount = 0; 
        UpdateAllViews(NULL); 
        EndWaitCursor(); 
        return; 
    }

    if(!m_pRecordset->IsBOF())
        m_pRecordset->MoveLast(); 

    m_nRowCount = m_pRecordset->GetAbsolutePosition() + 2; 
    TRACE("m_nRowCount = %d\n", m_nRowCount); 
    GetFieldSpecs(); 
    UpdateAllViews(NULL); 
    EndWaitCursor(); 
}

void CDemoDoc::PutQuery()
{
    CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd(); 
    pFrame->m_wndMyBar.SetDlgItemText(IDC_SQL, m_strQuery); 
}

void CDemoDoc::GetQuery()
{
    CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd(); 
    pFrame->m_wndMyBar.GetDlgItemText(IDC_SQL, m_strQuery); 
}

void CDemoDoc::GetFieldSpecs()
{
    m_nFields = m_pRecordset->GetFieldCount(); 
    m_arrayFieldName.SetSize(m_nFields); 
    m_arrayFieldSize.SetSize(m_nFields); 
    for(int i=0; i<m_nFields; i++)
    {
        CDaoFieldInfo dfi; 
        m_pRecordset->GetFieldInfo(i, dfi); 
        m_arrayFieldName[i] = dfi.m_strName; 
        m_arrayFieldSize[i] = dfi.m_lSize; 
    }
}