#pragma once
#include "MathLib.h"	//外部依赖
#include "UtilStr.h"	//外部依赖

class CCreature;
class CAction;
class CInterfaceBase;
class CNavigationFinder;


struct _ActionCallback_KeyFrame;
struct _ActionCallback_Complete;
using namespace MathLib;
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

private:
}