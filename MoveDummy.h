#pragma once
#ifndef __MOVE_DUMMY_H__
#define __MOVE_DUMMY_H__

#include "MathLib.h"
#include "Bounds.h"
#include "Vector.h"
#include "Shape.h"

class   CObjectDummy;
class   CBodyDummy;
class   CShapeCapsule;

class CMoveDummy
{
public:

	CMoveDummy();
	~CMoveDummy();
	void	SetCollision(int c);
	int		GetCollision() const;

	void	SetCollisionMask(int m);
	int		GetCollisionMask() const;
	void	SetGround(int g);
	int		GetGround() const;
	void	SetCeiling(int c);
	int		GetCeiling() const;
	void	SetPosition(const MathLib::vec3& p);
	const MathLib::vec3&    GetPosition() const;

	void	SetCollisionRadius(float radius);
	float	GetCollisionRadius() const;

	void	SetCollisionHeight(float height);
	float	GetCollisionHeight() const;

	void                    SetUp(const MathLib::vec3& u);
	const MathLib::vec3&    GetUp() const;

	void	SetEnabled(int e);
	int		GetEnabled() const;

	void                    SetVelocity(const MathLib::vec3& v);
	const MathLib::vec3&    GetVelocity() const;

	void	SetMaxVelocity(float v);
	float	GetMaxVelocity() const;

	void	SetAcceleration(float a);
	float	GetAcceleration() const;

	void	SetMaxThrough(float d);
	float	GetMaxThrough() const;

	void	Clear();

	int		Update(float fIfps, const MathLib::vec3& vDirection);
	int		Update(float fIfps, const MathLib::vec3& vDirection, const MathLib::vec3& pos);


private:
	void			Update_Bounds();
	MathLib::Mat4	Get_Body_Transform() const;
}