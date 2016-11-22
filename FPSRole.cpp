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
		m_pStand[1] = (CAnimationBlendRotate*)m_pCreature->GetAnimationBlend("stand_v");
		m_pFire[1] = (CAnimationBlendRotate*)m_pCreature->GetAnimationBlend("fire_v");
		m_pRun[0] = (CAnimationBlendDual*)m_pCreature->GetAnimationBlend("run_h");
		m_pRun[1] = (CAnimationBlendDual*)m_pCreature->GetAnimationBlend("run_v");


		m_fAniNowCoolingTime = 0.0f;
		m_fAniCoolingTime = 1.0f / m_pFire[0]->GetTriggerSpeed();
		m_fEmitNowCoolingTime = 0;
		m_fSudNowCoolingTime = 0;

		
		m_fSudCoolingTime = m_fAniCoolingTime  * 4.0f; //²âÊÔÖµ
		m_fEmitCoolingTime = m_fAniCoolingTime * 3.0f;//²âÊÔÖµ


		m_pBulletParticle = (CObjectParticles*)g_Engine.pGame->LoadNode(m_strBulletName);
	}
	return 1;//always return 1;
}

void CFPSRole::OnKeyFrame( _ActionCallback_KeyFrame* pKeyInfo )
{
	//I will finish this function later.
}

void CFPSRole::OnActionComplete( _ActionCallback_Complete* pActInfo )
{
	return CRoleBase::OnActionComplete(pActInfo);
}
