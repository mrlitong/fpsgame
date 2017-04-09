#pragma once
#include "MathLib.h"
#include "Singleton.h"
#include "UtilStr.h"

class CBRObject;
class CTextureImage;

class CStar2DControl : public CSingleton < CStar2DControl >
{

public:

	CStar2DControl(void);
	~CStar2DControl(void);

public:

	int         Init();
	void        Update();
	void        Click();
	int         Load(const char* strNormal, const char* strClick);
	void        SetEnable(int nEnable);
	int         IsEnable();



}