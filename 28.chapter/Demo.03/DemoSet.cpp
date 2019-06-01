// DemoSet.cpp : implementation of the CDemoSet class
//

#include "stdafx.h"
#include "Demo.h"
#include "DemoSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoSet implementation

IMPLEMENT_DYNAMIC(CDemoSet, CRecordset)

CDemoSet::CDemoSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CDemoSet)
	m_InstructorID = _T("");
	m_Name = _T("");
	m_RoomNo = _T("");
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;
}

CString CDemoSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Student Registration");
}

CString CDemoSet::GetDefaultSQL()
{
	return _T("[Instructor]");
}

void CDemoSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CDemoSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[InstructorID]"), m_InstructorID);
	RFX_Text(pFX, _T("[Name]"), m_Name);
	RFX_Text(pFX, _T("[RoomNo]"), m_RoomNo);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CDemoSet diagnostics

#ifdef _DEBUG
void CDemoSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDemoSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
