// SectionSet.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "SectionSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSectionSet

IMPLEMENT_DYNAMIC(CSectionSet, CRecordset)

CSectionSet::CSectionSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CSectionSet)
	m_CourseID = _T("");
	m_SectionNo = _T("");
	m_InstructorID = _T("");
	m_RoomNo = _T("");
	m_Schedule = _T("");
	m_Capacity = 0;
	m_nFields = 6;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;
    m_nParams = 1; \
}


CString CSectionSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Student Registration");
}

CString CSectionSet::GetDefaultSQL()
{
	return _T("[Section]");
}

void CSectionSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CSectionSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[CourseID]"), m_CourseID);
	RFX_Text(pFX, _T("[SectionNo]"), m_SectionNo);
	RFX_Text(pFX, _T("[InstructorID]"), m_InstructorID);
	RFX_Text(pFX, _T("[RoomNo]"), m_RoomNo);
	RFX_Text(pFX, _T("[Schedule]"), m_Schedule);
	RFX_Int(pFX, _T("[Capacity]"), m_Capacity);
    pFX->SetFieldType(CFieldExchange::param); 
    RFX_Text(pFX, _T("Param"), m_InstructorIDParam); 
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CSectionSet diagnostics

#ifdef _DEBUG
void CSectionSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CSectionSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
