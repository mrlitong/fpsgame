#include "FPSRole.h"
#include "Engine.h"
#include "Creature.h"
#include "AnimationBlend.h"


CFPSRole::CFPSRole(void)
{
	m_nFire = 0;
	m_fAniCoolingTime = 0;
	m_fAniNowCoolingTime = 0;
	m_fSudCoolingTime = 0;	
	m_fEmitCoolingTime = 0;
}
CFPSRole::~CFPSRole(void)
{
	g_Engine.pGame->RemoveNode(m_pMuzzleEffect);
}

int CFPSRole::Init( int nRoleID,const char* strCharFile )
{
	if(CRoleBase::Init(nRoleID,strCharFile))
	{
		m_pStand[0] = (CAnimationBlendRotate*)m_pCreature->GetAnimationBlend("stand_h");
		m_pFire[0] = (CAnimationBlendRotate*)m_pCreature->GetAnimationBlend("fire_h");
	}
	return 1;//always return 1;
}