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

