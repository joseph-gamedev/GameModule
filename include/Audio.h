#pragma once

#include "Resource.h"

class Audio : public Resource
{	
public:
	Audio(ResourceLoader *loader, const std::string &path) 
	:Resource(loader,path)
	{}
	virtual ~Audio() {}

	virtual bool Load() = 0;
	virtual bool Play(int numloop) = 0;
	
protected:

};