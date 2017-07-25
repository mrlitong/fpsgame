#include "precompiled.h"
#include "StdSkeletons.h"

#include "libxml/parser.h"
#include "libxml/xmlerror.h"



#include "CommonConvert.h"

#include "FUtils/FUXmlParser.h"

#include <map>

namespace
{
	struct SkeletonMap : public std::map<std::string, const Skeleton*>
	{
		SkeletonMap()
		{

		}
		~SkeletonMap()
		{
			for (iterator it = begin(); it != end(); ++it)
				delete it->second;
		}
	};
	SkeletonMap g_StandardSkeletons;
	SkeletonMap g_MappedSkeletons;

	struct Bone
	{
		std::string parent;
		std::string name;
		int targetId;
		int realTargetId;
	};
}

const Skeleton* Skeleton::FindSkeleton(const std::string& name)
{
	return g_MappedSkeletons[name];
}

Skeleton::Skeleton() : m(new Skeleton_impl) { }
Skeleton::~Skeleton() { }

struct Skeleton_impl
{
	std::string title;
	std::vector<Bone> bones;
	const Skeleton* target;
};