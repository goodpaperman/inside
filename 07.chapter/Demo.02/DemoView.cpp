// DemoView.cpp : implementation of the CDemoView class
//

#include "stdafx.h"
#include "Demo.h"

#include "DemoDoc.h"
#include "DemoView.h"
#include "SpecialFileDlg.h" 

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoView

IMPLEMENT_DYNCREATE(CDemoView, CView)

BEGIN_MESSAGE_MAP(CDemoView, CView)
	//{{AFX_MSG_MAP(CDemoView)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoView construction/destruction

CDemoView::CDemoView()
{
	// TODO: add construction code here

}

CDemoView::~CDemoView()
{
}

BOOL CDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView drawing

void CDemoView::OnDraw(CDC* pDC)
{
	pDC->TextOut(0, 0, "Press the left mouse button here."); 
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView diagnostics

#ifdef _DEBUG
void CDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDemoDoc* CDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDemoDoc)));
	return (CDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDemoView message handlers

void CDemoView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CSpecialFileDialog dlgFile(TRUE, NULL, "*.obj"); 
	CString strMessage; 
	int nModal = dlgFile.DoModal(); 
	if(nModal == IDCANCEL && dlgFile.m_bDeleteAll)
	{
		strMessage.Format("Are you sure you want to delete all %s files?", 
			dlgFile.m_strFileName); 
		if(AfxMessageBox(strMessage, MB_YESNO) == IDYES)
		{
			HANDLE h; 
			WIN32_FIND_DATA fData; 
			while((h = ::FindFirstFile(dlgFile.m_strFileName, &fData)) != (HANDLE)0xFFFFFFFF)
			{
				if(::DeleteFile(fData.cFileName) == FALSE)
				{
					strMessage.Format("Unable to delete file %s\n", fData.cFileName); 
					AfxMessageBox(strMessage); 
					break; 
				}
			}
		}
	}
	else if(nModal == IDOK)
	{
		CString strSingleFilename = dlgFile.GetPathName(); 
		strMessage.Format("Are you sure you want to delete %s?", strSingleFilename); 
		if(AfxMessageBox(strMessage, MB_YESNO) == IDYES)
			CFile::Remove(strSingleFilename); 
	}
}
