#if !defined(AFX_VALIDFORM_H__07411052_ACD4_4EB4_A5E8_6B677334D6AD__INCLUDED_)
#define AFX_VALIDFORM_H__07411052_ACD4_4EB4_A5E8_6B677334D6AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ValidForm.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CValidForm form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CValidForm : public CFormView
{    
	DECLARE_DYNAMIC(CValidForm)
private:
    BOOL m_bValidationOn; 
public:
	CValidForm(UINT nID);           // protected constructor used by dynamic creation

// Form Data
public:
	//{{AFX_DATA(CValidForm)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CValidForm)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CValidForm();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CValidForm)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VALIDFORM_H__07411052_ACD4_4EB4_A5E8_6B677334D6AD__INCLUDED_)
