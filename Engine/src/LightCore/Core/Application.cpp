#include "Application.h"

#include "LightCore/Core/Log.h"

#include "Platform/Windows/Window.h"

#include "LightCore/Events/EventSystem.h"

// Enable High Performance Graphics
extern "C" {
	_declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
}

namespace LightCore 
{
	Application::Application()
		: m_Running(true)
	{
		m_Window = Window::Create(WindowProps());
		
		EventSystem::AttachListener(EventType::WindowClose, std::bind(&Application::OnEvent, this, std::placeholders::_1));
	}

	void Application::OnUpdate()
	{
		EventSystem::ProcessEvents();
	}

	void Application::OnEvent(std::unique_ptr<Event> evt)
	{
		m_Running = false;

		LC_CORE_WARN("Application received exit cmd...");
	}

	void Application::Run()
	{
		//LC_CORE_INFO("Entering update loop");


		while (m_Running)
		{
			Application::OnUpdate();

			m_Window->OnUpdate();
		}
	}
}