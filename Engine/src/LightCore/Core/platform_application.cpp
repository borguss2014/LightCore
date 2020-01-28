#include "platform_application.h"
#include "LightCore/Core/Log.h"
#include "Platform/Windows/win32_window.h"
#include "LightCore/Events/EventSystem.h"

/* Enable high performance graphics on nVidia Optimus laptops
*  TODO(Cristian): Should allow the user to select the preferred GPU in the future
*/
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
		windowProps.title = "LightCore v0.0.1";

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