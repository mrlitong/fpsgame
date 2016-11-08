#ifndef __CAMERA_BASE_H__
#define __CAMERA_BASE_H__
#include "Player.h"

class CPlayer;

/*
*包括摄像头角度，视觉半径，最大最小角度，转向，视线方向，等。
*/
class CCameraBase : public CPlayer
{
public:

	CCameraBase();
	virtual ~CCameraBase();

	void SetEnabled(int nEnable);
	int IsEnabled() const;

	void SetHMDEnabled(int nEnable);
	int IsHMDEnabled() const;

	void SetRadius(float r);
	float GetRadius() const;

	// minimum theta angle
	void SetMinThetaAngle(float angle);
	float GetMinThetaAngle() const;

	// maximum theta angle
	void SetMaxThetaAngle(float angle);
	float GetMaxThetaAngle() const;

	// turning
	void SetTurning(float turning);
	float GetTurning() const;
	// phi angle
	void SetPhiAngle(float angle);
	float GetPhiAngle() const;

	// theta angle
	void SetThetaAngle(float angle);
	float GetThetaAngle() const;

	// view direction
	void SetViewDirection(const MathLib::vec3 &direction);
	const MathLib::vec3 &GetViewDirection() const;

	// update
	virtual void UpdateControls(float ifps);

	// flush
	virtual void FlushTransform();

	// bounds
	virtual const CBoundBox &GetBoundBox() const;
	virtual const CBoundSphere &GetBoundSphere() const;

	void SetFlush(int nFlush) { m_nFlush = nFlush; }
	void SetMouseControls(int nEnable) { m_nEnabelMouse = nEnable; }

}

#endif