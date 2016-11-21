#include "FPSRoleLocal.h"
#include "Creature.h"
#include "Engine.h"
#include "Input.h"
#include "App.h"
#include "ObjectMeshSkinned.h"
#include "ActorBase.h"
#include "Visualizer.h"
#include "game.h"
#include "RayControl.h"
#include "Common.h"
#include "ControlsApp.h"

CFPSRoleLocal::CFPSRoleLocal(void)
{
	m_nCharMode = 0;
	m_nMuzzleBone = -1;
	m_nUpdateMove = 0;
}

CFPSRoleLocal::~CFPSRoleLocal(void)
{
	delete m_pActorBase;
}

int CFPSRoleLocal::Init( int nRoleID,const char* strCharFile )
{
	CFPSRole::Init(nRoleID,strCharFile);

	m_pCreature->SetupBody(1,1);
	m_pCreature->SetHighShadow(1);
	SetupArms(2,0);

	m_pActorBase = new CActorBase();
	m_pActorBase->SetEnabled(1);

	//
	//m_vCameraOffset = vec3(0.0f,0.0f,1.8f);
	m_vCameraOffset = vec3(0.0f,0.0f,1.8f);		
	//m_vGunOffset = vec3(0.0,0.0,-0.0f);
	m_vGunOffset = vec3(0.2,0.2,0.2f);
	//m_vRotateOffset = vec3(-0.076326f, 0.018540f, -1.725809f); // gua dian  weizhi);
	m_vRotateOffset = vec3(-0.076326f, 0.018540f, -1.725809f); // gua dian  weizhi);

	return 1;
}

void CFPSRoleLocal::Update( float ifps )
{
	if(m_pFire[0] && m_pFire[1])
	{	
		//if(g_Engine.pApp->GetMouseButtonState(CApp::BUTTON_LEFT) || g_Engine.pApp->GetMouseButtonState(CApp::BUTTON_LDCLICK) )
		if(g_Engine.pInput->IsLBDownPress()||g_Engine.pInput->IsLBDBDown())
		{
			OpenFire();		//Êó±êµ¥»÷
		}
		else
		{			
			CloseFire();
		}
	}
	
	CFPSRole::Update(ifps);
	CRayControl::Instance().Update(m_matMuzzleTransform,vec3(0.0f,0.5f,-0.03f));
}

void CFPSRoleLocal::OnFire( float fCoolingTime )
{
	CFPSRole::OnFire(fCoolingTime);
}

void CFPSRoleLocal::UpdateTransform( const MathLib::mat4 & matRotate )
{
	mat4 m = Translate(m_pActorBase->GetPosition()+ m_vCameraOffset) * Translate(m_vGunOffset) * matRotate * Translate(m_vRotateOffset);

}