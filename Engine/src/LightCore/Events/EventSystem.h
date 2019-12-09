#pragma once

#include "Event.h"

#include <vector>
#include <functional>
#include <unordered_map>

namespace LightCore
{
	typedef std::function<void(Event*)> EventCallback;

	struct EventSystem
	{
		EventSystem();

		bool AddListener(const EventType& type, std::function<void(Event*)>& callback);

		bool ProcessQueue();
		bool BroadcastEvent(Event* e);

	private:
		std::vector<Event*>											m_EventQueue;
		std::unordered_map<EventType, std::vector<EventCallback>>	m_EventMap;
	};
}