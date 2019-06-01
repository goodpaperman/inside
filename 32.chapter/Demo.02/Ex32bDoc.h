// Ex32bDoc.h : interface of the CEx32bDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX32BDOC_H__5AFC5724_6942_41DF_80E1_97488B5479D9__INCLUDED_)
#define AFX_EX32BDOC_H__5AFC5724_6942_41DF_80E1_97488B5479D9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx32bSrvrItem;

class CEx32bDoc : public COleServerDoc
{
protected: // create from serialization only
	CEx32bDoc();
	DECLARE_DYNCREATE(CEx32bDoc)

// Attributes
public:
	CEx32bSrvrItem* GetEmbeddedItem()
		{ return (CEx32bSrvrItem*)COleServerDoc::GetEmbeddedItem(); }

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx32bDoc)
	protected:
	virtual COleServerItem* OnGetEmbeddedItem();
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx32bDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual CDocObjectServer* GetDocObjectServer(LPOLEDOCUMENTSITE pDocSite);

// Generated message map functions
protected:
	//{{AFX_MSG(CEx32bDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX32BDOC_H__5AFC5724_6942_41DF_80E1_97488B5479D9__INCLUDED_)
