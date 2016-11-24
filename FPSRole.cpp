#include "FPSRole.h"
#include "Engine.h"
#include "Creature.h"
#include "AnimationBlend.h"
#include "WorldEffect.h"

CFPSRole::CFPSRole(void)
{
	m_nFire = 0;
	m_fAniCoolingTime = 0;
	m_fAniNowCoolingTime = 0;
	m_fSudCoolingTime = 0;	
	m_fEmitCoolingTime = 0;

	m_fEmitNowCoolingTime = 0;
	m_fSudNowCoolingTime = 0;

	m_strMuzzleBone = "wuqi02";
	m_pArmsMesh = NULL;
	m_pBulletParticle = NULL;
	m_strBulletName = "data/effect/particle/zgfwq_sj_02.node";
	m_strMuzzleEffect  = "data/effect/particle/zgfwq_sj_01.node";
}
CFPSRole::~CFPSRole(void)
{
	g_Engine.pGame->RemoveNode(m_pBulletParticle);
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
		m_pBulletParticle->GetTracker(TRACKER_CUSTOM)->SetTrackValue(0,0.0f,vec4(1.0f,1.0f,1.0f,0.8f));
		m_pBulletParticle->SetName(CUtilStr::Format("%d",m_nRoleID));

		m_pMuzzleEffect = (CWorldEffect*)g_Engine.pGame->LoadNode(m_strMuzzleEffect);
		m_pMuzzleEffect->Stop();

		m_pMuzzleEffect->SetLoop(0);
		m_pMuzzleEffect->SetLoopCount(1);

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


void CFPSRole::SetPaceAnimationF_B( int nF_B )
{
	switch(nF_B)
	{
	case 0:
		m_pRun[0]->CloseBlend();
		break;
	case 1:	
		m_pRun[0]->PlayAnimationA();
		break;
	case 2:
		m_pRun[0]->PlayAnimationB();
		break;
	}
}

void CFPSRole::SetPaceAnimationL_R( int nF_B )
{
	switch(nF_B)
	{
	case 0:
		m_pRun[1]->CloseBlend();
		break;
	case 1:		
		m_pRun[1]->PlayAnimationA();
		break;
	case 2:		
		m_pRun[1]->PlayAnimationB();
		break;
	}
}

void CFPSRole::OnFire( float fCoolingTime )
{

}

void CFPSRole::UpdateMuzzleTransform()
{
	m_pFire[0]->LockFrame(2.3f);
	m_pFire[1]->LockFrame(2.3f);
	m_pStand[0]->LockFrame(2.3f);
	m_pStand[1]->LockFrame(2.3f);

	m_pArmsMesh->UpdateLink_Bone();
	m_pArmsMesh->SetTransform(m_pArmsMesh->GetTransform());

	m_matMuzzleTransform = m_pArmsMesh->GetWorldBoneTransform(m_nMuzzleBone);

}

void CFPSRole::SetMuzzleSpinL_R( float vValue )
{
	m_pStand[1]->SetRotateSpin(vValue);
	m_pFire[1]->SetRotateSpin(vValue);
}


void CFPSRole::SetMuzzleSpinU_D( float vValue )
{
	m_pStand[0]->SetRotateSpin(vValue);
	m_pFire[0]->SetRotateSpin(vValue);
}

void CFPSRole::Update( float ifps )
{
	UpdateMuzzleTransform();		
	m_pBulletParticle->SetWorldTransform(m_matMuzzleTransform);
	m_pMuzzleEffect->SetWorldTransform(m_matMuzzleTransform*Scale(0.4f,1.0f,0.5f));

	UpdateFire(ifps);
	CRoleBase::Update(ifps);
}