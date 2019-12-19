#include "EventSystem.h"

#include <LightCore/Core/Log.h>

std::vector<std::unique_ptr<LightCore::Event>> LightCore::EventSystem::m_EventQueue;
std::unordered_map<LightCore::EventType, std::vector<LightCore::EventCallback>>	LightCore::EventSystem::m_EventMap;

LightCore::EventSystem::EventSystem()
{
	
}

bool LightCore::EventSystem::AttachListener(const EventType& type, std::function<void(std::unique_ptr<Event>)> callback)
{
	if (callback == nullptr) {
		return false;
	}

	auto it = m_EventMap.find(type);

	if (it != m_EventMap.end()) {
		it->second.push_back(callback);
	}
	else {
		m_EventMap.emplace(type, std::vector<EventCallback>());
		m_EventMap[type].push_back(callback);
	}

	return true;
}

bool LightCore::EventSystem::DetachListener()
{
	return false;
}

bool LightCore::EventSystem::ProcessEvents()
{
	bool queueProcessed = true;

	for (std::vector<std::unique_ptr<Event>>::iterator it = m_EventQueue.begin(); it != m_EventQueue.end(); ++it) {
		
		bool messageProcessed = BroadcastEvent(std::move(*it));

		if (!messageProcessed) {
			queueProcessed = false;
			
			LC_CORE_ERROR("Event cannot be processed!");
		}
	}

	m_EventQueue.clear();

	return true;
}

bool LightCore::EventSystem::BroadcastEvent(std::unique_ptr<Event> evt)
{
	EventType eventType = evt->GetType();

	auto it = m_EventMap.find(eventType);

	if (it == m_EventMap.end()) {
		return false;
	}

	for (EventCallback callback : it->second) {
		callback(std::move(evt));
	}

	return true;
}

bool LightCore::EventSystem::QueueEvent(std::unique_ptr<Event> evt)
{
	if (evt == nullptr) {
		return false;
	}

	m_EventQueue.push_back(std::move(evt));

	return true;
}
