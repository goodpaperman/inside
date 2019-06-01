// DemoSet.cpp : implementation file
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
// CDemoSet

IMPLEMENT_DYNAMIC(CDemoSet, CRecordset)

CDemoSet::CDemoSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CDemoSet)
	m_StudentID = 0;
	m_Name = _T("");
	m_GradYear = 0;
	m_CourseID = _T("");
	m_Grade = _T("");
	m_SectionNo = _T("");
	m_nFields = 6;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;
}


CString CDemoSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Student Registration");
}

CString CDemoSet::GetDefaultSQL()
{
	return _T("[Student], [Enrollment]");
}

void CDemoSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CDemoSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[Student].[StudentID]"), m_StudentID);
	RFX_Text(pFX, _T("[Name]"), m_Name);
	RFX_Int(pFX, _T("[GradYear]"), m_GradYear);
	RFX_Text(pFX, _T("[CourseID]"), m_CourseID);
	RFX_Text(pFX, _T("[Grade]"), m_Grade);
	RFX_Text(pFX, _T("[SectionNo]"), m_SectionNo);
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
