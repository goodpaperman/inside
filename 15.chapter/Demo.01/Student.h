// Student.h: interface for the CStudent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STUDENT_H__4EB340D0_599C_49E5_A837_910C11F18B01__INCLUDED_)
#define AFX_STUDENT_H__4EB340D0_599C_49E5_A837_910C11F18B01__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CStudent : public CObject  
{
	DECLARE_DYNAMIC(CStudent)

public:
	CString m_strName; 
	int m_nGrade; 

	CStudent()
	{
		m_nGrade = 0; 
	}

	CStudent(const char* szName, int nGrade) : m_strName(szName)
	{
		m_nGrade = nGrade; 
	}

	CStudent(const CStudent& s) : m_strName(s.m_strName)
	{
		m_nGrade = s.m_nGrade; 
	}

	const CStudent& operator= (const CStudent& s)
	{
		m_strName = s.m_strName; 
		m_nGrade = s.m_nGrade; 
		return *this; 
	}

	BOOL operator== (const CStudent& s) const
	{
		if((m_strName == s.m_strName) && (m_nGrade == s.m_nGrade))
			return TRUE; 
		else 
			return FALSE; 
	}

	BOOL operator!= (const CStudent& s) const
	{
		return !(*this == s); 
	}

#ifdef _DEBUG
	void Dump(CDumpContext& dc) const; 
#endif
};

#endif // !defined(AFX_STUDENT_H__4EB340D0_599C_49E5_A837_910C11F18B01__INCLUDED_)
