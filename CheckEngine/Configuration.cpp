#include "Configuration.h"

Loger * Configuration::s_pLoger = 0;
ActionMap<int> Configuration::playerInputs;
ResourceManager<std::string, sf::Texture> Configuration::m_textures;

Configuration::Configuration()
{
}


Configuration::~Configuration()
{
	delete s_pLoger;
}

Loger * Configuration::log()
{
	if (!s_pLoger)
	{
		s_pLoger = new Loger();
	}
	return s_pLoger;
}

sf::Texture & Configuration::getTexture(const std::string & _key)
{
	return m_textures.getResource(_key);
}

void Configuration::initialize()
{
	initInputs();
	initTextures();
}

void Configuration::initInputs()
{
	playerInputs.map(PlayerInputs::Up, Action(sf::Keyboard::Up));
	playerInputs.map(PlayerInputs::Left, Action(sf::Keyboard::Left));
	playerInputs.map(PlayerInputs::Down, Action(sf::Keyboard::Down));
	playerInputs.map(PlayerInputs::Right, Action(sf::Keyboard::Right));
}

void Configuration::initTextures()
{
	m_textures.load("Player", "Ship.png");
}