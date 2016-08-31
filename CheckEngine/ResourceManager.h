#pragma once
#include <SFML\Audio.hpp>
#include <unordered_map>
#include <memory>

template<typename Key, typename Resource>
class ResourceManager
{
public:
	ResourceManager(const ResourceManager &) = delete;
	ResourceManager & operator=(const ResourceManager&) = delete;

	ResourceManager() = default;
	~ResourceManager();

	template<typename ... Args>
	void load(const Key & _id, Args&& ... args);

	Resource & getResource(const Key & _id) const;

private:
	std::unordered_map<Key, std::unique_ptr<Resource>> m_Resources;
};

#include "ResourceManager.tpl"