#if !defined(AFX_DEMOSET_H__6A4CE690_43E2_41F0_B559_EEFF437E6136__INCLUDED_)
#define AFX_DEMOSET_H__6A4CE690_43E2_41F0_B559_EEFF437E6136__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DemoSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDemoSet recordset

class CDemoSet : public CRecordset
{
public:
	CDemoSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CDemoSet)

// Field/Param Data
	//{{AFX_FIELD(CDemoSet, CRecordset)
	long	m_StudentID;
	CString	m_Name;
	int		m_GradYear;
	CString	m_CourseID;
	CString	m_Grade;
	CString	m_SectionNo;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoSet)
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

#endif // !defined(AFX_DEMOSET_H__6A4CE690_43E2_41F0_B559_EEFF437E6136__INCLUDED_)
