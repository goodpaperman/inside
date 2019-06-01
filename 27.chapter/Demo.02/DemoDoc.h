// DemoDoc.h : interface of the CDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEMODOC_H__B8901A63_113E_4FFC_B90A_E7F59A5F621E__INCLUDED_)
#define AFX_DEMODOC_H__B8901A63_113E_4FFC_B90A_E7F59A5F621E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

void ITrace(REFIID iid, const char* str); 

class CDemoDoc : public COleDocument
{
    friend class CDemoView; 
protected: // create from serialization only
	CDemoDoc();
	DECLARE_DYNCREATE(CDemoDoc)

    BEGIN_INTERFACE_PART(OleClientSite, IOleClientSite)
        STDMETHOD(SaveObject)(); 
        STDMETHOD(GetMoniker)(DWORD, DWORD, LPMONIKER*); 
        STDMETHOD(GetContainer)(LPOLECONTAINER*); 
        STDMETHOD(ShowObject)(); 
        STDMETHOD(OnShowWindow)(BOOL); 
        STDMETHOD(RequestNewObjectLayout)(); 
    END_INTERFACE_PART(OleClientSite) 

    BEGIN_INTERFACE_PART(AdviseSink, IAdviseSink)
        STDMETHOD_(void, OnDataChange)(LPFORMATETC, LPSTGMEDIUM); 
        STDMETHOD_(void, OnViewChange)(DWORD, LONG); 
        STDMETHOD_(void, OnRename)(LPMONIKER); 
        STDMETHOD_(void, OnSave)(); 
        STDMETHOD_(void, OnClose)(); 
    END_INTERFACE_PART(AdviseSink) 

    DECLARE_INTERFACE_MAP() 

// Attributes
public:
	LPOLEOBJECT m_lpOleObj; 
	LPSTORAGE m_pTempStgRoot; 
	LPSTORAGE m_pTempStgSub; 
	BOOL m_bHatch; 
	static const OLECHAR* s_szSub; 

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void OnCloseDocument();
	virtual void DeleteContents();
	protected:
	virtual BOOL SaveModified();
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
	afx_msg void OnEditClearAll();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMODOC_H__B8901A63_113E_4FFC_B90A_E7F59A5F621E__INCLUDED_)
