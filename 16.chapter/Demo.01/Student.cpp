// Student.cpp: implementation of the CStudent class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Demo.h"
#include "Student.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_SERIAL(CStudent, CObject, 0) 

#ifdef _DEBUG

void CStudent::Dump(CDumpContext& dc) const
{
	CObject::Dump(dc); 
	dc << " m_strName = " << m_strName << "\nm_nGrade = " << m_nGrade; 
}

#endif

void CStudent::Serialize(CArchive& ar)
{
	TRACE("Entering CStudent::Serialize\n"); 
	if(ar.IsStoring())
		ar << m_strName << m_nGrade; 
	else 
		ar >> m_strName >> m_nGrade; 
}