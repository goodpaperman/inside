// Demo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"

#define CLSID_CSpaceship 0 
#define IID_IUnknown 1
#define IID_IMotion 2
#define IID_IVisual 3
#define IID_IClassFactory 4

struct IUnknown
{
	virtual long AddRef() = 0; 
	virtual long Release() = 0; 
	virtual bool QueryInterface(int nIid, void** ppvObj) = 0; 
}; 

struct IMotion : IUnknown 
{
	virtual void Fly() = 0; 
	virtual int& GetPosition() = 0; 
}; 

struct IVisual : IUnknown 
{
	virtual void Display() = 0; 
}; 

#define offsetof(s,m)   (size_t)&(((s *)0)->m)

#define METHOD_PROLOGUE(theClass, localClass) \
	theClass* pThis = \
		((theClass*)((char*)this - offsetof(theClass, m_x##localClass))); \
	//AFX_MANAGE_STATE(pThis->m_pModuleState) \
	//pThis; // avoid warning from compiler 

class CSpaceship
{
protected:
	int m_nPosition; 
	int m_nAcceleration; 
	int m_nColor; 
	long m_dwRef; 
public:
	CSpaceship()
	{
		m_nPosition = m_nAcceleration = m_nColor = 0; 
		m_dwRef = 0; 
	}

	class XMotion : public IMotion
	{
	public:
		XMotion() {}
		virtual long AddRef(); 
		virtual long Release(); 
		virtual bool QueryInterface(int nIid, void** ppvObj); 
		virtual void Fly(); 
		virtual int& GetPosition(); 
	}m_xMotion; 

	class XVisual : public IVisual
	{
	public:
		XVisual() {}
		virtual long AddRef(); 
		virtual long Release(); 
		virtual bool QueryInterface(int nIid, void** ppvObj); 
		virtual void Display(); 
	}m_xVisual; 

	friend class XVisual; 
	friend class XMotion; 
}; 

long CSpaceship::XMotion::AddRef()
{
	METHOD_PROLOGUE(CSpaceship, Motion); 
	return ++pThis->m_dwRef; 
}

long CSpaceship::XMotion::Release()
{
	METHOD_PROLOGUE(CSpaceship, Motion); 
	if(pThis->m_dwRef == 0)
		return 0; 
	
	if(--pThis->m_dwRef == 0)
	{
		delete pThis; 
		return 0; 
	}
	
	return pThis->m_dwRef; 
}

bool CSpaceship::XMotion::QueryInterface(int nIid, void** ppvObj)
{
	METHOD_PROLOGUE(CSpaceship, Motion); 
	switch(nIid)
	{
		case IID_IUnknown:
		case IID_IMotion:
			*ppvObj = &pThis->m_xMotion; 
			AddRef(); 
			break; 
		case IID_IVisual:
			*ppvObj = &pThis->m_xVisual; 
			AddRef(); 
			break; 
		default:
			*ppvObj = NULL; 
			return false; 
	}

	return true; 
}

int& CSpaceship::XMotion::GetPosition()
{
	METHOD_PROLOGUE(CSpaceship, Motion); 
	return pThis->m_nPosition; 
}

void CSpaceship::XMotion::Fly()
{
	METHOD_PROLOGUE(CSpaceship, Motion); 
	pThis->m_nPosition++; 
}

long CSpaceship::XVisual::AddRef()
{
	METHOD_PROLOGUE(CSpaceship, Visual); 
	return ++pThis->m_dwRef; 
}

long CSpaceship::XVisual::Release()
{
	METHOD_PROLOGUE(CSpaceship, Visual); 
	if(pThis->m_dwRef == 0)
		return 0; 
	
	if(--pThis->m_dwRef == 0)
	{
		delete pThis; 
		return 0; 
	}
	
	return pThis->m_dwRef; 
}

bool CSpaceship::XVisual::QueryInterface(int nIid, void** ppvObj)
{
	METHOD_PROLOGUE(CSpaceship, Visual); 
	switch(nIid)
	{
		case IID_IUnknown:
		case IID_IMotion:
			*ppvObj = &pThis->m_xMotion; 
			AddRef(); 
			break; 
		case IID_IVisual:
			*ppvObj = &pThis->m_xVisual; 
			AddRef(); 
			break; 
		default:
			*ppvObj = NULL; 
			return false; 
	}
	return true; 
}

void CSpaceship::XVisual::Display()
{
	printf("Display a space ship here.\n"); 
}

struct IClassFactory : public IUnknown
{
	virtual bool CreateInstance(int nIid, void** ppvObj) = 0; 
}; 

class CSpaceshipFactory : public IClassFactory
{
private:
	long m_dwRef; 
public:
	CSpaceshipFactory() { m_dwRef = 1; }
	virtual bool QueryInterface(int nIid, void** ppvObj); 
	virtual long AddRef(); 
	virtual long Release(); 
	virtual bool CreateInstance(int nIid, void** ppvObj);  
}; 

bool CSpaceshipFactory::QueryInterface(int nIid, void** ppvObj)
{
	return false; 
}

long CSpaceshipFactory::AddRef()
{
	return ++m_dwRef; 
}

long CSpaceshipFactory::Release()
{
	if(m_dwRef == 0)
		return 0; 

	if(--m_dwRef == 0)
	{
		delete this; 
		return 0; 
	}

	return m_dwRef; 
}

bool CSpaceshipFactory::CreateInstance(int nIid, void** ppvObj)
{
	CSpaceship* pObj = new CSpaceship(); 
	IUnknown* pUnk = &pObj->m_xMotion; 
	return pUnk->QueryInterface(nIid, ppvObj); 
}

bool GetClassObject(int nClsid, int nIid, void** ppvObj)
{
	if(nClsid == CLSID_CSpaceship)
	{
		if(nIid == IID_IUnknown || nIid == IID_IClassFactory)
		{
			CSpaceshipFactory* pObj = new CSpaceshipFactory(); 
			*ppvObj = pObj; 
			return true; 
            //CSpaceship* pObj = new CSpaceship(); 
            //IUnknown* pUnk = &pObj->m_xMotion; 
            //return pUnk->QueryInterface(nIid, ppvObj); 
		}
	}
	return false; 
}

int main(int argc, char* argv[])
{	
    IMotion* pMot; 
	IVisual* pVis; 
	IClassFactory* pFac; 
    GetClassObject(CLSID_CSpaceship, IID_IClassFactory, (void**)&pFac); 
	pFac->CreateInstance(IID_IMotion, (void**)&pMot); 

    int nPos = 50; 
    pMot->GetPosition() = nPos; 
    pMot->Fly(); 
    nPos = pMot->GetPosition(); 
    printf("new position = %d\n", nPos); 
    //delete pMot; 

	pMot->QueryInterface(IID_IVisual, (void**)&pVis); 
    //GetClassObject(CLSID_CSpaceship, IID_IVisual, (void**)&pVis);
    pVis->Display(); 
    //delete pVis; 
	pVis->Release(); 
	pMot->Release(); 
	pFac->Release(); 
	return 0;
}
