// CntrItem.h : interface of the CEx32aCntrItem class
//

#if !defined(AFX_CNTRITEM_H__EAB5529B_998C_46AE_BFDA_C72FF96E913B__INCLUDED_)
#define AFX_CNTRITEM_H__EAB5529B_998C_46AE_BFDA_C72FF96E913B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CEx32aDoc;
class CEx32aView;

class CEx32aCntrItem : public CRichEditCntrItem
{
	DECLARE_SERIAL(CEx32aCntrItem)

// Constructors
public:
	CEx32aCntrItem(REOBJECT* preo = NULL, CEx32aDoc* pContainer = NULL);
		// Note: pContainer is allowed to be NULL to enable IMPLEMENT_SERIALIZE.
		//  IMPLEMENT_SERIALIZE requires the class have a constructor with
		//  zero arguments.  Normally, OLE items are constructed with a
		//  non-NULL document pointer.

// Attributes
public:
	CEx32aDoc* GetDocument()
		{ return (CEx32aDoc*)CRichEditCntrItem::GetDocument(); }
	CEx32aView* GetActiveView()
		{ return (CEx32aView*)CRichEditCntrItem::GetActiveView(); }

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx32aCntrItem)
	public:
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	~CEx32aCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CNTRITEM_H__EAB5529B_998C_46AE_BFDA_C72FF96E913B__INCLUDED_)
