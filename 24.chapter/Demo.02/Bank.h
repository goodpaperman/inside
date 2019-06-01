#if !defined(AFX_BANK_H__116AF2DF_AE2B_471B_BE95_990645297605__INCLUDED_)
#define AFX_BANK_H__116AF2DF_AE2B_471B_BE95_990645297605__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Bank.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CBank command target

class CBank : public CCmdTarget
{
	DECLARE_DYNCREATE(CBank)

	CBank();           // protected constructor used by dynamic creation

// Attributes
public:
	double m_dBalance; 

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBank)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CBank();

	// Generated message map functions
	//{{AFX_MSG(CBank)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CBank)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CBank)
	afx_msg double GetBalance();
	afx_msg void SetBalance(double newValue);
	afx_msg double Withdrawal(double dAmount);
	afx_msg void Deposit(double dAmount);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};


#define IMPLEMENT_OLECREATE2(class_name, external_name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
    AFX_DATADEF COleObjectFactory class_name::factory(class_name::guid, \
        RUNTIME_CLASS(class_name), TRUE, _T(external_name)); \
    AFX_COMDAT const AFX_DATADEF GUID class_name::guid = \
        { l, w1, w2, { b1, b2, b3, b4, b5, b6, b7, b8 } }; \

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BANK_H__116AF2DF_AE2B_471B_BE95_990645297605__INCLUDED_)
