#pragma once
#include "GameProcess.h"
#include "Engine.h"
#include "World.h"
#include "App.h"
#include "ToolsCamera.h"
#include "ControlsApp.h"
#include "MathLib.h"
#include "Game.h"
#include "Editor.h"
#include "Input.h"
#include "BlueRayUtils.h"
#include "World.h"
#include "Object.h"
#include "Action.h"
#include "FPSRoleLocal.h"
#include "StarControl.h"
#include "RayControl.h"
#include "CameraBase.h"
#include "ActorBase.h"
#include "sys/SysControl.h"
#include "FileSystem.h"
#include "RenderManager.h"
#include "Texture.h"
using namespace MathLib;


class CFPSRoleLocal;
class CCameraBase;
class CActorBase;
class CStarControl;
class CRayControl;
class CGameProcess : public CMessageBase
{
public:
	CGameProcess(void);
	virtual ~CGameProcess(void);
	int        Init();
	int        ShutDown();
	int        Update();
	int        Render();

	CRoleBase*  GetRole(int nID);
	CRoleBase*  GetRoleFormIndex(int nIndex);

public:
	static int  KeyPress(unsigned int nKey);
	static int  KeyRelease(unsigned int nKey);

protected:
	CFPSRoleLocal*	m_pRole;
	CSkillSystem*		m_pSkillSystem;
	CCameraBase*		m_pCameraBase;
	CStarControl*		m_pStarControl;
	CRayControl*		m_pRayControl;
private:
};