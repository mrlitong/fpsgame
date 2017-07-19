#pragma once
#ifndef INCLUDED_COMMONCONVERT
#define INCLUDED_COMMONCONVERT

#include <exception>
#include <string>
#include <memory>
#include <vector>

class Skeleton;


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
/**
* Standard error handler - logs FCollada messages using Log(), and also
* maintains a list of XML parser errors.
*/
class FoclladaErrorHandler
{

private:
	void OnError(FUError::Level errorLevel, uint32 errorCode, uint32 lineNumber);
	std::string& xmlErrors;

	void operator=(FColladaErrorHandler);

public:
	FoclladaErrorHandler(std::string& xmlErrors);
	~FoclladaErrorHandler();
};

/**
* Standard document loader. Based on FCDocument::LoadFromText, but allows
* access to \<extra\> nodes at the document level (i.e. directly in \<COLLADA\>).
*/
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