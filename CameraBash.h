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
private:
	void Update_Controls(float ifps);
	void Update_HMD(float ifps);
	// update bounds
	void Update_Bounds();

	// update transformation
	virtual void Update_Transform();

	float m_fRadius;
	float m_fMinThetaAngle;             // minimum theta angle
	float m_fMaxThetaAngle;             // maximum theta angle
	float m_fAcceleration;              // acceleration
	float m_fTurning;                   // turning

	int m_nFlush;                       // flush flag
	MathLib::Vec3 m_vPosition;          // position
	MathLib::vec3 m_vDirection;         // direction
	float m_fPhiAngle;                  // phi angle
	float m_fThetaAngle;                // theta angle

	CBoundBox m_BoundBox;               // bounding box
	CBoundSphere m_BoundSphere;         // bounding sphere

	CPlayer *m_pLastPlayer;

	int m_nHMDEnable;
	int m_nEnabelMouse;
}

#endif