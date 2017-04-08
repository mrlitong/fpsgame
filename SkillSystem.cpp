#include "SkillSystem.h"
#include "BulletSystem.h"
#include "interface.h"
#include "GameProcess.h"
#include "ObjectParticles.h"

CSkillSystem::CSkillSystem(CGameProcess*	pGameProcess)
{
	CBulletSystem::GetInstance()->SetCallback(MakeInterface(this, &CSkillSystem::OnSkillCallback));
	m_pGameProcess = pGameProcess;
	AddListen(BR_PARTICLE_HIT, MakeMessageFunc(this, &CSkillSystem::OnParticleHit));
}

