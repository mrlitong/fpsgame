#include "RoleBase.h"
#include "Creature.h"
#include "interface.h"
#include "Action.h"
#include "Utils.h"
#include "NavigationFinder.h"
#include "Engine.h"
#include "World.h"
#include "Object.h"
#include "Avatar.h"

CRoleBase::CRoleBase(void)
{
	m_pCreature = NULL;
	m_pActionComplete = NULL;
	m_nOrceDirection = 0;
	m_nMoveing = 0;
	m_fMoveSpeed = 6.0f;
	m_nMoveToType = 0;
	m_nUpdateMove = 1;
}

CRoleBase::~CRoleBase(void)
{
	SAFE_DELETE(m_pActionComplete);
	SAFE_DELETE(m_pCreature);
	SAFE_DELETE(m_pPathFind);
}

//³õÊ¼»¯½ÇÉ«
int CRoleBase::Init(int nRoleID, const char* strCharFile)
{
	if (m_pCreature)return 1;

	m_nMoveing = 1;
	m_nRoleID = nRoleID;
	m_pCreature = new CCreature();
	m_pActionComplete = MakeInterface(this, &CRoleBase::OnActionMsg);
	m_pCreature->SetActionComplete(m_pActionComplete);

	m_pCreature->Load(strCharFile);
	m_pCreature->SetupBody(1, 0);
	m_pCreature->SetPosition(vec3_zero);
	m_pCreature->SetDirection(vec3(0.0f, -1.0f, 0.0f));
	m_pCreature->SetRoleID(nRoleID);

	m_AngleYaw.SetDirection(vec3(0.0f, -1.0f, 0.0f));

	m_pPathFind = new CNavigationFinder();
	m_pPathFind->SetMode(CNavigationFinder::MODE_PATHFIND_STRAIGHT);

	return 1;
}