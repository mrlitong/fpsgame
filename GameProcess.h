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
};