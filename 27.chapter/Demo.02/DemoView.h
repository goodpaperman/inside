// DemoView.h : interface of the CDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEMOVIEW_H__D66D8F2A_2DF5_42EE_BA9B_FEAEFDE3CAFB__INCLUDED_)
#define AFX_DEMOVIEW_H__D66D8F2A_2DF5_42EE_BA9B_FEAEFDE3CAFB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define CF_OBJECTDESCRIPTOR "Object Descriptor"
#define CF_EMBEDDEDOBJECT "Embedded Object"
#define SETFORMATETC(fe, cf, asp, td, med, li) \
    ((fe).cfFormat = cf,  \
     (fe).dwAspect = asp, \
     (fe).ptd = td,       \
     (fe).tymed = med,    \
     (fe).lindex = li)

//#define SETFORMATETC(fe, cf, asp, td, med, li)   \
//   ((fe).cfFormat=cf, \
//    (fe).dwAspect=asp, \
//    (fe).ptd=td, \
//    (fe).tymed=med, \
//    (fe).lindex=li)

class CDemoCntrItem;
class CDemoView : public CScrollView
{
protected: // create from serialization only
	CDemoView();
	DECLARE_DYNCREATE(CDemoView)

// Attributes
public:
	CDemoDoc* GetDocument();
	// m_pSelection holds the selection to the current CDemoCntrItem.
	// For many applications, such a member variable isn't adequate to
	//  represent a selection, such as a multiple selection or a selection
	//  of objects that are not CDemoCntrItem objects.  This selection
	//  mechanism is provided just to help you get started.

	// TODO: replace this selection mechanism with one appropriate to your app.
	//CDemoCntrItem* m_pSelection;

	CLIPFORMAT m_cfObjDesc; 
	CLIPFORMAT m_cfEmbedded; 
	CSize m_sizeTotal; 
	CRectTracker m_tracker; 
    CRect m_rectTracker; 


// Operations
public:
	void GetSize(); 
	void SetNames(); 
	void SetViewAdvise(); 
	BOOL MakeMetafilePict(COleDataSource* pSource); 
	COleDataSource* SaveObject(); 
	BOOL DoPasteObject(COleDataObject* pDataObject); 
	BOOL DoPasteObjectDescriptor(COleDataObject* pDataObject); 

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//virtual BOOL IsSelected(const CObject* pDocItem) const;// Container support
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDemoView)
    //afx_msg void OnDestroy();
    //afx_msg void OnSetFocus(CWnd* pOldWnd);
    //afx_msg void OnSize(UINT nType, int cx, int cy);
    //afx_msg void OnCancelEditCntr();
	afx_msg void OnEditCopy();
	afx_msg void OnUpdateEditCopy(CCmdUI* pCmdUI);
	afx_msg void OnEditCopyTo();
	afx_msg void OnEditCut();
	afx_msg void OnEditPaste();
	afx_msg void OnUpdateEditPaste(CCmdUI* pCmdUI);
	afx_msg void OnEditPasteFrom();
	afx_msg void OnEditInsertObject();
	afx_msg void OnUpdateEditInsertObject(CCmdUI* pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DemoView.cpp
inline CDemoDoc* CDemoView::GetDocument()
   { return (CDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMOVIEW_H__D66D8F2A_2DF5_42EE_BA9B_FEAEFDE3CAFB__INCLUDED_)
