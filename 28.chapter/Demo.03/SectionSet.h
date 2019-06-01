#if !defined(AFX_SECTIONSET_H__9141CD62_5FBF_4DFD_80F3_37333B80D27A__INCLUDED_)
#define AFX_SECTIONSET_H__9141CD62_5FBF_4DFD_80F3_37333B80D27A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SectionSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSectionSet recordset

class CSectionSet : public CRecordset
{
public:
	CSectionSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CSectionSet)

// Field/Param Data
	//{{AFX_FIELD(CSectionSet, CRecordset)
	CString	m_CourseID;
	CString	m_SectionNo;
	CString	m_InstructorID;
	CString	m_RoomNo;
	CString	m_Schedule;
	int		m_Capacity;
	//}}AFX_FIELD
    CString m_InstructorIDParam; 


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSectionSet)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SECTIONSET_H__9141CD62_5FBF_4DFD_80F3_37333B80D27A__INCLUDED_)
