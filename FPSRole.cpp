#include "FPSRole.h"
#include "Engine.h"

CFPSRole::CFPSRole(void)
{
	m_nFire = 0;
	m_fAniCoolingTime = 0;
	m_fAniNowCoolingTime = 0;
	m_fSudCoolingTime = 0;	
	m_fEmitCoolingTime = 0;
}
CFPSRole::~CFPSRole(void)
{
	g_Engine.pGame->RemoveNode(m_pMuzzleEffect);
}