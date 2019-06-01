// Machine generated IDispatch wrapper class(es) created with ClassWizard

#include "stdafx.h"
#include "clockdriver.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// IAlarm properties

DATE IAlarm::GetTime()
{
	DATE result;
	GetProperty(0x1, VT_DATE, (void*)&result);
	return result;
}

void IAlarm::SetTime(DATE propVal)
{
	SetProperty(0x1, VT_DATE, propVal);
}

/////////////////////////////////////////////////////////////////////////////
// IAlarm operations


/////////////////////////////////////////////////////////////////////////////
// IClock properties

DATE IClock::GetTime()
{
	DATE result;
	GetProperty(0x1, VT_DATE, (void*)&result);
	return result;
}

void IClock::SetTime(DATE propVal)
{
	SetProperty(0x1, VT_DATE, propVal);
}

/////////////////////////////////////////////////////////////////////////////
// IClock operations

VARIANT IClock::GetFigure(short nIndex)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, parms,
		nIndex);
	return result;
}

void IClock::SetFigure(short nIndex, const VARIANT& newValue)
{
	static BYTE parms[] =
		VTS_I2 VTS_VARIANT;
	InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nIndex, &newValue);
}

void IClock::RefreshWin()
{
	InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void IClock::ShowWin()
{
	InvokeHelper(0x3, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

LPDISPATCH IClock::CreateAlarm(DATE Time)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_DATE;
	InvokeHelper(0x4, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Time);
	return result;
}
