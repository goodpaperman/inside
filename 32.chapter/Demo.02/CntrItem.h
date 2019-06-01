// CntrItem.h : interface of the CEx32bCntrItem class
//

#if !defined(AFX_CNTRITEM_H__FA3D0630_D5A6_4780_9FDA_50119D8CD250__INCLUDED_)
#define AFX_CNTRITEM_H__FA3D0630_D5A6_4780_9FDA_50119D8CD250__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CEx32bDoc;
class CEx32bView;

class CEx32bCntrItem : public COleDocObjectItem
{
	DECLARE_SERIAL(CEx32bCntrItem)

// Constructors
public:
	CEx32bCntrItem(CEx32bDoc* pContainer = NULL);
		// Note: pContainer is allowed to be NULL to enable IMPLEMENT_SERIALIZE.
		//  IMPLEMENT_SERIALIZE requires the class have a constructor with
		//  zero arguments.  Normally, OLE items are constructed with a
		//  non-NULL document pointer.

// Attributes
public:
	CEx32bDoc* GetDocument()
		{ return (CEx32bDoc*)COleDocObjectItem::GetDocument(); }
	CEx32bView* GetActiveView()
		{ return (CEx32bView*)COleDocObjectItem::GetActiveView(); }

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx32bCntrItem)
	public:
	virtual void OnChange(OLE_NOTIFICATION wNotification, DWORD dwParam);
	virtual void OnActivate();
	protected:
	virtual void OnDeactivateUI(BOOL bUndoable);
	virtual BOOL OnChangeItemPosition(const CRect& rectPos);
	virtual BOOL CanActivate();
	//}}AFX_VIRTUAL

// Implementation
public:
	~CEx32bCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual void Serialize(CArchive& ar);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CNTRITEM_H__FA3D0630_D5A6_4780_9FDA_50119D8CD250__INCLUDED_)
