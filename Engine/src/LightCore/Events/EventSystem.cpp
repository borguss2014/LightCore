#include "EventSystem.h"

#include <LightCore/Core/Log.h>

LightCore::EventSystem::EventSystem()
{

}

bool LightCore::EventSystem::AddListener(const EventType& type, std::function<void(Event*)>& callback)
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

bool LightCore::EventSystem::ProcessQueue()
{
	bool queueProcessed = true;

	for (Event* e : m_EventQueue) {
		bool messageProcessed = BroadcastEvent(e);

		if (!messageProcessed) {
			queueProcessed = false;
			
			LC_CORE_ERROR("Event queue processing unable to continue!");

			break;
		}
	}

	return queueProcessed;
}

bool LightCore::EventSystem::BroadcastEvent(Event* e)
{
	EventType eventType = e->GetType();

	auto it = m_EventMap.find(eventType);

	if (it == m_EventMap.end()) {
		return false;
	}

	for (EventCallback callback : it->second) {
		callback(e);
	}

	return true;
}