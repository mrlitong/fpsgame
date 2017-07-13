#ifndef __HMD_WRAPPER_H__
#define __HMD_WRAPPER_H__

#include "MathLib.h"


class CHMDWrapper
{

public:

	CHMDWrapper() {}
	virtual ~CHMDWrapper() {}
	virtual void                Init() = 0;
	virtual void                Update() = 0;
	virtual void                Shutdown() = 0;

	virtual void                SetUseHMD(int u) = 0;
	virtual int                 GetUseHMD() const = 0;

	virtual const MathLib::vec3 &GetLocalDirection() const = 0;
	virtual const MathLib::vec3 &GetLocalUp() const = 0;

private:

};

extern CHMDWrapper *g_pHMD;

#endif