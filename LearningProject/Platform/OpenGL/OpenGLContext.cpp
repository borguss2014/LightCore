#include "OpenGLContext.h"

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>


OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
	: m_WindowHandle(windowHandle)
{
	if (m_WindowHandle == nullptr)
	{
		std::cout << "Window pointer is null!" << std::endl;
	}
}

void OpenGLContext::Init()
{
	// Load all OpenGL function pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return;
	}

	glfwMakeContextCurrent(m_WindowHandle);
}

void OpenGLContext::SwapBuffers()
{
	glfwSwapBuffers(m_WindowHandle);
}
