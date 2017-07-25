#include "precompiled.h"
#include "CommonConvert.h"

#include "StdSkeletons.h"

#include <algorithm>


#include <cassert>

void require_(int line, bool value, const char* type, const char* message)
{
	if (value) return;
	char linestr[16];
	sprintf(linestr, "%d", line);
	throw ColladaException(std::string(type) + " (line " + linestr + "): " + message);
}

/** Error handler for libxml2 */
void errorHandler(void* ctx, const char* msg, ...)
{
	char buffer[1024];
	va_list ap;
	va_start(ap, msg);
	vsnprintf(buffer, sizeof(buffer), msg, ap);
	buffer[sizeof(buffer) - 1] = '\0';
	va_end(ap);

	*((std::string*)ctx) += buffer;
}