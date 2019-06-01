// Demo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#define RUNTIME_CLASS(class_name) (&class_name::class##class_name) 
class CObject; 

struct CRuntimeClass
{
    char m_lpszClassName[21]; 
    int m_nObjectSize; 
    CObject* (*m_pfnCreateObject)(); 
    CObject* CreateObject(); 
}; 

class CObject
{
public:
    virtual CRuntimeClass* GetRuntimeClass() const { return NULL; } 
    static CRuntimeClass classObject; 
    virtual ~CObject() {} 
protected:
    CObject() { printf("CObject constructor\n"); } 
}; 

CRuntimeClass CObject::classObject = { "CObject", sizeof(CObject), NULL }; 

CObject* CRuntimeClass::CreateObject()
{
    return (*m_pfnCreateObject)(); 
}

class CAlpha : public CObject
{
public:
    virtual CRuntimeClass* GetRuntimeClass() const { return &classCAlpha; } 
    static CRuntimeClass classCAlpha; 
    static CObject* CreateObject(); 
protected:
    CAlpha() { printf("CAlpha constructor\n"); }
}; 

CRuntimeClass CAlpha::classCAlpha = { "CAlpha", sizeof(CAlpha), CAlpha::CreateObject } ; 

CObject* CAlpha::CreateObject()
{
    return new CAlpha; 
}

class CBeta : public CObject
{
public:
    virtual CRuntimeClass* GetRuntimeClass() const { return &classCBeta; } 
    static CRuntimeClass classCBeta; 
    static CObject* CreateObject(); 
protected:
    CBeta() { printf("CBeta constructor\n"); }
}; 

CRuntimeClass CBeta::classCBeta = { "CBeta", sizeof(CBeta), CBeta::CreateObject }; 

CObject* CBeta::CreateObject()
{
    return new CBeta; 
}


int main(int argc, char* argv[])
{
    printf("Entering dyncreate main\n"); 
    CRuntimeClass* pRTCAlpha = RUNTIME_CLASS(CAlpha); 
    CObject* pObj1 = pRTCAlpha->CreateObject(); 
    printf("class pObj1 = %s\n", pObj1->GetRuntimeClass()->m_lpszClassName); 
    CRuntimeClass* pRTCBeta = RUNTIME_CLASS(CBeta); 
    CObject* pObj2 = pRTCBeta->CreateObject(); 
    printf("class of pObj2 = %s\n", pObj2->GetRuntimeClass()->m_lpszClassName); 
    delete pObj1; 
    delete pObj2; 
	return 0;
}
