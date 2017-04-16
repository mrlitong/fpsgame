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
void CStar2DControl::Update()
{
	if (!IsEnable())
	{
		return;
	}
	m_fClickScale += m_nClickState * g_Engine.pGame->GetIFps() * 5.5f;
	if (m_fClickScale <= 0.8f)
	{
		m_nClickState = 1;
	}
	else if (m_fClickScale >= 1.0f)
	{
		m_fClickScale = 1.0f;
		m_nClickState = 0;
	}

	if (m_pNormalTex && m_pNormalTex->GetTexture())
	{
		CTexture *tex = m_pNormalTex->GetTexture();
		float width = CMathCore::Itof(tex->GetWidth());
		float height = CMathCore::Itof(tex->GetHeight());

		if (m_fNormalTexScale != 0.0f)
		{
			float aspect = height / width;
			width = g_Engine.pGui->GetWidth() * m_fNormalTexScale;
			height = width * aspect;
		}

		float CenterX = g_Engine.pGui->GetWidth() / 2.0f;
		float CenterY = g_Engine.pGui->GetHeight() / 2.0f;
		float x0 = CenterX - width / 2.0f;
		float y0 = CenterY - height / 2.0f;
		float x1 = CenterX + width / 2.0f;
		float y1 = CenterY + height / 2.0f;
		g_Engine.pGui->RenderTexture(tex, vec4(x0, y0, x1, y1), m_vNormalColor);
	}

}

