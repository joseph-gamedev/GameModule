#pragma once

#include "Resource.h"

class Image : public Resource
{	
public:
	Image(ResourceLoader *loader, const std::string &path) 
	:Resource(loader,path)
	{}
	virtual ~Image() {}

	virtual int getWidth() = 0;
	virtual int getHeight() = 0;

protected:

};