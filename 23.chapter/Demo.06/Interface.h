

// {D405FABA-759C-4506-890C-F353CD598AAD}
static const IID IID_IMotion = 
{ 0xd405faba, 0x759c, 0x4506, { 0x89, 0xc, 0xf3, 0x53, 0xcd, 0x59, 0x8a, 0xad } };

// {4997BF96-549E-431b-8C5C-BB7C84E5A9DB}
static const IID IID_IVisual = 
{ 0x4997bf96, 0x549e, 0x431b, { 0x8c, 0x5c, 0xbb, 0x7c, 0x84, 0xe5, 0xa9, 0xdb } };


struct IMotion : public IUnknown
{
	STDMETHOD_(void, Fly)() = 0; 
	STDMETHOD_(int&, GetPosition)() = 0; 
}; 

struct IVisual : public IUnknown
{
	STDMETHOD_(void, Display)() = 0; 
}; 