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