#pragma once
#include "Rolebase.h"
#include "UtilStr.h"

class CAnimationBlendRotate;
class CAnimationBlendDual;
class CObjectParticles;
class CWorldEffect;
class CObjectMeshSkinned;

class CFPSRole :public CRoleBase
{
public:
	CFPSRole(void);
	virtual ~CFPSRole(void);
	virtual int  Init(int nRoleID, const char* strCharFile);
	virtual void	Update(float ifps);

	void    SetMuzzleSpinU_D(float vValue);
	void    SetMuzzleSpinL_R(float vValue);
	void    SetPaceAnimationF_B(int nF_B);
	void    SetPaceAnimationL_R(int nF_B);
	void    OpenFire() { m_nFire = 1; }
	void    CloseFire() { m_nFire = 0; }
	int     SetupArms(int nAssembly, int nBody);
protected:
	virtual void		OnKeyFrame(_ActionCallback_KeyFrame* pKeyInfo);
	virtual void		OnActionComplete(_ActionCallback_Complete* pActInfo);
protected:
	CAnimationBlendRotate*		m_pStand[2];
	CAnimationBlendRotate*		m_pFire[2];
	CAnimationBlendDual*		m_pRun[2];

	int						m_nFire;
	float					m_fAniCoolingTime;//后坐力动画冷却时间
	float					m_fAniNowCoolingTime;
	float					m_fSudCoolingTime;//开枪声音冷却时间
	float					m_fSudNowCoolingTime;
	float					m_fEmitCoolingTime;//发射子弹冷却时间
	float					m_fEmitNowCoolingTime;

	CUtilStr					m_strMuzzleBone;
	int						m_nMuzzleBone;
	CObjectMeshSkinned*		m_pArmsMesh;

	void						UpdateFire(float ifps);
	virtual void				OnFire(float fCoolingTime);
	void						UpdateMuzzleTransform();
	CUtilStr					m_strBulletName;
	CObjectParticles*			m_pBulletParticle;
	CUtilStr					m_strMuzzleEffect;
	CWorldEffect*				m_pMuzzleEffect;
	mat4						m_matMuzzleTransform;
};

