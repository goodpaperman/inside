// Demo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"

#define CLSID_CSpaceship 1
#define IID_IMotion 2
#define IID_IVisual 3

struct IMotion
{
	virtual void Fly() = 0; 
	virtual int& GetPosition() = 0; 
}; 

struct IVisual 
{
	virtual void Display() = 0; 
}; 

class CSpaceship : public IMotion, public IVisual 
{
protected:
	int m_nPosition; 

public:
	CSpaceship() { m_nPosition = 0; }
	void Fly(); 
	int& GetPosition() { return m_nPosition; }
	void Display() { printf("display a space ship here.\n"); }
}; 

void CSpaceship::Fly()
{
	m_nPosition ++; 
}

bool GetClassObject(int nClsid, int nIid, void** ppvObj)
{
	if(nClsid == CLSID_CSpaceship)
	{
		if(nIid == IID_IMotion)
		{
			*ppvObj = (IMotion*)new CSpaceship(); 
		}
		else if(nIid == IID_IVisual)
		{
    		*ppvObj = (IVisual*)new CSpaceship(); 
		}
	}

	return true; 
}


int main(int argc, char* argv[])
{
	IMotion* pMot; 
	GetClassObject(CLSID_CSpaceship, IID_IMotion, (void**)&pMot); 

	int nPos = 50; 
	pMot->GetPosition() = nPos; 
	pMot->Fly(); 
	nPos = pMot->GetPosition(); 
	printf("new position = %d\n", nPos); 
	//delete pMot; 

	IVisual* pVis; 
	GetClassObject(CLSID_CSpaceship, IID_IVisual, (void**)&pVis);
	pVis->Display(); 
	//delete pVis; 
	return 0;
}
