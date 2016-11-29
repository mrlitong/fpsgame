#pragma once
#include "MessageBase.h"
#include "SkillSystem.h"
#include "RoleBase.h"
#include "Vector.h"

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