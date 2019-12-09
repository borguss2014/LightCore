#pragma once

#include <memory>
#include <cstdint>
#include <string>
#include <functional>

namespace LightCore
{
	class Event;

	class __declspec(novtable) GenericWindow
	{
	public:
		virtual ~GenericWindow() = default;

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		virtual void SetEventCallback(std::function<void(Event & e)> fn) = 0;
	};
}