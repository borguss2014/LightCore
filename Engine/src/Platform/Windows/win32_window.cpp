#include "win32_window.h"

#include <iostream>

#include "Platform/OpenGL/OpenGLContext.h"

#include <glad/glad.h>
#include <GL/GL.h>

#include <LightCore/Core/Log.h>
#include <LightCore\Events\EventSystem.h>

namespace LightCore
{
	win32_window::win32_window(const platform_window_props& properties)
	{
		wProps = properties;

		int success = glfwInit();

		LC_ASSERT(success, "Failed to initialize GLFW");

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_Monitor = glfwGetPrimaryMonitor();

		GLFWmonitor* monitor = nullptr;

		if (wProps.fullscreen)
		{
			monitor = m_Monitor;
		}

		m_Window = glfwCreateWindow(wProps.width, wProps.height, wProps.title.c_str(), monitor, nullptr);

		LC_ASSERT(m_Window != nullptr, "Failed to create GLFW window");

		m_Context = std::make_unique<OpenGLContext>(m_Window);
		m_Context->Init();

		glfwSetWindowUserPointer(m_Window, this);

		SetVSync(wProps.vsync);

		glfwSetFramebufferSizeCallback(m_Window, Framebuffer_Size_Callback);
		glfwSetKeyCallback(m_Window, Key_Callback);
		glfwSetWindowCloseCallback(m_Window, Window_Close_Callback);

		if (wProps.fullscreen)
		{
			SetFullScreen();
		}

		CenterWindow();

		//SetInputMode(GLFW_CURSOR_DISABLED);

		std::string s("Window initialized");
		LC_CORE_INFO(s);

		EventSystem::AttachListener(EventType::KeyPressed, std::bind(&win32_window::OnKeyEvent, this, std::placeholders::_1));
	}

	win32_window::~win32_window()
	{
		glfwTerminate();
	}

	GLFWmonitor** win32_window::GetAvailableMonitors(int32_t* count) const
	{
		return glfwGetMonitors(count);
	}

	GLFWmonitor* win32_window::GetMonitor() const
	{
		return m_Monitor;
	}

	bool win32_window::GetWindowShouldClose() const
	{
		return glfwWindowShouldClose(m_Window);
	}

	void win32_window::SetFullScreen()
	{
		glfwSetWindowMonitor(m_Window, m_Monitor, 0, 0, wProps.width, wProps.height, 60);
	}

	void win32_window::SetMonitor(GLFWmonitor* monitor)
	{
		m_Monitor = monitor;

		glfwSetWindowMonitor(m_Window, monitor, 0, 0, wProps.width, wProps.height, 60);
	}

	void win32_window::SetInputMode(int mode)
	{
		glfwSetInputMode(m_Window, GLFW_CURSOR, mode);
	}

	void win32_window::CenterWindow()
	{
		if (wProps.fullscreen)
		{
			LC_WARN("Warning: cannot center a fullscreen window!");
			return;
		}

		const GLFWvidmode* mode = glfwGetVideoMode(m_Monitor);

		uint32_t monitorWidth = mode->width;
		uint32_t monitorHeight = mode->height;

		uint32_t winX = (monitorWidth / 2) - (wProps.width / 2);
		uint32_t winY = (monitorHeight / 2) - (wProps.height / 2);

		glfwSetWindowMonitor(m_Window, nullptr, winX, winY, wProps.width, wProps.height, 60);
	}

	void win32_window::OnUpdate()
	{
		glfwPollEvents();
		m_Context->SwapBuffers();
	}

	void win32_window::SetEventCallback(std::function<void(Event& e)> fn)
	{
		LC_TRACE("EVENT SET");
	}

	std::string win32_window::GetMonitorName(GLFWmonitor* monitor) const
	{
		return glfwGetMonitorName(monitor);
	}

	void win32_window::SetVSync(bool enabled)
	{
		glfwSwapInterval(enabled);

		wProps.vsync = enabled;
	}

	// Glfw: whenever the window size changed (by OS or user resize) this callback function executes
	void win32_window::Framebuffer_Size_Callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	void win32_window::Key_Callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window, true);

			LC_CORE_WARN("Window set to close");

			std::unique_ptr<WindowEvt> windowCloseEvt = std::make_unique<WindowEvt>(EventType::WindowClose);
			EventSystem::QueueEvent(std::move(windowCloseEvt));
		}
	}

	void win32_window::Window_Close_Callback(GLFWwindow* window)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);

		std::unique_ptr<WindowEvt> windowCloseEvt = std::make_unique<WindowEvt>(EventType::WindowClose);
		EventSystem::QueueEvent(std::move(windowCloseEvt));
	}

	void win32_window::OnKeyEvent(std::unique_ptr<Event> evt)
	{
		// Get data packed by evt
		//
		// if key == ESC
		// close window
	}
}