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
private:
	std::string msg;
public:
	ColladaException(const std::string& msg) :msg(msg)
	{

	}
	~ColladaException()
		throw()
	{

	}
};


#endif