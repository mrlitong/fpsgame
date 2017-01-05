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
	m_pRole->Init(10001, "data/role/hero/FpsRole/fps.char");		//加载角色资源

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

	}
}



	return 0;
}


