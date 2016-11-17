#include "Common.h"
#include "Engine.h"



CCommon::CCommon(void)
{

}


CCommon::~CCommon(void)
{

}

vec3 CCommon::GetTransformDirection(const mat4& matTransform, const vec3& vUP)
{
	
}

int CCommon::GetIntersectionPosition(vec3& vRetPoint, const vec3& p0, const vec3& p1, int nMask /*= 2|4*/)
{

}

int CCommon::GetIntersectionObject(CBRObject** vRetObject, const vec3& p0, const vec3& p1, int nMask /*= 2|4*/)
{

}

float CCommon::CalcAxisScale(const mat4& modelview, float fov, vec4 objectPosW, float sizeInPixels, float viewHeight)
{

}