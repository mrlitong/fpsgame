#include "FPSRoleLocal.h"
#include "Creature.h"


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

CFPSRoleLocal::CFPSRoleLocal(void)
{
	m_nCharMode = 0;
	m_nMuzzleBone = -1;
	m_nUpdateMove = 0;
}


int CFPSRoleLocal::Init(int nRoleID,const char* strCharFile)
{
	CFPSRole::Init(nRoleID, strCharFile);

	m_pCreature->SetupBody(1, 1);

	m_pCreature->SetHighShadow(1);
	SetupArms(2, 0);
	//m_vCameraOffset = vec3(0.0f, 0.0f, 1.8f);

	m_pActorBase = new CActorBase();
	m_pActorBase->SetEnabled(1);
	m_vCameraOffset = vec3(0.0f, 0.0f, 1.8f);
	m_vCameraOffset = vec3(0.0f, 0.0f, 1.8f);		
													
	m_vGunOffset = vec3(0.2, 0.2, 0.2f);
	//m_vRotateOffset = vec3(-0.076326f, 0.018540f, -1.725809f); // gua dian  weizhi);
	m_vRotateOffset = vec3(-0.076326f, 0.018540f, -1.725809f); // gua dian  weizhi);


	return 1;
}




void CFPSRoleLocal::Update(float ifps)
{
	if (m_pFire[0])
	{
		if (g_Engine.pApp->GetMouseButtonState(CApp::BUTTON_LEFT) || g_Engine.pApp->GetMouseButtonState(CApp::BUTTON_LDCLICK))
		{
			OpenFire();		//Êó±êµ¥»÷
		}
		else
		{
			CloseFire();
		}
	}
}