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

const FMVector3 FMVector3_XAxis(1.0f, 0.0f, 0.0f);
static float identity[] = { 1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1 };
FMMatrix44 FMMatrix44_Identity(identity);

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

FColladaErrorHandler::FColladaErrorHandler(std::string& xmlErrors_)
	: xmlErrors(xmlErrors_)
{
	// Grab all the error output from libxml2, for useful error reporting
	xmlSetGenericErrorFunc(&xmlErrors, &errorHandler);

	FUError::AddErrorCallback(FUError::DEBUG_LEVEL, this, &FColladaErrorHandler::OnError);
	FUError::AddErrorCallback(FUError::WARNING_LEVEL, this, &FColladaErrorHandler::OnError);
	FUError::AddErrorCallback(FUError::ERROR_LEVEL, this, &FColladaErrorHandler::OnError);
}


CommonConvert::~CommonConvert()
{
	
}