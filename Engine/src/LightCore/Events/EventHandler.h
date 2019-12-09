#pragma once

namespace LightCore
{ 
	class Event;

	class __declspec(novtable) EventHandler
	{
	public:
		virtual ~EventHandler() = default;

		virtual bool Process(Event& evt) = 0;
	};
}