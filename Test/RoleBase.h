#pragma once
#include "MathLib.h"
#include "UtilStr.h"

class CCreature;
class CAction;
class CInterfaceBase;
class CNavigationFinder;

struct _ActionCallback_KeyFrame;
struct _ActionCallback_Complete;

class CNode;

class CRoleBase
{
public:
	CRoleBase(void);
	virtual ~CRoleBase(void);

	virtual int	Init(int nRoleID, const char* strCharFile);
	virtual void	Update(float ifps);

	int		GetRoleID() { return m_nRoleID; }
	void		SetRoleID(int nID) { m_nRoleID = nID; }

	CAction*	PlayAction(const char* szName, int nLoop = 0, float fCorrectingTime = 1.0f);
	CAction*	OrceAction(const char* szName, int nLoop = 0, float fCorrectingTime = 1.0f);

	void		SetPosition(const vec3& vPosition, int nOrce = 0);
	void		SetDirection(const vec3& vDirection, int nOrce = 0);
	void		SetDirectionTo(const vec3& vDirection, int nOrce = 0);

	virtual int	MoveTo(const vec3& vPosition);
	virtual int	MoveToPath(const vec3& vPosition);
	virtual void	StopMove();
	virtual void	StopMove(const vec3& vPosition);

	int		IsMoveing() { return m_nMoveing; }

	vec3		GetDirection();
	vec3		GetPosition();

	float	GetRoleRadius();
	float	GetRoleHeight();
protected:
	void		UpdateMove(float ifps);
	vec3		TestRoleZ(vec3& vPosition);
	CNode*	GetAssemblyNode(const CUtilStr& strAssembly);
	CNode*	GetAssemblyNode(int nAssembly);

	CCreature*	m_pCreature;
	int			m_nRoleID;
	int			m_nOrceDirection;

	CAngleYaw	m_AngleYaw;
	CNavigationFinder* m_pPathFind;
	int				 m_nMoveing;
	int				 m_nMoveToType;
	float			 m_fMoveSpeed;
	int				 m_nNowPathPoint;
	vec3				 m_vNowPathPosition;
	vec3				 m_vStartPathPosition;
	vec3				 m_vDestPathPosition;

	int			     m_nUpdateMove;
protected:
	CInterfaceBase*	m_pActionComplete;
	int				OnActionMsg(void* pVoid);
	virtual void		OnKeyFrame(_ActionCallback_KeyFrame* pKeyInfo);
	virtual void		OnActionComplete(_ActionCallback_Complete* pActInfo);
};