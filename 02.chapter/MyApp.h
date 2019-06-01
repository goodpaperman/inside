
#include <afxwin.h>

class CMyApp : public CWinApp
{
public:
	virtual BOOL InitInstance(); 
}; 

class CMyFrame : public CFrameWnd
{
public: 
	CMyFrame(); 

protected:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point); 
	afx_msg void OnPaint(); 
	DECLARE_MESSAGE_MAP()
}; 