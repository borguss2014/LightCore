#pragma once

#include <vector>
#include <functional>
#include <unordered_map>
#include <memory>

#include "Event.h"

namespace LightCore
{
	typedef std::function<void(std::unique_ptr<Event>)> EventCallback;

	struct EventSystem
	{
		EventSystem();

		static bool AttachListener(const EventType& type, std::function<void(std::unique_ptr<Event>)> callback);
		static bool DetachListener();

		static bool ProcessEvents();
		static bool BroadcastEvent(std::unique_ptr<Event> evt);

		static bool QueueEvent(std::unique_ptr<Event> evt);

	private:
		static std::vector<std::unique_ptr<Event>>							m_EventQueue;
		static std::unordered_map<EventType, std::vector<EventCallback>>	m_EventMap;
	};

}