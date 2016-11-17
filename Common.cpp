#include "Common.h"
#include "Engine.h"

#include "Game.h"
#include "World.h"

CCommon::CCommon(void)
{

}


CCommon::~CCommon(void)
{

}

vec3 CCommon::GetTransformDirection(const mat4& matTransform, const vec3& vUP)
{
	return MakeRotationFromYZ(matTransform.getColumn3(1), vUP) * vec3(0.0f, -1.0f, 0.0f);
}

int CCommon::GetIntersectionPosition(vec3& vRetPoint, const vec3& p0, const vec3& p1, int nMask /*= 2|4*/)
{
	vec3 n;
	int s;

	g_Engine.pWorld->GetIntersection(p0, p1, nMask, vRetPoint, n, s);

	return s >= 0;
}

int CCommon::GetIntersectionObject(CBRObject** vRetObject, const vec3& p0, const vec3& p1, int nMask /*= 2|4*/)
{
	vec3 p, n;
	int s;
	vRetObject = NULL;
	*vRetObject = g_Engine.pWorld->GetIntersection(p0, p1, nMask, p, n, s);

	return s >= 0;
}

float CCommon::CalcAxisScale(const mat4& modelview, float fov, vec4 objectPosW, float sizeInPixels, float viewHeight)
{
	float worldHeight;
	// World height on origin's z value
	vec4 objPosV;
	objPosV = modelview * objectPosW;
	worldHeight = 2.0f * CMathCore::Abs(objPosV.z) * (float)CMathCore::Tan(fov / 2.0f * DEG2RAD);

	return sizeInPixels * (worldHeight / viewHeight);
}