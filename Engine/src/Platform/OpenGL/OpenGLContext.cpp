#include "OpenGLContext.h"

#include <iostream>

#include <GLFW/glfw3.h>

#include <glad/glad.h>
#include <GL/GL.h>

#include <LightCore/Core/Log.h>


OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
	: m_WindowHandle(windowHandle)
{
		LC_ASSERT(m_WindowHandle != nullptr, "Window pointer is null!");
}

void OpenGLContext::Init()
{
	glfwMakeContextCurrent(m_WindowHandle);

	// Load all OpenGL function pointers
	LC_ASSERT(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress), "Failed to initialize GLAD");

	PrintContextInfo();
}

void OpenGLContext::PrintContextInfo()
{
	LC_CORE_INFO("Vendor: {}", glGetString(GL_VENDOR));
	LC_CORE_INFO("Renderer: {}", glGetString(GL_RENDERER));
	LC_CORE_INFO("OpenGL version: {}", glGetString(GL_VERSION));
	LC_CORE_INFO("GLSL version {}", glGetString(GL_SHADING_LANGUAGE_VERSION));
	LC_CORE_INFO("========================================");
}

void OpenGLContext::SwapBuffers()
{
	glfwSwapBuffers(m_WindowHandle);
}
