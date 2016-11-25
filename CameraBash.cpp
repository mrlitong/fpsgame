#include "CameraBase.h"

using namespace MathLib;


#ifdef MEMORY_INFO
#define new new(__FILE__, __LINE__) 
#endif // MEMORY_INFO




CCameraBase::CCameraBase(): CPlayer(PLAYER_SPECTATOR) 
{
	m_nFlush = 0;
    m_vPosition = Vec3_zero;
    m_fPhiAngle = 0.0f;
    m_fThetaAngle = 0.0f;
    m_pLastPlayer = NULL;
	m_nEnabelMouse = 1;
    SetRadius(1.0f);

	SetMinThetaAngle(-90.0f);
    SetMaxThetaAngle(90.0f);
    SetTurning(90.0f);
	
    SetViewDirection(vec3(0.0f,1.0f,0.0f));

    SetEnabled(0);
    SetHMDEnabled(1);
}

CCameraBase::~CCameraBase()
{
    Leave();
}

void CCameraBase::SetEnabled(int nEnable)
{
	if(nEnable)
	{
		m_pLastPlayer =  g_Engine.pGame->GetPlayer();
        CPlayer::SetEnabled(nEnable);
	}
	else
	{

	}
}