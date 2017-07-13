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

CLocalHMDWrapper::~CLocalHMDWrapper()
{

}

void CLocalHMDWrapper::Init()
{
	m_nHaveHMD = Interface::CDeviceInterface::GetInstance()->InitEnv();
}

void CLocalHMDWrapper::Update()
{
	if (GetUseHMD())
	{
		Interface::SEulerAngles sData;
		Interface::CDeviceInterface::GetInstance()->GetHMDSensorRotation(sData);
		Interface::CDeviceInterface::GetInstance()->Run();

		vec3 dir = forward_vector;
		vec3 up = up_vector;
		quat rotate(-sData.fPitch * RAD2DEG, sData.fRoll * RAD2DEG, sData.fYaw * RAD2DEG);

		m_vLocalDirection = rotate * dir;
		m_vLocalUp = rotate * up;
	}
}

void CLocalHMDWrapper::Shutdown()
{
	Interface::CDeviceInterface::GetInstance()->Destroy();
}

void CLocalHMDWrapper::SetUseHMD(int u)
{
	m_nUseHMD = u;
}

int CLocalHMDWrapper::GetUseHMD() const
{
	return m_nUseHMD && m_nHaveHMD;
}

const MathLib::vec3 & CLocalHMDWrapper::GetLocalDirection() const
{
	return m_vLocalDirection;
}

const MathLib::vec3 & CLocalHMDWrapper::GetLocalUp() const
{
	return m_vLocalUp;
}

CLocalHMDWrapper LocalHMDWrapper;
CHMDWrapper *g_pHMD = &LocalHMDWrapper;