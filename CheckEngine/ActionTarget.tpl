#include "ActionTarget.h"

template<typename T>
ActionTarget<T>::ActionTarget(const ActionMap<T> & _actionMap) : m_actionMap(_actionMap)
{
}

template <typename T>
bool ActionTarget<T>::processEvent(const sf::Event & _event) const
{
		bool res = false;
		auto action = m_lEventsPoll.begin();
		while (action != m_lEventsPoll.end() || res != true)
		{
			if (m_actionMap.get(action->first) == _event)
			{
				action->second(_event);
				res = true;
			}
		}
		return res;
}

template <typename T>
void ActionTarget<T>::processEvents() const
{
		for (auto & action : m_lEventsRealTime)
		{
			const Action _action = m_actionMap.get(action.first);
			if (_action.test())
			{
				action.second(_action.m_event);
			}
		}
}

template <typename T>
void ActionTarget<T>::bind(const T & _key, const FuncType & _callback)
{
		const Action & _action = m_actionMap.get(_key);
		if (_action.m_type & Action::ActionType::RealTime)
		{
			m_lEventsRealTime.emplace_back(_key, _callback);
		}
		else
		{
			m_lEventsPoll.emplace_back(_key, _callback);
		}
}

template <typename T>
void ActionTarget<T>::unbind(const T & _key)
{
		auto remove_func = [&_key](const std::pair<Action, FuncType> & _func) -> bool
		{
			return _func.first == _key;
		};

		const Action action = m_actionMap.get(key);
		if (action.m_type & Action::ActionType::RealTime)
		{
			m_lEventsRealTime.remove_if(remove_func);
		}
		else
		{
			m_lEventsPoll.remove_if(remove_func);
		}
}

