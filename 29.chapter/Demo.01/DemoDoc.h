// DemoDoc.h : interface of the CDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEMODOC_H__09310C75_1E10_4A84_9DC5_751F6E41E178__INCLUDED_)
#define AFX_DEMODOC_H__09310C75_1E10_4A84_9DC5_751F6E41E178__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDemoDoc : public CDocument
{
protected: // create from serialization only
	CDemoDoc();
	DECLARE_DYNCREATE(CDemoDoc)

// Attributes
public:
    CDaoRecordset* m_pRecordset; 
    CDaoDatabase m_database; 
    CString m_strDatabase; 
    CString m_strConnect; 
    CString m_strQuery; 
    BOOL m_bConnected; 
    int m_nFields; 
    int m_nRowCount; 
    enum { UNK, MDB, ISAM, ODBC } m_nDatabaseType; 

    CStringArray m_arrayFieldName; 
    CDWordArray m_arrayFieldSize; 

// Operations
public:
    void DaoOpenOdbc(); 
    void DaoOpenIsam(); 
    void DaoOpenMdb(); 
    void OpenRecordset(); 
    void PutQuery(); 
    void GetQuery(); 
    void GetFieldSpecs(); 

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual void OnCloseDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDemoDoc)
	afx_msg void OnFileOpenOdbc();
	afx_msg void OnFileOpenIsam();
	afx_msg void OnFileOpenMdb();
	afx_msg void OnFileDisconnect();
	//}}AFX_MSG
    afx_msg void OnRequery(); 
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMODOC_H__09310C75_1E10_4A84_9DC5_751F6E41E178__INCLUDED_)
