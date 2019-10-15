#include "Window.h"

#include <iostream>


Window::Window(const WindowProps& properties)
{
	m_Properties = properties;

	InitAPIContext();

	m_Monitor = glfwGetPrimaryMonitor();
}

void Window::InitAPIContext()
{
	bool success = glfwInit();

	if (!success)
	{
		std::cout << "Failed to initialize GLFW!" << std::endl;
		return;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Fix compilation on OS X
	#endif
}

void Window::CreateWindow()
{
	m_Window = glfwCreateWindow(m_Properties.width, m_Properties.height, m_Properties.title.c_str(), nullptr, nullptr);

	if (m_Window == nullptr)
	{
		std::cout << "Failed to create GLFW window!" << std::endl;
		return;
	}

	glfwMakeContextCurrent(m_Window);

	if (m_Properties.fullscreen)
	{
		SetFullScreen();
	}
}

GLFWmonitor** Window::GetAvailableMonitors(int32_t* count) const
{
	return glfwGetMonitors(count);
}

void Window::SetFullScreen()
{
	glfwSetWindowMonitor(m_Window, m_Monitor, 0, 0, m_Properties.width, m_Properties.height, 60);
}

void Window::SetMonitor(GLFWmonitor* monitor)
{
	m_Monitor = monitor;

	glfwSetWindowMonitor(m_Window, monitor, 0, 0, m_Properties.width, m_Properties.height, 60);
}

void Window::CenterWindow()
{
	const GLFWvidmode* mode = glfwGetVideoMode(m_Monitor);

	uint32_t monitorWidth = mode->width;
	uint32_t monitorHeight = mode->height;

	uint32_t winX = (monitorWidth / 2) - (m_Properties.width / 2);
	uint32_t winY = (monitorHeight / 2) - (m_Properties.height / 2);

	glfwSetWindowMonitor(m_Window, nullptr, winX, winY, m_Properties.width, m_Properties.height, 60);
}

GLFWwindow* Window::GetWindow() const
{
	return m_Window;
}

Window::~Window()
{
	glfwTerminate();
}