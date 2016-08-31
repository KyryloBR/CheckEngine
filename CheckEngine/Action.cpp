#include "Action.h"


Action::Action(const sf::Keyboard::Key & _key, int _type) : m_type(_type)
{
	m_event.type = sf::Event::EventType::KeyPressed;
	m_event.key.code = _key;
}


Action::Action(const sf::Mouse::Button & _button, int _type) : m_type(_type)
{
	m_event.type = sf::Event::EventType::MouseButtonPressed;
	m_event.mouseButton.button = _button;
}

Action::~Action()
{

}

bool Action::test() const
{
	bool res = false;
	if (m_event.type == sf::Event::EventType::KeyPressed)
	{
		if (m_type & ActionType::Pressed)
		{
			res = sf::Keyboard::isKeyPressed(m_event.key.code);
		}	
	}
	else if (m_event.type == sf::Event::EventType::MouseButtonPressed)
	{
		if (m_type & ActionType::Pressed)
		{
			res = sf::Mouse::isButtonPressed(m_event.mouseButton.button);
		}
	}
	return res;
}

bool Action::operator==(const sf::Event & _event) const
{
	bool res = false;
	if (_event.type == sf::Event::EventType::KeyPressed)
	{
		if ((m_type & ActionType::Pressed) && m_event.type == sf::Event::EventType::KeyPressed)
		{
			res = _event.key.code == m_event.key.code;
		}
	}
	else if (_event.type == sf::Event::EventType::KeyReleased)
	{
		if ((m_type & ActionType::Realesed) && m_event.type == sf::Event::EventType::KeyReleased)
		{
			res = _event.key.code == m_event.key.code;
		}
	}
	else if (_event.type == sf::Event::EventType::MouseButtonPressed)
	{
		if ((m_type & ActionType::Pressed) && m_event.type == sf::Event::EventType::MouseButtonPressed)
		{
			res = _event.mouseButton.button == m_event.mouseButton.button;
		}
	}
	else if (_event.type == sf::Event::EventType::MouseButtonReleased)
	{
		if ((m_type & ActionType::Realesed) && m_event.type == sf::Event::EventType::MouseButtonReleased)
		{
			res = _event.mouseButton.button == m_event.mouseButton.button;
		}
	}
	return res;
}

bool Action::operator==(const Action & _other) const
{
	return _other.m_type == this->m_type && _other == this->m_event;
}