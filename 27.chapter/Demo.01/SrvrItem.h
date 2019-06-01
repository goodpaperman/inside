// SrvrItem.h : interface of the CDemoSrvrItem class
//

#if !defined(AFX_SRVRITEM_H__7A876367_EBE8_4F30_A64F_104C5304A32B__INCLUDED_)
#define AFX_SRVRITEM_H__7A876367_EBE8_4F30_A64F_104C5304A32B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDemoSrvrItem : public COleServerItem
{
	DECLARE_DYNAMIC(CDemoSrvrItem)

// Constructors
public:
	CDemoSrvrItem(CDemoDoc* pContainerDoc);

// Attributes
	CDemoDoc* GetDocument() const
		{ return (CDemoDoc*)COleServerItem::GetDocument(); }

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoSrvrItem)
	public:
	virtual BOOL OnDraw(CDC* pDC, CSize& rSize);
	virtual BOOL OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize);
	//}}AFX_VIRTUAL

// Implementation
public:
	~CDemoSrvrItem();
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

#endif // !defined(AFX_SRVRITEM_H__7A876367_EBE8_4F30_A64F_104C5304A32B__INCLUDED_)
