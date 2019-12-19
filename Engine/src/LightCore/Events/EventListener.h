#pragma once

namespace LightCore
{
	struct Event;

	struct __declspec(novtable) EventListener
	{
	private:
		virtual ~EventListener() = default;

		virtual void OnEvent(Event& e) = 0;
	};
}