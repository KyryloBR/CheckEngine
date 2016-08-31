#include "Player.h"
#include "Configuration.h"
#include "AdditionVariable.h"

Player::Player() : ActionTarget(Configuration::playerInputs), m_velocity(0.0,0.0)
{
	m_Sprite.setTexture(Configuration::getTexture("Player"));
	m_Sprite.setOrigin(49.5, 37.5);
	bind(Configuration::PlayerInputs::Up, [this](const sf::Event &)
	{
		m_velocity.y = -250;
	});

	bind(Configuration::PlayerInputs::Right, [this](const sf::Event &)
	{
		m_velocity.x = 300;
	});

	bind(Configuration::PlayerInputs::Down, [this](const sf::Event &)
	{
		m_velocity.y = 250;
	});

	bind(Configuration::PlayerInputs::Left, [this](const sf::Event &)
	{
		m_velocity.x = -300;
	});

}

Player::~Player()
{

}

void Player::setPosition(sf::Vector2f & _position)
{
	m_Sprite.setPosition(_position);
}

void Player::processEvents()
{
	m_velocity.x = 0;
	m_velocity.y = 0;
	ActionTarget::processEvents();
}

void Player::update(sf::Time _deltaTime)
{
	float seconds = _deltaTime.asSeconds();
	m_Sprite.move(seconds * m_velocity);
}

void Player::draw(sf::RenderTarget & _target, sf::RenderStates _states) const
{
	_target.draw(m_Sprite, _states);
}