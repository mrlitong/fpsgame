#pragma once
#ifndef __ACTOR_BASE_H__
#define __ACTOR_BASE_H__

#include "Shape.h"
#include "Bounds.h"

class CActorBase
{    
	CActorBase();
	virtual ~CActorBase();

	void SetEnabled(int enable);
	int IsEnabled() const;

	void Update(float ifps);

	// intersection mask
	void SetIntersectionMask(int mask);
	int GetIntersectionMask() const;

	enum {            //×´Ì¬
		STATE_FORWARD = 0,
		STATE_BACKWARD,
		STATE_MOVE_LEFT,
		STATE_MOVE_RIGHT,
		STATE_CROUCH,	//¶×·ü
		STATE_JUMP,
		STATE_RUN,
		NUM_STATES,
	};


};