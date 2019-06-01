#if !defined(AFX_RYGWND_H__11617B83_B089_4C35_BFE7_BF6EE6A23BF7__INCLUDED_)
#define AFX_RYGWND_H__11617B83_B089_4C35_BFE7_BF6EE6A23BF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RygWnd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRygWnd window

#define RYG_SETSTATE (WM_USER+1)
#define RYG_GETSTATE (WM_USER+2)
LRESULT CALLBACK AFX_EXPORT RygWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam); 

class CRygWnd : public CWnd
{
// Construction
public:
	CRygWnd();

// Attributes
public:

private:
	int m_nState; // 0 = off, 1 = red, 2 = yellow, 3 = green.
	static CRect s_rect; 
	static CPoint s_point; 
	static CRect s_rColor[3]; 
	static CBrush s_bColor[4]; 

// Operations
public:
	static BOOL RegisterWndClass(HINSTANCE hInstance); 

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRygWnd)
	protected:
		void PostNcDestroy(); 
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRygWnd();

private:
	void SetMapping(CDC* pDC); 
	void UpdateColor(CDC* pDC, int n); 

	// Generated message map functions
protected:
	//{{AFX_MSG(CRygWnd)
	afx_msg void OnPaint(); 
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point); 
	//}}AFX_MSG
	afx_msg LRESULT OnSetState(WPARAM wParam, LPARAM lParam); 
	afx_msg LRESULT OnGetState(WPARAM wParam, LPARAM lParam); 
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RYGWND_H__11617B83_B089_4C35_BFE7_BF6EE6A23BF7__INCLUDED_)
