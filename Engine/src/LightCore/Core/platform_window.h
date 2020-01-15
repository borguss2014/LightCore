#pragma once

#include <memory>
#include <cstdint>
#include <string>
#include <functional>

namespace LightCore
{
	struct Event;
	struct platform_window_props;

	struct __declspec(novtable) platform_window
	{
	public:
		virtual ~platform_window() = default;

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		virtual void SetEventCallback(std::function<void(Event& e)> fn) = 0;

		static std::unique_ptr<platform_window> Create(const platform_window_props& props);
	};
}