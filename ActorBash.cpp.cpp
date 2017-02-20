#include "Engine.h"
#include "Game.h"
#include "ObjectDummy.h"
#include "BodyRigid.h"
#include "BodyDummy.h"
#include "Physics.h"
#include "ShapeCapsule.h"
#include "ActorBase.h"
#include "Visualizer.h"
#include "sys/SysControl.h"


using namespace MathLib;

#ifdef MEMORY_INFO
#define new new(__FILE__, __LINE__) 
#endif // MEMORY_INFO

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
}