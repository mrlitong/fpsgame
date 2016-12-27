#include "GameMain.h"
#include "GameProcess.h"

CGameMain::CGameMain(void)
{

}

CGameMain::~CGameMain(void)
{

}
int CGameMain::Init()
{
	g_pSysControl->Init();
	m_pGameProcess = new CGameProcess();
	return m_pGameProcess->Init();
}

int CGameMain::ShutDown()
{
	g_pSysControl->Shutdown();
	m_pGameProcess->ShutDown();
	delete m_pGameProcess;
	return 0;
}