#if !defined(AFX_DEMOAUTO_H__43F8C783_E45E_40B8_ACE2_FCC5431BE7A2__INCLUDED_)
#define AFX_DEMOAUTO_H__43F8C783_E45E_40B8_ACE2_FCC5431BE7A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DemoAuto.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CDemoAuto command target

class CDemoAuto : public CCmdTarget
{
	DECLARE_DYNCREATE(CDemoAuto)

	CDemoAuto();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoAuto)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CDemoAuto();

	// Generated message map functions
	//{{AFX_MSG(CDemoAuto)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CDemoAuto)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CDemoAuto)
	long m_lData;
	afx_msg void OnLongDataChanged();
	VARIANT m_vaTextData;
	afx_msg void OnTextDataChanged();
	afx_msg BOOL DisplayDialog();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMOAUTO_H__43F8C783_E45E_40B8_ACE2_FCC5431BE7A2__INCLUDED_)
