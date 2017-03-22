#include "RayControl.h"
#include "ObjectParticles.h"
#include "Engine.h"
#include "Game.h"
#include "Object.h"
#include "Player.h"
#include "Common.h"
#include "App.h"

CRayControl::CRayControl(void)
{
	m_pStarNormal = NULL;
	Init();
}

