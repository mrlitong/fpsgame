#pragma once
#ifndef INCLUDED_STDSKELETONS
#define INCLUDED_STDSKELETONS

#include <string>
#include <memory>

struct Skeleton_impl;

class Sketeton
{
public:
	/** Default constructor - don't use; use FindSkeleton instead. */
	Skeleton();
	~Skeleton();

	/**
	* Returns the number of bones in the standard-skeleton which this current
	* skeleton is mapped onto.
	*/
	int GetBoneCount() const;



};

#endif