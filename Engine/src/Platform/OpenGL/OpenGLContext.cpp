#include "OpenGLContext.h"

#include <iostream>

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>


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
	glfwMakeContextCurrent(m_WindowHandle);

	// Load all OpenGL function pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return;
	}
}

void OpenGLContext::SwapBuffers()
{
	glfwSwapBuffers(m_WindowHandle);
}
