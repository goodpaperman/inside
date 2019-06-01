// Ex32aDoc.h : interface of the CEx32aDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX32ADOC_H__D64F3114_E720_4B90_95EE_EDFA39180BCC__INCLUDED_)
#define AFX_EX32ADOC_H__D64F3114_E720_4B90_95EE_EDFA39180BCC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx32aSrvrItem;

class CEx32aDoc : public CRichEditDoc
{
protected: // create from serialization only
	CEx32aDoc();
	DECLARE_DYNCREATE(CEx32aDoc)

// Attributes
public:
	CEx32aSrvrItem* GetEmbeddedItem()
		{ return (CEx32aSrvrItem*)CRichEditDoc::GetEmbeddedItem(); }

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx32aDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	protected:
	virtual COleServerItem* OnGetEmbeddedItem();
	virtual BOOL SaveModified();
	//}}AFX_VIRTUAL
	virtual CRichEditCntrItem* CreateClientItem(REOBJECT* preo) const;

// Implementation
public:
	virtual ~CEx32aDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual CDocObjectServer* GetDocObjectServer(LPOLEDOCUMENTSITE pDocSite);

// Generated message map functions
protected:
	//{{AFX_MSG(CEx32aDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX32ADOC_H__D64F3114_E720_4B90_95EE_EDFA39180BCC__INCLUDED_)
