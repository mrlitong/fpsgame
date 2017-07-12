#include "SysControl.h"
#include "ControlsApp.h"
#include "ControlsXPad360.h"
#include "Engine.h"
#include "App.h"
#include "Engine.h"
#include "App.h"
#include "Input.h"
#include "ObjectGui.h"
#include "WidgetLabel.h"



#ifdef _WIN32
#pragma execution_character_set("utf-8")
#endif

using namespace MathLib;

class CSysControlLocal : public CSysControl
{
public:
	CSysControlLocal();
	virtual ~CSysControlLocal();

	virtual void Init();
	virtual void Update(float ifps);
	virtual void Shutdown();

	virtual int GetState(int state);
	virtual int ClearState(int state);

	virtual float GetMouseDX();
	virtual float GetMouseDY();

	virtual void SetMouseGrab(int g);
	virtual int GetMouseGrab();


	virtual void SetControlMode(ControlMode mode);
	virtual ControlMode GetControlMode() const;

private:
	void Update_Mouse(float ifps);
	void Update_Keyboard(float ifps);
	void Update_XPad360(float ifps);

	CControlsXPad360    *m_pControlsXPad360;
	ControlMode         m_nControlMode;	

	int                 m_nOldMouseX;
	int                 m_nOldMouseY;

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
	m_pTest3DUI->CreateMaterial("gui_base");


	m_pTest3DUI->SetWorldTransform(Translate(0.0f, 0.0f, 2.0f) * MakeRotationFromZY(vec3(0.0f, -1.0f, 0.0f), vec3(0.0f, 0.0f, 1.0f)));

	m_pTestMessageLabel = new CWidgetLabel(m_pTest3DUI->GetGui());
	m_pTest3DUI->GetGui()->AddChild(m_pTestMessageLabel, CGui::ALIGN_CENTER);
	m_pTestMessageLabel->SetFontColor(vec4(0.0f, 0.0f, 0.0f, 1.0f));

	m_pTestMessageLabel = new CWidgetLabel(m_pTest3DUI->GetGui());
	m_pTest3DUI->GetGui()->AddChild(m_pTestMessageLabel, CGui::ALIGN_CENTER);
	m_pTestMessageLabel->SetFontColor(vec4(0.0f, 0.0f, 0.0f, 1.0f));

