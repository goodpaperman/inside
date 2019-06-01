// Machine generated IDispatch wrapper class(es) created with ClassWizard
/////////////////////////////////////////////////////////////////////////////
// IAlarm wrapper class

class IAlarm : public COleDispatchDriver
{
public:
	IAlarm() {}		// Calls COleDispatchDriver default constructor
	IAlarm(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IAlarm(const IAlarm& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:
	DATE GetTime();
	void SetTime(DATE);

// Operations
public:
};
/////////////////////////////////////////////////////////////////////////////
// IClock wrapper class

class IClock : public COleDispatchDriver
{
public:
	IClock() {}		// Calls COleDispatchDriver default constructor
	IClock(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IClock(const IClock& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:
	DATE GetTime();
	void SetTime(DATE);

// Operations
public:
	VARIANT GetFigure(short nIndex);
	void SetFigure(short nIndex, const VARIANT& newValue);
	void RefreshWin();
	void ShowWin();
	LPDISPATCH CreateAlarm(DATE Time);
};
