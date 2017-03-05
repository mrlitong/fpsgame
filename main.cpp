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

}