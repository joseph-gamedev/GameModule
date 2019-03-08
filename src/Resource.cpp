#include "Resource.h"

Resource::Resource(ResourceLoader *loader, const std::string &path)
	: m_loader(loader)
	, m_path(path)
{

}