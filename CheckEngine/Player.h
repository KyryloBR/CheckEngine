#pragma once

#include "ActionTarget.h"
#include <SFML\Graphics.hpp>

class Player : public sf::Drawable, public ActionTarget<int>
{
public:
	Player();
	~Player();

	void setPosition(sf::Vector2f & _position);

	void processEvents();
	void update(sf::Time _deltaTime);


private:
	virtual void draw(sf::RenderTarget & _target, sf::RenderStates _states) const;

	sf::Sprite		m_Sprite;
	sf::Vector2f	m_velocity;
};