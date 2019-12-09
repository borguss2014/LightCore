#pragma once

namespace LightCore
{
	class Event;

	class __declspec(novtable) EventListener
	{
	private:
		virtual ~EventListener() = default;

		virtual void OnNotify(Event& e) = 0;
	};
}