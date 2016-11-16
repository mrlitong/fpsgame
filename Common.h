#pragma once
#include "MathLib.h"
using namespace MathLib;
class CBRObject;

class CCommon
{
public:
	CCommon(void);
	~CCommon(void);
	static int	 GetIntersectionObject(CBRObject** vRetObject, const vec3& p0, const vec3& p1, int nMask = 2 | 4);
	static float  CalcAxisScale(float fov,vec4 objectPosW,float sizeInPixels,float viewHeight);
	static vec3   GetTransformDirection(const mat4& matTransform,const vec3& vUP = vec3(0.0f,0.0f,1.0f));
	static int	 GetIntersectionPosition(const mat4& modelview,vec3& vRetPoint,const vec3& p0,const vec3& p1,int nMask = 2|4);
};