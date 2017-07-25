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
	
	/**
	* Tries to find a skeleton that matches the given root bone name.
	* Returns NULL if there is no match.
	*/
	static const Skeleton* FindSkeleton(const std::string& rootBoneName);


	int GetBoneID(const std::string& name) const;
	int GetRealBoneID(const std::string& name) const;



	static void LoadSkeletonDataFromXml(const char* xmlData, size_t xmlLength, std::string& xmlErrors);

	std::unique_ptr<Skeleton_impl> m;
private:
	Skeleton(Skeleton&);
};

#endif	// INCLUDED_STDSKELETONS