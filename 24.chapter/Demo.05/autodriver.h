// Machine generated IDispatch wrapper class(es) created with ClassWizard
/////////////////////////////////////////////////////////////////////////////
// IAuto wrapper class

class IAuto : public COleDispatchDriver
{
public:
	IAuto() {}		// Calls COleDispatchDriver default constructor
	IAuto(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IAuto(const IAuto& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:
	long GetLongData();
	void SetLongData(long);
	VARIANT GetTextData();
	void SetTextData(const VARIANT&);

// Operations
public:
	BOOL DisplayDialog();
};