	m_pTestMessageLabel->SetFontSize(80);
	m_pTestMessageLabel->SetFontOutline(1);
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

int CSysControlLocal::ClearState(int state)
{
	return m_pControlsApp->ClearState(state);
}

float CSysControlLocal::GetMouseDX()
{
	return m_pControlsApp->GetMouseDX();
}

float CSysControlLocal::GetMouseDY()
{
	return m_pControlsApp->GetMouseDY();
}
void CSysControlLocal::SetMouseGrab(int g)
{
	g_Engine.pApp->SetMouseGrab(g);
	g_Engine.pGui->SetMouseShow(!g);
}
int CSysControlLocal::GetMouseGrab()
{
	return g_Engine.pApp->GetMouseGrab();
}

void CSysControlLocal::SetControlMode(ControlMode mode)
{
	m_nControlMode = mode;
}

CSysControl::ControlMode CSysControlLocal::GetControlMode() const
{
	return m_nControlMode;
}

CSysControl::ControlMode CSysControlLocal::GetControlMode() const
{
	return m_nControlMode;
}
void CSysControlLocal::Update_Mouse(float ifps)
{
	float dx = (g_Engine.pApp->GetMouseX() - m_nOldMouseX) * g_Engine.pControls->GetMouseSensitivity() * 0.1f;//0.1f这个数值越大，鼠标移动越快
	float dy = (g_Engine.pApp->GetMouseY() - m_nOldMouseY) * g_Engine.pControls->GetMouseSensitivity() * 0.1f;//0.1这个数值越小，鼠标移动越慢

	m_pControlsApp->SetMouseDX(dx);
	m_pControlsApp->SetMouseDY(dy);

	if (g_Engine.pApp->GetMouseGrab() && g_Engine.pApp->GetActive())
	{
		g_Engine.pApp->SetMouse(g_Engine.pApp->GetWidth() / 2, g_Engine.pApp->GetHeight() / 2);
	}

	m_nOldMouseX = g_Engine.pApp->GetMouseX();
	m_nOldMouseY = g_Engine.pApp->GetMouseY();
}

void CSysControlLocal::Update_Keyboard(float ifps)
{


	if (g_Engine.pInput->IsKeyDown('w'))
		m_pControlsApp->SetState(CControls::STATE_FORWARD, 1);
	if (g_Engine.pInput->IsKeyDown('s'))
		m_pControlsApp->SetState(CControls::STATE_BACKWARD, 1);
	if (g_Engine.pInput->IsKeyDown('a'))
		m_pControlsApp->SetState(CControls::STATE_MOVE_LEFT, 1);
	if (g_Engine.pInput->IsKeyDown('d'))
		m_pControlsApp->SetState(CControls::STATE_MOVE_RIGHT, 1);

	if (g_Engine.pInput->IsKeyUp('w'))
		m_pControlsApp->SetState(CControls::STATE_FORWARD, 0);
	else if (g_Engine.pInput->IsKeyUp('s'))
		m_pControlsApp->SetState(CControls::STATE_BACKWARD, 0);

	if (g_Engine.pInput->IsKeyUp('a'))
		m_pControlsApp->SetState(CControls::STATE_MOVE_LEFT, 0);
	else if (g_Engine.pInput->IsKeyUp('d'))
		m_pControlsApp->SetState(CControls::STATE_MOVE_RIGHT, 0);
	if (g_Engine.pInput->IsKeyDown(' '))
		m_pControlsApp->SetState(CControls::STATE_JUMP, 1);
	else
		m_pControlsApp->SetState(CControls::STATE_JUMP, 0);
}
void CSysControlLocal::Update_XPad360(float ifps)
{
	m_pControlsXPad360->UpdateEvents();
	if (m_pControlsXPad360->IsAvailable())
	{
		CUtilStr strMessage;
		strMessage = CUtilStr("测试3D UI\n"),
		strMessage += CUtilStr(m_pControlsXPad360->GetName()) + "\n";


		strMessage += CUtilStr::Format("\n手柄测试\n");
		strMessage += CUtilStr::Format("LeftX:  %5.2f\n", m_pControlsXPad360->GetLeftX());
		strMessage += CUtilStr::Format("LeftY:  %5.2f\n", m_pControlsXPad360->GetLeftY());
		strMessage += CUtilStr::Format("RightX: %5.2f\n", m_pControlsXPad360->GetRightX());
		strMessage += CUtilStr::Format("RightY: %5.2f\n", m_pControlsXPad360->GetRightY());
		strMessage += "\nTriggers:\n";
		strMessage += CUtilStr::Format("Left:   %5.2f\n", m_pControlsXPad360->GetLeftTrigger());
		strMessage += CUtilStr::Format("Right:  %5.2f\n", m_pControlsXPad360->GetRightTrigger());

		strMessage += CUtilStr::Format("\nButtons:\n");
		for (int i = 0; i < CControlsXPad360::NUM_BUTTONS; ++i)
		{
			strMessage += CUtilStr::Format("%d ", m_pControlsXPad360->GetButton(i));
		}
		m_pTestMessageLabel->SetText(strMessage.Get());

		const float fPadThreshold = 0.5f;
		if (m_pControlsXPad360->GetLeftX() > fPadThreshold)
			m_pControlsApp->SetState(CControls::STATE_MOVE_RIGHT, 1);
		else if (m_pControlsXPad360->GetLeftX() < -fPadThreshold)
			m_pControlsApp->SetState(CControls::STATE_MOVE_LEFT, 1);
		else
		{
			m_pControlsApp->SetState(CControls::STATE_MOVE_LEFT, 0);
			m_pControlsApp->SetState(CControls::STATE_MOVE_RIGHT, 0);
		}
		if (m_pControlsXPad360->GetLeftY() > fPadThreshold)
			m_pControlsApp->SetState(CControls::STATE_FORWARD, 1);
		else if (m_pControlsXPad360->GetLeftY() < -fPadThreshold)
			m_pControlsApp->SetState(CControls::STATE_BACKWARD, 1);
		else
		{
			m_pControlsApp->SetState(CControls::STATE_FORWARD, 0);
			m_pControlsApp->SetState(CControls::STATE_BACKWARD, 0);
		}
		if (m_pControlsXPad360->GetButton(CControlsXPad360::BUTTON_SHOULDER_LEFT) || m_pControlsXPad360->GetButton(CControlsXPad360::BUTTON_SHOULDER_RIGHT))
			m_pControlsApp->SetState(CControls::STATE_JUMP, 1);
		else
			m_pControlsApp->SetState(CControls::STATE_JUMP, 0);
		if (m_pControlsXPad360->GetRightTrigger() > fPadThreshold || m_pControlsXPad360->GetLeftTrigger() > fPadThreshold)
		{
			m_pControlsApp->SetState(CControls::STATE_FIRE, 1);
			//震动
			m_pControlsXPad360->SetLeftMotor(0.3f);
			m_pControlsXPad360->SetRightMotor(0.3f);
		}
		else if (m_pControlsXPad360->GetRightTrigger() < fPadThreshold && m_pControlsXPad360->GetLeftTrigger() < fPadThreshold)
		{
			m_pControlsApp->SetState(CControls::STATE_FIRE, 0);

			m_pControlsXPad360->SetLeftMotor(0.0f);
			m_pControlsXPad360->SetRightMotor(0.0f);
		}
	}
}

CSysControlLocal local;
CSysControl *g_pSysControl = &local;