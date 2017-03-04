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
private:

	int     m_nUseHMD;
	int     m_nHaveHMD;
	vec3    m_vLocalDirection;
	vec3    m_vLocalUp;

};

CLocalHMDWrapper::CLocalHMDWrapper()
{
	m_nUseHMD = 1;
	m_nHaveHMD = 0;
	m_vLocalDirection = forward_vector;
	m_vLocalUp = up_vector;
}

