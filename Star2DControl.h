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

	void        SetNormalColor(const MathLib::vec4& vColor);
	const MathLib::vec4& GetNormalColor() const;

	void        SetClickColor(const MathLib::vec4& vColor);
	const MathLib::vec4& GetClickColor() const;


	//屏幕空间比例 从0到1的值
	void        SetNormalScale(float fScale);
	float       GetNormalScale() const;

	void        SetClickScale(float fScale);
	float       GetClickScale() const;



}