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

	virtual int GetState(int state);		//鼠标状态，键盘状态，人物状态，子弹状态等等。
	virtual int ClearState(int state);

	virtual float GetMouseDX();
	virtual float GetMouseDY();

	virtual void SetMouseGrab(int g);		//设置是否显示鼠标
	virtual int GetMouseGrab();			//获取鼠标状态，是显示呢还是不显示的状态。


	virtual void SetControlMode(ControlMode mode);			//控制模式
	virtual ControlMode GetControlMode() const;				//获取控制模式

private:
	void Update_Mouse(float ifps);

}