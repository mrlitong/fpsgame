#include "Star2DControl.h"
#include "Engine.h"

using namespace MathLib;

CStar2DControl::CStar2DControl(void)
{
	m_pNormalTex = NULL;
	m_pClickTex = NULL;
	m_nEnabled = 1;
	m_nClickState = 0;
	m_fClickScale = 1.0f;
	m_vNormalColor = vec4_one;
	m_vClickColor = vec4_one;
	m_fNormalTexScale = 0.1f;
	m_fClickTexScale = 0.1f;
	Init();
}

CStar2DControl::~CStar2DControl(void)
{
	g_Engine.pGui->ReleaseTexture(m_pNormalTex);
	g_Engine.pGui->ReleaseTexture(m_pClickTex);
}

int CStar2DControl::Init()
{
	return Load(NORMAL_NAME, CLICK_NAME);
}

