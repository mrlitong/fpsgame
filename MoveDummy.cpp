#include "MoveDummy.h"
#include "ObjectDummy.h"
#include "BodyDummy.h"
#include "ShapeCapsule.h"

#include "Utils.h"
#include "Engine.h"
#include "Physics.h"
#include "Game.h"
#include "World.h"

#define MOVE_DUMMY_IFPS			(1.0f/100.0f)		
#define MOVE_DUMMY_CLAMP           89.9f
#define MOVE_DUMMY_COLLISIONS		1

using namespace MathLib;

CMoveDummy::CMoveDummy()		//构造函数
{
	m_pObject = new CObjectDummy();		//创造一个虚拟实体类
	m_pDummy = new CBodyDummy();
	m_pShape = new CShapeCapsule(0.5f, 1.0f);

	SetCollisionMask(1);
	Clear();
}

CMoveDummy::~CMoveDummy()
{
	m_pDummy->SetObject(NULL);
	SAFE_DELETE(m_pObject);
	SAFE_DELETE(m_pDummy);
}

void CMoveDummy::SetCollision(int c)
{
	m_nCollision = c;
}

int CMoveDummy::GetCollision() const
{
	return m_nCollision;
}

void CMoveDummy::SetCollisionMask(int m)
{
	m_pShape->SetCollisionMask(m);
}

int CMoveDummy::GetCollisionMask() const
{
	return m_nCollisionMask;
}

void CMoveDummy::SetGround(int g)
{
	m_nGround = g;
}

int CMoveDummy::GetGround() const
{
	return m_nGround;
}

void CMoveDummy::SetCeiling(int c)
{
	m_nCeiling = c;
}

int CMoveDummy::GetCeiling() const
{
	return m_nCeiling;
}

void CMoveDummy::SetPosition(const MathLib::vec3& p)
{
	m_vPosition = p;
}

const MathLib::vec3& CMoveDummy::GetPosition() const
{
	return m_vPosition;
}

void CMoveDummy::SetCollisionRadius(float radius)
{
	if (!Compare(m_pShape->GetRadius(), radius))
	{
		m_pDummy->SetPreserveTransform(Mat4(Translate(m_vUp * (radius - m_pShape->GetRadius()))) * m_pDummy->GetTransform());
		m_pShape->SetRadius(radius);
	}

	Update_Bounds();
}


float CMoveDummy::GetCollisionRadius() const
{
	return m_pShape->GetRadius();
}

void CMoveDummy::SetCollisionHeight(float height)
{
	if (!Compare(m_pShape->GetHeight(), height))
	{
		m_pDummy->SetPreserveTransform(Mat4(Translate(m_vUp * (height - m_pShape->GetHeight()) * 0.5f)) * m_pDummy->GetTransform());
		m_pShape->SetHeight(height);
	}

	Update_Bounds();
}
float CMoveDummy::GetCollisionHeight() const
{
	return m_pShape->GetHeight();
}


