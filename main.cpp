#include "Engine.h"
#include "interface.h"
#include "GameMain.h"


#include "Console.h"
#include "direct.h"
#include "HMDWrapper.h"

#include "EngineConsole.h"
#include "FileSystem.h"

int main(int argc, char* argv[])
{
#ifdef USE_HMD		
	g_pHMD->Init();
	int useHmd = g_pHMD->GetUseHMD();

}