#include "GameProcess.h"
#include "Object.h"
#include "Engine.h"
#include "World.h"
#include "App.h"
#include "ToolsCamera.h"
#include "ControlsApp.h"
#include "MathLib.h"
#include "Game.h"
#include "Editor.h"
#include "Input.h"
#include "BlueRayUtils.h"
#include "World.h"
#include "Action.h"
#include "FPSRoleLocal.h"
#include "StarControl.h"
#include "RayControl.h"

using namespace MathLib;

CGameProcess::CGameProcess(void)
{

}

CGameProcess::~CGameProcess(void)
{

}
int CGameProcess::Init()
{
	g_Engine.pFileSystem->CacheFilesFormExt("char");
	g_Engine.pFileSystem->CacheFilesFormExt("node");
	g_Engine.pFileSystem->CacheFilesFormExt("smesh");
	g_Engine.pFileSystem->CacheFilesFormExt("sanim");

	g_Engine.pWorld->LoadWorld("data/scene/terrain/test/test.world");
	//g_Engine.pWorld->LoadWorld("data/scene/terrain/cj/cj.world"); 
	g_Engine.pControls->SetKeyPressFunc(KeyPress);
	g_Engine.pControls->SetKeyReleaseFunc(KeyRelease);

	m_pRole = new CFPSRoleLocal();
	m_pRole->Init(10001, "data/role/hero/FpsRole/fps.char");		

	m_pRole->SetActorPosition(vec3(0, 0, 0));	//设置角色初始位置。以门处作为原点，三维坐标系vec3是向量
	m_pSkillSystem = new CSkillSystem(this);
	m_pCameraBase = new CCameraBase();
	m_pCameraBase->SetEnabled(1);
	g_pSysControl->SetMouseGrab(1);

	m_pStarControl = new CStarControl();
	m_pRayControl = new CRayControl();

	return 1;
}

int CGameProcess::ShutDown()			//关闭游戏进程
{
	delete m_pRole;
	delete m_pSkillSystem;
	delete m_pCameraBase;
	delete m_pStarControl;
	delete m_pRayControl;

	DelAllListen();
	return 0;
}

