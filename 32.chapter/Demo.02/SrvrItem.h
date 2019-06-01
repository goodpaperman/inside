// SrvrItem.h : interface of the CEx32bSrvrItem class
//

#if !defined(AFX_SRVRITEM_H__41E542F1_763C_413E_BC32_FCACC65992BE__INCLUDED_)
#define AFX_SRVRITEM_H__41E542F1_763C_413E_BC32_FCACC65992BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CEx32bSrvrItem : public CDocObjectServerItem
{
	DECLARE_DYNAMIC(CEx32bSrvrItem)

// Constructors
public:
	CEx32bSrvrItem(CEx32bDoc* pContainerDoc);

// Attributes
	CEx32bDoc* GetDocument() const
		{ return (CEx32bDoc*)CDocObjectServerItem::GetDocument(); }

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx32bSrvrItem)
	public:
	virtual BOOL OnDraw(CDC* pDC, CSize& rSize);
	virtual BOOL OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize);
	//}}AFX_VIRTUAL

// Implementation
public:
	~CEx32bSrvrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SRVRITEM_H__41E542F1_763C_413E_BC32_FCACC65992BE__INCLUDED_)
