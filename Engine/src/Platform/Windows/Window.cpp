#include "Window.h"

#include <iostream>

#include "Platform/OpenGL/OpenGLContext.h"

#include <glad/glad.h>
#include <GL/GL.h>

#include <LightCore/Core/Log.h>

namespace LightCore
{
	Window::Window(const WindowProps& properties)
	{
		m_Properties = properties;

		int success = glfwInit();

		LC_ASSERT(success, "Failed to initialize GLFW");

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_Monitor = glfwGetPrimaryMonitor();

		GLFWmonitor* monitor = nullptr;

		if (m_Properties.Fullscreen)
		{
			monitor = m_Monitor;
		}

		m_Window = glfwCreateWindow(m_Properties.Width, m_Properties.Height, m_Properties.Title.c_str(), monitor, nullptr);

		LC_ASSERT(m_Window != nullptr, "Failed to create GLFW window");

		m_Context = std::make_unique<OpenGLContext>(m_Window);
		m_Context->Init();

		glfwSetWindowUserPointer(m_Window, this);

		SetVSync(m_Properties.Vsync);

		glfwSetFramebufferSizeCallback(m_Window, framebuffer_size_callback);

		glfwSetKeyCallback(m_Window, key_callback);

		if (m_Properties.Fullscreen)
		{
			SetFullScreen();
		}

		CenterWindow();

		//SetInputMode(GLFW_CURSOR_DISABLED);

		std::string s("Window created");
		LC_CORE_INFO(s);
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	GLFWmonitor** Window::GetAvailableMonitors(int32_t* count) const
	{
		return glfwGetMonitors(count);
	}

	GLFWmonitor* Window::GetMonitor() const
	{
		return m_Monitor;
	}

	bool Window::GetWindowShouldClose() const
	{
		return glfwWindowShouldClose(m_Window);
	}

	void Window::SetFullScreen()
	{
		glfwSetWindowMonitor(m_Window, m_Monitor, 0, 0, m_Properties.Width, m_Properties.Height, 60);
	}

	void Window::SetMonitor(GLFWmonitor* monitor)
	{
		m_Monitor = monitor;

		glfwSetWindowMonitor(m_Window, monitor, 0, 0, m_Properties.Width, m_Properties.Height, 60);
	}

	void Window::SetInputMode(int mode)
	{
		glfwSetInputMode(m_Window, GLFW_CURSOR, mode);
	}

	void Window::CenterWindow()
	{
		if (m_Properties.Fullscreen)
		{
			LC_WARN("Warning: cannot center a fullscreen window!");
			return;
		}

		const GLFWvidmode* mode = glfwGetVideoMode(m_Monitor);

		uint32_t monitorWidth = mode->width;
		uint32_t monitorHeight = mode->height;

		uint32_t winX = (monitorWidth / 2) - (m_Properties.Width / 2);
		uint32_t winY = (monitorHeight / 2) - (m_Properties.Height / 2);

		glfwSetWindowMonitor(m_Window, nullptr, winX, winY, m_Properties.Width, m_Properties.Height, 60);
	}

	void Window::OnUpdate()
	{
		glfwPollEvents();
		m_Context->SwapBuffers();
	}

	void Window::SetEventCallback(std::function<void(Event& e)> fn)
	{
		LC_TRACE("EVENT SET");
	}

	std::string Window::GetMonitorName(GLFWmonitor* monitor) const
	{
		return glfwGetMonitorName(monitor);
	}

	void Window::SetVSync(bool enabled)
	{
		glfwSwapInterval(enabled);

		m_Properties.Vsync = enabled;
	}

	// Glfw: whenever the window size changed (by OS or user resize) this callback function executes
	void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		{
			std::cout << "Pressed ESC... EXITING" << std::endl;
			glfwSetWindowShouldClose(window, true);
		}
	}
	std::unique_ptr<Window> Window::Create(const WindowProps& props)
	{
		return std::make_unique<Window>(props);
	}
}