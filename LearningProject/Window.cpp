#include "Window.h"

#include <iostream>


Window::Window(const WindowProps& properties)
{
	m_Properties = properties;

	initAPIContext();
}

void Window::initAPIContext()
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

void Window::createWindow()
{
	m_Window = glfwCreateWindow(m_Properties.width, m_Properties.height, m_Properties.title.c_str(), nullptr, nullptr);

	if (m_Window == nullptr)
	{
		std::cout << "Failed to create GLFW window!" << std::endl;
		return;
	}

	glfwMakeContextCurrent(m_Window);
}

GLFWwindow* Window::getWindow() const
{
	return m_Window;
}

Window::~Window()
{
	glfwTerminate();
}