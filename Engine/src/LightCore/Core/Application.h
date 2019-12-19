#pragma once

#include <memory>

#include "Core.h"
#include "GenericWindow.h"

namespace LightCore
{
	struct Application
	{
		Application();
		virtual ~Application() = default;

		void Run();

		void OnUpdate();

		std::unique_ptr<GenericWindow> m_Window;
		bool m_Running;
	};

	// To be defined in SANDBOX
	Application* CreateApplication();
}