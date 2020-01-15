#pragma once

#include <memory>

#include "Core.h"
#include "platform_window.h"

namespace LightCore
{
	struct platform_application
	{
		platform_application();
		virtual ~platform_application() = default;

		void Run();
		void OnUpdate();
		void OnEvent(std::unique_ptr<Event> evt);

		std::unique_ptr<platform_window> platformWindow;
		bool appRunning;
	};

	// To be defined in SANDBOX
	platform_application* CreateApplication();
}