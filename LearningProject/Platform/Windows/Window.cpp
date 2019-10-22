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
	if (!glfwInit())
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
	GLFWmonitor* monitor = nullptr;

	if (m_Properties.fullscreen)
	{
		monitor = m_Monitor;
	}

	m_Window = glfwCreateWindow(m_Properties.width, m_Properties.height, m_Properties.title.c_str(), monitor, nullptr);

	if (m_Window == nullptr)
	{
		std::cout << "Failed to create GLFW window!" << std::endl;
		return;
	}

	SetVSync(m_Properties.vsync);

	glfwSetWindowUserPointer(m_Window, this);

	glfwSetFramebufferSizeCallback(m_Window, framebuffer_size_callback);

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

GLFWmonitor* Window::GetMonitor() const
{
	return m_Monitor;
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
	if (m_Properties.fullscreen)
	{
		std::cout << "Warning: cannot center a fullscreen window!" << std::endl;
		return;
	}

	const GLFWvidmode* mode = glfwGetVideoMode(m_Monitor);

	uint32_t monitorWidth = mode->width;
	uint32_t monitorHeight = mode->height;

	uint32_t winX = (monitorWidth / 2) - (m_Properties.width / 2);
	uint32_t winY = (monitorHeight / 2) - (m_Properties.height / 2);

	glfwSetWindowMonitor(m_Window, nullptr, winX, winY, m_Properties.width, m_Properties.height, 60);
}

std::string Window::GetMonitorName(GLFWmonitor* monitor) const
{
	return glfwGetMonitorName(monitor);
}

GLFWwindow* Window::GetWindow() const
{
	return m_Window;
}

bool Window::IsVSync() const
{
	return m_Properties.vsync;
}

void Window::SetVSync(bool state)
{
	glfwSwapInterval(state);

	m_Properties.vsync = state;
}

Window::~Window()
{
	glfwTerminate();
}

// Glfw: whenever the window size changed (by OS or user resize) this callback function executes
void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
