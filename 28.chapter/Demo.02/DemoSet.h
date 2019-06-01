// DemoSet.h : interface of the CDemoSet class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEMOSET_H__1AE29127_077E_4273_88D4_ED792C8DFA27__INCLUDED_)
#define AFX_DEMOSET_H__1AE29127_077E_4273_88D4_ED792C8DFA27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDemoSet : public CRecordset
{
public:
	CDemoSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CDemoSet)

// Field/Param Data
	//{{AFX_FIELD(CDemoSet, CRecordset)
	CString	m_InstructorID;
	CString	m_Name;
	CString	m_RoomNo;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoSet)
	public:
	virtual CString GetDefaultConnect();	// Default connection string
	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMOSET_H__1AE29127_077E_4273_88D4_ED792C8DFA27__INCLUDED_)

