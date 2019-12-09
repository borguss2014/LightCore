#pragma once

namespace LightCore
{
	enum class EventType
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
}