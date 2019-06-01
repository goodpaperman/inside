#if !defined(AFX_PERSISTENT_H__6BEF74E5_D276_45FF_A7BD_FA4BB8257A21__INCLUDED_)
#define AFX_PERSISTENT_H__6BEF74E5_D276_45FF_A7BD_FA4BB8257A21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Persistent.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPersistentFrame frame

class CPersistentFrame : public CFrameWnd
{
	DECLARE_DYNAMIC(CPersistentFrame)
private:
	static const CRect s_rectDefault; 
	static const char s_profileHeading[]; 
	static const char s_profileRect[]; 
	static const char s_profileIcon[]; 
	static const char s_profileMax[]; 
	static const char s_profileTool[]; 
	static const char s_profileStatus[]; 
	BOOL m_bFirstTime; 

protected:
	CPersistentFrame();           // protected constructor used by dynamic creation
	virtual ~CPersistentFrame();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPersistentFrame)
	public:
	virtual void ActivateFrame(int nCmdShow = -1); 
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPersistentFrame)
		// NOTE - the ClassWizard will add and remove member functions here.
	afx_msg void OnDestroy(); 
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PERSISTENT_H__6BEF74E5_D276_45FF_A7BD_FA4BB8257A21__INCLUDED_)
