#pragma once

#include <string>


#ifndef INCLUDED_COMMONCONVERT
#define INCLUDED_COMMONCONVERT

struct OutputCB
{
	virtual ~OutputCB()
	{

	}
};

class ColladaException
{
	std::string msg;
	ColladaException(const std::string& msg) :msg(msg)
	{

	}
	~ColladaException()
		throw()
	{

	}
};


#endif