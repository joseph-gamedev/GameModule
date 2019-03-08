#pragma once

#include <string>

class ResourceLoader;

class Resource
{
public:

	Resource(ResourceLoader *loader, const std::string &path);
	virtual ~Resource() {}

	virtual bool Load() { return false; }

	bool IsLoaded() { return false; }

	virtual bool Init() = 0;

protected:
	ResourceLoader *m_loader;
	std::string		m_path;
};