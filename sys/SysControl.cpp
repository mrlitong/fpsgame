#include "SysControl.h"
#include "ControlsApp.h"
#include "ControlsXPad360.h"
#include "Engine.h"
#include "App.h"


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
	void Update_Keyboard(float ifps);
	void Update_XPad360(float ifps);


	CControlsApp        *m_pControlsApp;		//控制游戏中移动
	CControlsXPad360    *m_pControlsXPad360;
	ControlMode         m_nControlMode;			//控制模式
	
	int                 m_nOldMouseX;			//上一个鼠标坐标X
	int                 m_nOldMouseY;			//上一个鼠标坐标Y

	CObjectGui          *m_pTest3DUI;
	CWidgetLabel        *m_pTestMessageLabel;




};



CSysControlLocal::CSysControlLocal()
{

}
CSysControlLocal::~CSysControlLocal()
{

}

void CSysControlLocal::Init()
{
	m_pControlsApp = new CControlsApp;
	m_pControlsXPad360 = new CControlsXPad360(0);


	g_Engine.pApp->SetMouseGrab(0);
	g_Engine.pApp->SetMouseShow(0);			

	SetControlMode(CONTROL_KEYBORAD_MOUSE);

	m_pTest3DUI = new CObjectGui(2.0f, 1.0f, "data/core/gui/");
	m_pTest3DUI->SetMouseShow(0);		
	m_pTest3DUI->SetBackground(1);		
	m_pTest3DUI->SetBackgroundColor(vec4(1.0f, 0.0f, 0.0f, 1.0f));

	m_pTest3DUI->SetScreenSize(800, 400);
	m_pTest3DUI->SetControlDistance(1000.0f);	
	m_pTest3DUI->CreateMaterial("gui_base");	 //show in game	


	m_pTest3DUI->SetWorldTransform(Translate(0.0f, 0.0f, 2.0f) * MakeRotationFromZY(vec3(0.0f, -1.0f, 0.0f), vec3(0.0f, 0.0f, 1.0f)));

	m_pTestMessageLabel = new CWidgetLabel(m_pTest3DUI->GetGui());	//初始化文字标签
	m_pTest3DUI->GetGui()->AddChild(m_pTestMessageLabel, CGui::ALIGN_CENTER);
	m_pTestMessageLabel->SetFontColor(vec4(0.0f, 0.0f, 0.0f, 1.0f));



	m_pTestMessageLabel->SetFontSize(80);		//设置字体大小
	m_pTestMessageLabel->SetFontOutline(1);		//设置字体轮廓
	m_pTestMessageLabel->SetText("两个黄鹂鸣翠柳\n一行白鹭上青天\n窗含西岭千秋雪\n门泊东吴万里船");


	void CSysControlLocal::Update(float ifps)
	{
		Update_Mouse(ifps);
		Update_Keyboard(ifps);
		Update_XPad360(ifps);
	}


	m_nOldMouseX = 0;
	m_nOldMouseY = 0;
}
void CSysControlLocal::Shutdown()	
{
	g_Engine.pApp->SetMouseGrab(0);
	g_Engine.pApp->SetMouseShow(0);
	delete m_pControlsApp;
	m_pControlsApp = NULL;
	delete m_pControlsXPad360;
	m_pControlsXPad360 = NULL;
	delete m_pTestMessageLabel;
	m_pTestMessageLabel = NULL;
	delete m_pTest3DUI;
	m_pTest3DUI = NULL;

}

int CSysControlLocal::GetState(int state)
{

    return m_pControlsApp->GetState(state);
}
