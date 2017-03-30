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

}