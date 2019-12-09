#include "Application.h"

#include "LightCore/Core/Log.h"

#include "Platform/Windows/Window.h"

namespace LightCore 
{
	Application::Application()
		: m_Running(true)
	{
		m_Window = Window::Create(WindowProps());
		//m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
	}

	void Application::OnUpdate()
	{

	}

	void Application::Run()
	{
		LC_CORE_INFO("Entering update loop");

		while (m_Running)
		{
			OnUpdate();

			m_Window->OnUpdate();
		}
	}
}