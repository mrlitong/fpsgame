#pragma once
#ifndef INCLUDED_COMMONCONVERT
#define INCLUDED_COMMONCONVERT

#include <exception>
#include <string>
#include <memory>
#include <vector>




struct OutputCB
{
	virtual ~OutputCB()
	{

	}
	virtual void operator() (const char* data, unsigned int length) = 0;
};

class ColladaException : public std::exception
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

class FocolladaErrorHandler
{
public:
	FocolladaErrorHandler(std::string& xmlErrors);
	~FocolladaErrorHandler();
};


class FColladaDocument
{
public:
	void LoadFromText(const char* text);

	/** Returns the FCDocument that was loaded. */
	FCDocument* GetDocument() const { return document.get(); }

	/** Returns the \<extra\> data from the \<COLLADA\> element. */
	FCDExtra* GetExtra() const { return extra.get(); }

private:
	void ReadExtras(xmlNode* colladaNode);
	std::unique_ptr<FCDocument> document;
	std::unique_ptr<FCDExtra> extra;
};


#endif