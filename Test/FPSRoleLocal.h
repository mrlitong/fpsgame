#pragma once
#include "FPSRole.h"

class CActorBase;

class CFPSRoleLocal : public CFPSRole
{
public:
	CFPSRoleLocal(void);
	virtual ~CFPSRoleLocal(void);
public:
	virtual int  Init(int nRoleID, const char* strCharFile);
	virtual void	Update(float ifps);
	void			UpdateTransform(const MathLib::mat4 & matRotate);

	MathLib::vec3 GetActorPosition();
	void			SetActorPosition(const vec3& vPosition);
	void			SetActorDirection(const vec3& vDirection);
	void			UpdateActor(float ifps);
	MathLib::vec3 GetCameraOffset() { return m_vCameraOffset; }
protected:
	virtual void OnFire(float fCoolingTime);
	int				m_nCharMode;
	CActorBase*		m_pActorBase;
	MathLib::vec3		m_vCameraOffset;
	MathLib::vec3		m_vGunOffset;
	MathLib::vec3		m_vRotateOffset;
};