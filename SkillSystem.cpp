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

CSkillSystem::~CSkillSystem(void)
{
	CBulletSystem::ReleaseInstance();
}

int CSkillSystem::OnSkillCallback(void* pVoid)
{
	_BulletCallback* pBase = (_BulletCallback*)pVoid;
	switch (pBase->nMsgID)
	{
	case _BulletCallback::GetTargetPosition:
	{
		_Bullet_GetTargetPosition* pBullet = (_Bullet_GetTargetPosition*)pBase;
		CRoleBase* pRole = m_pGameProcess->GetRole(pBullet->nTarget);//test
		if (pRole)
		{
			pBullet->nRetState = 1;
			pBullet->vRetPos = pRole->GetPosition() + vec3(0.0f, 0.0f, 1.2f);
			pBullet->vRetDir = pRole->GetDirection();
		}
		else
		{
			pBullet->nRetState = 0;
		}
	}break;
	case _BulletCallback::HitTarget:
	{
		_Bullet_HitTarget* pBullet = (_Bullet_HitTarget*)pBase;

	}break;
	case _BulletCallback::GetCollision:
	{
		_Bullet_GetCollision* pBullet = (_Bullet_GetCollision*)pBase;
		//test
		for (int i = 0; i < 20; i++)
		{
			CRoleBase* pRole = m_pGameProcess->GetRoleFormIndex(i);
			if (pRole)
			{
				if ((pRole->GetPosition() - pBullet->vPos).length() < pBullet->fRadius + pRole->GetRoleRadius())
				{
					pBullet->nRetTarget = pRole->GetRoleID();
					pBullet->vRetHitPoint = pRole->GetPosition() + vec3(0.0f, 0.0f, 1.2f);
				}
			}
		}
	}break;
	case _BulletCallback::Blast:
	{
		_Bullet_Blast* pBullet = (_Bullet_Blast*)pBase;

	}break;
	}

	return 1;
}

void CSkillSystem::Update(float ifps)
{
	CBulletSystem::GetInstance()->Update();
}