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

CRayControl::~CRayControl(void)
{
	g_Engine.pGame->RemoveNode(m_pStarNormal);
}

int CRayControl::Init()
{
	m_pStarNormal = (CObjectParticles*)g_Engine.pGame->LoadNode("data/StarControl/ray_line.node");

	if (!m_pStarNormal)
		return 0;

	m_pStarNormal->GetTracker(TRACKER_CUSTOM)->SetTrackValue(0, 0, vec4(1.0f, 1.0f, 1.0f, 0.5f));

	return 1;
}
void CRayControl::Update(const mat4& matTransform, const vec3 & vOffset)
{
	m_pStarNormal->SetWorldTransform(matTransform*Translate(vOffset));
}

int CRayControl::isEnable()
{
	return m_pStarNormal->IsEnabled();
}

