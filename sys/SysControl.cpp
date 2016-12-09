#include "SysControl.h"
#include "ControlsApp.h"
#include "ControlsXPad360.h"

//解决跨平台字符集兼容问题
#ifdef _WIN32
#pragma execution_character_set("utf-8")
#endif

using namespace MathLib;

class CSysControlLocal : public CSysControl
{
public:
	CSysControlLocal();
    virtual ~CSysControlLocal();

	virtual void Init();	//角色要初始化，着色器要初始化，
	virtual void Update(float ifps);
	virtual void Shutdown();




}