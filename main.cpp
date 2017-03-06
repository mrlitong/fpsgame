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
	if (useHmd)
	{
		//头盔3d
		render_stereo = 2;

		//自定义窗口分辨率 与头盔分辨率一直
		video_mode = -1;
		video_width = 2160;
		video_height = 1200;

		// 全屏方式 0：窗口    1：全屏
		video_fullscreen = 0;

		video_resizable = 0;
		video_vsync = 0;
	}
	else
	{
		//无头盔
		render_stereo = 0;

		//自定义窗口分辨率
		video_mode = -1;
		video_fullscreen = 0;
		video_width = 1280;
		video_height = 720;
		video_resizable = 0;
		video_vsync = 0;
	}
#else
	render_stereo = 0;

	video_mode = -1;	
	video_fullscreen = 0;	
	video_width = 1280;		
	video_height = 720;		
	video_resizable = 0;	
	video_vsync = 0;		
#endif

	char pAppPath[260];		
	getcwd(pAppPath, 260);
	strcat(pAppPath, "\\");

	CGameMain t_Game;

	CInterfaceBase *pInit = MakeInterface(&t_Game, &CGameMain::Init);
	CInterfaceBase *pUpdate = MakeInterface(&t_Game, &CGameMain::Update);
	CInterfaceBase *pShutdown = MakeInterface(&t_Game, &CGameMain::ShutDown);
	CInterfaceBase *pRender = MakeInterface(&t_Game, &CGameMain::Render);

	char *pArg[3] = { NULL, "-engine_config", "data/TestProject.cfg" };	
	g_Engine.pEngine = new CEngine(NULL, pAppPath, NULL, NULL, 3, pArg, NULL, "1123581321", pInit);	

	//1.空 2.路径 3.空 4.空 5.参数个数？  6.一个指针数组指针,就是上面定义的那个  7.空 8.密码 9.一个类指针
	//CEngine(CApp *pApp, const char *pAppPath, void *pExternalWindow, const char *pHomePath, int argc, char **argv, const char *pProject, const char *pPassword, CInterfaceBase *pInitInterface);

	g_Engine.pEngine->SetUpdateInterface(pUpdate);
	g_Engine.pEngine->SetShutdownInterface(pShutdown);	//如果注释掉，退出调试会弹错
	g_Engine.pEngine->SetRenderInterface(pRender);	//渲染界面，注释掉貌似没有任何影响



}