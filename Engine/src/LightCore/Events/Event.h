#pragma once

namespace LightCore
{
	enum struct EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	struct __declspec(novtable) Event
	{
		virtual ~Event() = default;

		virtual EventType GetType() = 0;
	};

	struct InputEvent : public Event
	{
		InputEvent(EventType type)
			: m_EventType(type) {

		}

		~InputEvent() {}

		virtual EventType GetType() override {
			return m_EventType;
		};

	private:
		EventType m_EventType;
	};
}