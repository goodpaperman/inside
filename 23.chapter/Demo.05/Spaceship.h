#if !defined(AFX_SPACESHIP_H__D24BB79D_7D87_46D8_8C75_2355CF5C3117__INCLUDED_)
#define AFX_SPACESHIP_H__D24BB79D_7D87_46D8_8C75_2355CF5C3117__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Spaceship.h : header file
//

void ITrace(REFIID iid, const char* str); 


/////////////////////////////////////////////////////////////////////////////
// CSpaceship command target

class CSpaceship : public CCmdTarget
{
	DECLARE_DYNCREATE(CSpaceship)

protected:
	CSpaceship();           // protected constructor used by dynamic creation

// Attributes
public:

private:
	int m_nPosition; 
	int m_nAcceleration; 
	int m_nColor; 

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpaceship)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CSpaceship();

	// Generated message map functions
	//{{AFX_MSG(CSpaceship)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CSpaceship)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CSpaceship)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	//DECLARE_DISPATCH_MAP()

	BEGIN_INTERFACE_PART(Motion, IMotion)
		STDMETHOD_(void, Fly)(); 
		STDMETHOD_(int&, GetPosition)(); 
	END_INTERFACE_PART(Motion)

	BEGIN_INTERFACE_PART(Visual, IVisual)
		STDMETHOD_(void, Display)(); 
	END_INTERFACE_PART(Visual)

	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPACESHIP_H__D24BB79D_7D87_46D8_8C75_2355CF5C3117__INCLUDED_)
