#pragma once

#include <functional>
#include <list>
#include <utility>
#include "ActionMap.h"

template <typename T = int>
class ActionTarget
{
public:
	ActionTarget(const ActionTarget<T> &) = delete;
	ActionTarget<T> & operator=(const ActionTarget<T> &) = delete;

	using FuncType = std::function<void(const sf::Event&)>;
	ActionTarget(const ActionMap<T>& _actionMap);

	bool processEvent(const sf::Event & _event) const;
	void processEvents() const;

	void bind(const T& _key, const FuncType& _callback);
	void unbind(const T& _key);

private:
	std::list<std::pair<T, FuncType>> m_lEventsRealTime;
	std::list<std::pair<T, FuncType>> m_lEventsPoll;

	const ActionMap<T>& m_actionMap;
};

#include "ActionTarget.tpl"