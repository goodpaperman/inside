// Machine generated IDispatch wrapper class(es) created with ClassWizard

#include "stdafx.h"
#include "autodriver.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// IAuto properties

long IAuto::GetLongData()
{
	long result;
	GetProperty(0x1, VT_I4, (void*)&result);
	return result;
}

void IAuto::SetLongData(long propVal)
{
	SetProperty(0x1, VT_I4, propVal);
}

VARIANT IAuto::GetTextData()
{
	VARIANT result;
	GetProperty(0x2, VT_VARIANT, (void*)&result);
	return result;
}

void IAuto::SetTextData(const VARIANT& propVal)
{
	SetProperty(0x2, VT_VARIANT, &propVal);
}

/////////////////////////////////////////////////////////////////////////////
// IAuto operations

BOOL IAuto::DisplayDialog()
{
	BOOL result;
	InvokeHelper(0x3, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
	return result;
}
