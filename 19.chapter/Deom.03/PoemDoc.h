// PoemDoc.h : interface of the CPoemDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_POEMDOC_H__8A5D4B8A_707E_4D1C_84EC_16CC6BEC8F5A__INCLUDED_)
#define AFX_POEMDOC_H__8A5D4B8A_707E_4D1C_84EC_16CC6BEC8F5A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPoemDoc : public CDocument
{
protected: // create from serialization only
	CPoemDoc();
	DECLARE_DYNCREATE(CPoemDoc)

// Attributes
public:
	CStringArray m_stringArray; 

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPoemDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void DeleteContents();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPoemDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPoemDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POEMDOC_H__8A5D4B8A_707E_4D1C_84EC_16CC6BEC8F5A__INCLUDED_)
