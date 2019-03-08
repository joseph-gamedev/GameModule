#pragma once 

#include <string>
#include <map>

class Audio;
class Resource;
class ResourceLoader;
class ResourceGroup;
class Image;

class ResourceManager
{
public:
	ResourceManager(ResourceLoader *loader);
	virtual ~ResourceManager() {}

	virtual bool LoadResourceGroup(const std::string &groupName);
	virtual void UnloadResourceGroup(const std::string &groupName);

	virtual Image *GetImage(const std::string &id);
	virtual bool HasString(const std::string &id);
	virtual std::string GetString(const std::string &id);
	virtual Audio *GetAudio(const std::string &id);

	virtual Image *GetImageFromPath(const std::string &path);
	
private:
	ResourceLoader *m_resourceLoader;

	std::map<std::string, ResourceGroup*> m_resourceGroups;

	std::map<std::string, Resource*> m_resPathMap;
	std::map<std::string, Resource*> m_resIdMap;

	std::map<std::string, std::string> m_stringMap;
};