#include "precompiled.h"
#include "CommonConvert.h"

#include <algorithm>

void require_(int line, bool value, const char* type, const char* message)
{
	if (value) return;
	char linestr[16];
	sprintf(linestr, "%d", line);
	throw ColladaException(std::string(type) + " (line " + linestr + "): " + message);
}