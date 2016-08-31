#pragma once
#include "Loger.h"
#include "ResourceManager.h"
#include "ActionMap.h"
#include <SFML\Graphics.hpp>

class Configuration
{
public:
	using Textures = ResourceManager<std::string, sf::Texture>;

	Configuration(const Configuration&) = delete;
	Configuration & operator=(const Configuration&) = delete;

	Configuration();
	~Configuration();

	enum PlayerInputs : int{Up,Right,Down,Left};
	static ActionMap<int> playerInputs;


	static Loger* log();

	static sf::Texture & getTexture(const std::string & _key);

	static void initialize();

private:
	static void initInputs();
	static void initTextures();

	static Loger * s_pLoger;
	static ResourceManager<std::string, sf::Texture> m_textures;
};

