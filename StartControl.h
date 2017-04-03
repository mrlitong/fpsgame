#pragma once
#include "MathLib.h"
#include "Singleton.h"


class CBRObject;
using namespace MathLib;

class CStarControl : public CSingleton < CStarControl >
{
public:
	CStarControl(void);
	~CStarControl(void);
public:
	int		Init();
	void		Update(const vec3& vPos, const vec3& vDir);
	void		Click();
	int		Load(const char* strNormal, const char* strClick);
	int		isEnable();
	void		SetEnable(int nEnable);
	void		SetViewDistance(float fViewDistance) { m_fViewDistance = fViewDistance; }
	void		SetColor(const vec4& vColor);
protected:
	CBRObject*			m_pStarNormal;
	CBRObject*			m_pStarClick;
	float				m_fViewDistance;
	int					m_nClickState;
	float				m_fClickScale;
}