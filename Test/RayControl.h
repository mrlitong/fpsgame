#pragma once
#include "MathLib.h"
#include "Singleton.h"


class CObjectParticles;
using namespace MathLib;

class CRayControl : public CSingleton<CRayControl>
{
public:
	CRayControl(void);
	~CRayControl(void);
public:
	int		Init();
	void		Update(const mat4& matTransform, const vec3 & vOffset = vec3_zero);
	int		isEnable();
	void		SetEnable(int nEnable);
	void		SetColor(const vec4& vColor);
protected:
	CObjectParticles*	  m_pStarNormal;
};