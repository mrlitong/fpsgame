#include "Engine.h"
#include "Game.h"
#include "ObjectDummy.h"
#include "BodyRigid.h"
#include "BodyDummy.h"



#ifdef MEMORY_INFO
#define new new(__FILE__, __LINE__) 
#endif // MEMORY_INFO

using namespace MathLib;

/*
*/
#define ACTOR_BASE_IFPS             (1.0f / 60.0f)
#define ACTOR_BASE_CLAMP            89.9f
#define ACTOR_BASE_COLLISIONS       4

/*
*/


CActorBase::CActorBase()
{
	m_vUp = vec3(0.0f, 0.0f, 1.0f);
	m_pObject = new CObjectDummy();
	m_pDummy = new CBodyDummy();
	m_pShape = new CShapeCapsule(1.0f, 1.0f);

	m_nFlush = 0;
	m_vPosition = Vec3_zero;
	m_vVelocity = Vec3_zero;
	m_fPhiAngle = 0.0f;			//倾斜角		二维平面坐标系中，直线向Y周延伸的方向与X轴正向之间的夹角
	m_fThetaAngle = 0.0f;			//方位角，正北方那条线与当前线条按照顺时针走过的角度

	for (int i = 0; i < NUM_STATES; i++)
	{
		m_pStates[i] = 0;
		m_pTimes[i] = 0.0f;
	}

}