int CGameProcess::Update()
{
	float ifps = g_Engine.pGame->GetIFps();

	if (g_Engine.pInput->IsKeyDown('1'))
	{
		CAction* pAction = m_pRole->OrceAction("attack02");
		if (pAction)
		{
			pAction->SetupSkillThrow(vec3_zero, -1.0f, 2.0f);
			m_pRole->StopMove();
		}
	}
	else if (g_Engine.pInput->IsKeyDown('2'))
	{
		CAction* pAction = m_pRole->OrceAction("skill01");
		if (pAction)
		{
			m_pRole->StopMove();
		}
	}
	else if (g_Engine.pInput->IsKeyDown('3'))
	{
		CAction* pAction = m_pRole->OrceAction("skill02");
		if (pAction)
		{
			m_pRole->StopMove();
			CRoleBase* pTarget = NULL;
			for (int i = 0; i < 20; i++)
			{
				float l = (m_vAIList[i]->GetPosition() - m_pRole->GetPosition()).length();
				if (l > 5.0f && l < 15.0f)
				{
					pTarget = m_vAIList[i];
					break;
				}
			}
			if (pTarget)
			{
				CVector<int> vTarget;
				vTarget.Append(pTarget->GetRoleID());
				pAction->SetupSkillBulletTarget(vTarget);
				m_pRole->SetDirection((pTarget->GetPosition() - m_pRole->GetPosition()).normalize(), 1);
			}
		}
	}
	else if (g_Engine.pInput->IsKeyDown('4'))//多发子弹
	{
		CAction* pAction = m_pRole->OrceAction("skill02");
		if (pAction)
		{
			m_pRole->StopMove();
			CVector<int> vTarget;
			for (int i = 0; i < 20; i++)
			{
				float l = (m_vAIList[i]->GetPosition() - m_pRole->GetPosition()).length();
				if (l > 5.0f && l < 20.0f)
				{
					vTarget.Append(m_vAIList[i]->GetRoleID());
				}
			}
			if (!vTarget.Empty())
			{
				pAction->SetupSkillBulletTarget(vTarget);
			}
		}
	}
	else if (g_Engine.pInput->IsKeyDown('5'))
	{
		CAction* pAction = m_pRole->OrceAction("skill03");
		if (pAction)
		{
			m_pRole->StopMove();
			CVector<vec3> vPos;
			pAction->SetupSkillTargetPoint(vPos);
		}
	}
	else if (g_Engine.pInput->IsKeyDown('6'))
	{
		CAction* pAction = m_pRole->OrceAction("skill06");
		if (pAction)
		{
			m_pRole->StopMove();
			CVector<vec3> vPos;
			for (int i = 0; i < 20; i++)
			{
				float l = (m_vAIList[i]->GetPosition() - m_pRole->GetPosition()).length();
				if (l > 5.0f && l < 20.0f)
					vPos.Append(m_vAIList[i]->GetPosition());

			}
			pAction->SetupSkillTargetPoint(vPos);
		}
	}
	else if (g_Engine.pInput->IsKeyDown('7'))
	{
		CAction* pAction = m_pRole->OrceAction("skill05");
		if (pAction)
		{
			m_pRole->StopMove();
			CVector<int> vTarget;
			for (int i = 0; i < 20; i++)
			{
				float l = (m_vAIList[i]->GetPosition() - m_pRole->GetPosition()).length();
				if (l > 5.0f && l < 20.0f)
					vTarget.Append(m_vAIList[i]->GetRoleID());
			}
			if (!vTarget.Empty())
			{
				pAction->SetupSkillBulletTarget(vTarget);
			}
		}
	}
	else if (g_Engine.pInput->IsKeyDown('8'))
	{
		CAction* pAction = m_pRole->OrceAction("skill07");
		if (pAction)
		{
			m_pRole->StopMove();
			CVector<vec3> vPos;
			for (int i = 0; i < 20; i++)
			{
				float l = (m_vAIList[i]->GetPosition() - m_pRole->GetPosition()).length();
				if (l > 5.0f && l < 20.0f)
					vPos.Append(m_vAIList[i]->GetPosition());
			}
			pAction->SetupSkillBulletPosition(vPos);
		}
	}
	else if (g_Engine.pInput->IsKeyDown('9'))
	{
		CAction* pAction = m_pRole->OrceAction("skill08");
		if (pAction)
		{
			m_pRole->StopMove();
			pAction->SetupSkillBulletDirection(1);
		}

	}
	else if (g_Engine.pInput->IsKeyUp(CInput::KEY_ESC))
	{
		g_Engine.pApp->Exit();
	}
	if(g_Engine.pInput->IsLBDown())
	{
		vec3 p0,p1;
		BlueRay::GetPlayerMouseDirection(p0,p1);
		vec3 vRetPoint,vRetNormal;
		int nS = -1;
		g_Engine.pWorld->GetIntersection(p0,p1,CBRObject::MASK_SCENE,vRetPoint,vRetNormal,nS);

		if(-1 != nS)
		{
			m_pRole->MoveToPath(vRetPoint);
		}
	}
	for(int i = 0;i < 20;i++)
	{
		if(!m_vAIList[i]->IsMoveing())
		{
			vec3 vPos = vec3(g_Engine.pGame->GetRandomFloat(-20.0f,20.0f),g_Engine.pGame->GetRandomFloat(-20.0f,20.0f),1.1f);
			m_vAIList[i]->MoveToPath(vPos);
		}

		m_vAIList[i]->Update(ifps);
	}
	if (g_Engine.pInput->IsLBDown())	//shubiaozuojian
	{
		g_pSysControl->SetMouseGrab(1);
		m_pStarControl->Click();
	}
	if (g_Engine.pInput->IsKeyDown(CInput::KEY_ESC))		
	{
		g_pSysControl->SetMouseGrab(0);
	}
	m_pCameraBase->SetMouseControls(g_pSysControl->GetMouseGrab());
	m_pCameraBase->Update(ifps);

	m_pRole->SetActorDirection(m_pCameraBase->GetViewDirection());
	m_pRole->UpdateActor(ifps);
	m_pCameraBase->SetPosition(m_pRole->GetActorPosition() + m_pRole->GetCameraOffset());

	vec3 x = m_pCameraBase->GetModelview().getRow3(0);
	vec3 y = m_pCameraBase->GetModelview().getRow3(1);
	vec3 z = m_pCameraBase->GetModelview().getRow3(2);

	mat4 r = mat4_identity;

	r.setColumn3(0, -x);	//
	r.setColumn3(1, z);		//
	r.setColumn3(2, y);		//

	m_pRole->UpdateTransform(r);



	return 0;
}


