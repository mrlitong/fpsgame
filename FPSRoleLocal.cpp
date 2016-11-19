#include "FPSRoleLocal.h"
#include "Creature.h"

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


int CFPSRoleLocal::Init(int nRoleID,char* strCharFile)
{
	CFPSRole::Init(nRoleID, strCharFile);

	return 0;
}
