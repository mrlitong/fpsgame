#include "HMDWrapper.h"
#include "interface\DeviceMgrInterface.h"

using namespace MathLib;

class CLocalHMDWrapper : public CHMDWrapper
{
public:

	CLocalHMDWrapper();
	virtual ~CLocalHMDWrapper();
	virtual void                Init();
	virtual void                Update();
	virtual void                Shutdown();
	virtual void                SetUseHMD(int u);
	virtual int                 GetUseHMD() const;
	virtual const MathLib::vec3 &GetLocalDirection() const;
	virtual const MathLib::vec3 &GetLocalUp() const;


}