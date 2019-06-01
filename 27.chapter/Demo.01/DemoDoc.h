// DemoDoc.h : interface of the CDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEMODOC_H__E2C7FF60_DEBC_41C4_852E_BADF5C70C32E__INCLUDED_)
#define AFX_DEMODOC_H__E2C7FF60_DEBC_41C4_852E_BADF5C70C32E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDemoSrvrItem;

class CDemoDoc : public COleServerDoc
{
protected: // create from serialization only
	CDemoDoc();
	DECLARE_DYNCREATE(CDemoDoc)

// Attributes
public:
	CDemoSrvrItem* GetEmbeddedItem()
		{ return (CDemoSrvrItem*)COleServerDoc::GetEmbeddedItem(); }

// Operations
public:
	CString m_strText; 

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoDoc)
	protected:
	virtual COleServerItem* OnGetEmbeddedItem();
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
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
	afx_msg void OnModify();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMODOC_H__E2C7FF60_DEBC_41C4_852E_BADF5C70C32E__INCLUDED_)
