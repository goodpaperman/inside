#if !defined(AFX_ALARM_H__371CC8D3_9FFB_4350_871C_D4365080DDEC__INCLUDED_)
#define AFX_ALARM_H__371CC8D3_9FFB_4350_871C_D4365080DDEC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Alarm.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CAlarm command target

class CAlarm : public CCmdTarget
{
	DECLARE_DYNAMIC(CAlarm)

public:
	CAlarm(DATE time);           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAlarm)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CAlarm();

	// Generated message map functions
	//{{AFX_MSG(CAlarm)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CAlarm)
	public:
	DATE m_time;
	protected:
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ALARM_H__371CC8D3_9FFB_4350_871C_D4365080DDEC__INCLUDED_)
