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

void CMoveDummy::SetUp(const MathLib::vec3& u)
{
	m_vUp = u;
}

const MathLib::vec3& CMoveDummy::GetUp() const
{
	return m_vUp;
}
void CMoveDummy::SetEnabled(int e)
{
	m_nEnabled = e;
}

float CMoveDummy::GetCollisionHeight() const
{
	return m_pShape->GetHeight();
}
void CMoveDummy::SetUp(const MathLib::vec3& u)
{
	m_vUp = u;
}

const MathLib::vec3& CMoveDummy::GetUp() const
{
	return m_vUp;
}
void CMoveDummy::SetEnabled(int e)
{
	m_nEnabled = e;
}

int CMoveDummy::GetEnabled() const
{
	return m_nEnabled;
}

void CMoveDummy::SetVelocity(const MathLib::vec3& v)
{
	m_vVelocity = v;
}

const MathLib::vec3& CMoveDummy::GetVelocity() const
{
	return m_vVelocity;
}

void CMoveDummy::SetMaxVelocity(float v)
{
	m_fMaxVelocity = v;
}
float CMoveDummy::GetMaxVelocity() const
{
	return m_fMaxVelocity;
}

void CMoveDummy::SetAcceleration(float a)
{
	m_fAcceleration = a;
}
float CMoveDummy::GetAcceleration() const
{
	return m_fAcceleration;
}
float CMoveDummy::GetMaxThrough() const
{
	return m_fMaxThrough;
}
void CMoveDummy::Clear()
{
	SetVelocity(vec3_zero);
	SetMaxVelocity(2.5f);
	SetAcceleration(15.0f);
	SetCollision(1);
	SetCollisionMask(1);
	SetGround(0);
	SetCeiling(0);
	SetPosition(vec3_zero);
	SetUp(vec3(0.0f, 0.0f, 1.0f));
	SetEnabled(1);
	m_pDummy->SetEnabled(1);
	m_pObject->SetBody(NULL);
	m_pObject->SetBody(m_pDummy);

	m_pShape->SetBody(NULL);
	m_pShape->SetBody(m_pDummy);
	m_pShape->SetExclusionMask(2);

	m_pObject->SetWorldTransform(Get_Body_Transform());

	SetCollisionRadius(0.5f);
	SetCollisionHeight(1.0f);


	SetMaxThrough(0.4f);

	m_vecContacts.Clear();

}
int CMoveDummy::Update(float fIfps, const MathLib::vec3& vDirection)
{
	return Update(fIfps, vDirection, m_vPosition);
}
int CMoveDummy::Update(float fIfps, const MathLib::vec3& vDirection, const MathLib::vec3& pos)
{
	SetPosition(pos);

	vec3 vOldPosition = m_vPosition;

	float fVVelocity = Dot(m_vVelocity, m_vUp);
	float fHVelocity = CMathCore::Sqrt(CMathCore::Abs(m_vVelocity.length2() - fVVelocity*fVVelocity));

	m_vVelocity = m_vUp * fVVelocity + vDirection * fHVelocity;
	// time
	float time = fIfps;// * g_Engine.pPhysics->GetScale();

	// penetration tolerance
	float penetration = g_Engine.pPhysics->GetPenetrationTolerance();
	float penetration_2 = penetration * 2.0f;
	// clear collision flags
	if (GetCollision())
	{
		m_nGround = 0;
		m_nCeiling = 0;
	}

	// frozen linear velocity
	float frozen_velocity = g_Engine.pPhysics->GetFrozenLinearVelocity();


	// movement
	do
	{
		// adaptive time step
		float ifps = Min(time, MOVE_DUMMY_IFPS);
		time -= ifps;
		// integrate velocity
		m_vVelocity += vDirection * (m_fAcceleration * ifps);
		m_vVelocity += g_Engine.pPhysics->GetGravity() * ifps;

		fVVelocity = Dot(m_vVelocity, m_vUp);
		fHVelocity = CMathCore::Sqrt(m_vVelocity.length2() - fVVelocity*fVVelocity);

		m_vVelocity = m_vUp * fVVelocity + vDirection * m_fMaxVelocity;






	}
	while (time > EPSILON);








}