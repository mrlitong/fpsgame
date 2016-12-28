#include "GameProcess.h"
#include "Object.h"
#include "Engine.h"
#include "World.h"
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
}