#pragma once
#ifndef __MOVE_DUMMY_H__
#define __MOVE_DUMMY_H__

#include "MathLib.h"
#include "Bounds.h"
#include "Vector.h"
#include "Shape.h"

class   CObjectDummy;
class   CBodyDummy;

class CMoveDummy
{
public:

	CMoveDummy();
	~CMoveDummy();
	void	SetCollision(int c);
	int		GetCollision() const;

	void	SetCollisionMask(int m);
	int		GetCollisionMask() const;
private:

}