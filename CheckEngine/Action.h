#pragma once
#include <SFML\Window\Event.hpp>

class Action
{
public:
	enum ActionType
	{
		RealTime = 1,
		Pressed  = 1 << 1,
		Realesed = 1 << 2
	};

	Action(const sf::Keyboard::Key & _key, int _type = ActionType::RealTime | ActionType::Pressed);
	Action(const sf::Mouse::Button & _button, int _type = ActionType::RealTime | ActionType::Pressed);
	~Action();

	bool test() const;

	bool operator==(const sf::Event & _event) const;
	bool operator==(const Action & _action) const;

private:
	template <typename>
	friend class ActionTarget;
	sf::Event m_event;
	int m_type;
};

