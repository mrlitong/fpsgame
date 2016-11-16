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
};