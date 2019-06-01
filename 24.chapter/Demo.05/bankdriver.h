// Machine generated IDispatch wrapper class(es) created with ClassWizard
/////////////////////////////////////////////////////////////////////////////
// IBank wrapper class

class IBank : public COleDispatchDriver
{
public:
	IBank() {}		// Calls COleDispatchDriver default constructor
	IBank(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IBank(const IBank& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:
	double GetBalance();
	void SetBalance(double);

// Operations
public:
	double Withdrawal(double dAmount);
	void Deposit(double dAmount);
};
