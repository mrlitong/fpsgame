#include "CameraBase.h"
#include "sys/SysControl.h"
#include "HMDWrapper.h"
#include "Engine.h"
#include "Game.h"

using namespace MathLib;


#ifdef MEMORY_INFO
#define new new(__FILE__, __LINE__) 
#endif // MEMORY_INFO

#define CAMERA_BASE_CLAMP            89.9f


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
		g_Engine.pGame->SetPlayer(this);

	}
	else
	{
		if (m_pLastPlayer)
        {
            g_Engine.pGame->SetPlayer(m_pLastPlayer);
            CPlayer::SetEnabled(nEnable);
        }
	}
}


int CCameraBase::IsEnabled() const
{
    return CPlayer::IsEnabled();
}
void CCameraBase::SetHMDEnabled(int nEnable)
{
    m_nHMDEnable = nEnable;
}

int CCameraBase::IsHMDEnabled() const
{
    return m_nHMDEnable;
}

void CCameraBase::SetRadius(float r)
{
    m_fRadius = r;
}

float CCameraBase::GetRadius() const
{
    return m_fRadius;
}
/******************************************************************************\
*
* Parameters
*
\******************************************************************************/

/*
 */
void CCameraBase::Update_Bounds() 
{
    m_BoundSphere.Set(vec3_zero,m_fRadius);
    m_BoundBox.Set(m_BoundSphere);
    Update_World_Position();
}

void CCameraBase::SetMinThetaAngle(float angle)
{
    m_fMinThetaAngle = Clamp(angle,-CAMERA_BASE_CLAMP,CAMERA_BASE_CLAMP);
}