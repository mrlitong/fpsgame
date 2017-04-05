#include "StarControl.h"
#include "ObjectParticles.h"
#include "Engine.h"
#include "Game.h"
#include "Object.h"
#include "Player.h"
#include "Common.h"
#include "App.h"

CStarControl::CStarControl(void)
{
	m_pStarNormal = NULL;
	m_pStarClick = NULL;
	m_fViewDistance = 0.5f;
	m_nClickState = 0;
	m_fClickScale = 1.0f;
	Init();
}