#include "ResourceManager.h"
#include <string>
#include <iostream>

template<typename Key, typename Resource>
ResourceManager<Key, Resource>::~ResourceManager()
{
}

template<typename Key, typename Resource>
template<typename ... Args>
void ResourceManager<Key, Resource>::load(const Key & _id, Args&& ... args)
{
	std::unique_ptr<Resource> pResource(new Resource);
	if (pResource->loadFromFile(std::forward<Args>(args)...))
	{
		std::cout << "File hasn`t been loaded.";
	}
	m_Resources.emplace(_id, std::move(pResource));
}

template<typename Key, typename Resource>
Resource & ResourceManager<Key, Resource>::getResource(const Key & _id) const
{
	return *m_Resources.at(_id);
}