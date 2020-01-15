#include "platform_application.h"
#include "LightCore/Core/Log.h"
#include "Platform/Windows/win32_window.h"
#include "LightCore/Events/EventSystem.h"

// Enable High Performance Graphics
extern "C" {
	_declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
}

namespace LightCore 
{
	platform_application::platform_application()
	{
		appRunning = false;

		platform_window_props windowProps;
		windowProps.width = 800;
		windowProps.height= 600;
		windowProps.fullscreen = false;
		windowProps.vsync = false;
		windowProps.title = "LightCore Engine";

		platformWindow = platform_window::Create(windowProps);
		
		EventSystem::AttachListener(EventType::WindowClose, std::bind(&platform_application::OnEvent, this, std::placeholders::_1));
	}

	void platform_application::OnUpdate()
	{
		EventSystem::ProcessEvents();
	}

	void platform_application::OnEvent(std::unique_ptr<Event> evt)
	{
		appRunning = false;

		LC_CORE_WARN("Application received exit cmd...");
	}

	void platform_application::Run()
	{
		appRunning = true;

		while (appRunning)
		{
			platform_application::OnUpdate();

			platformWindow->OnUpdate();
		}
	}
}