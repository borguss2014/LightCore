#include "opengl_context.h"

#include <iostream>

#include <glad/glad.h>
#include <GL/GL.h>

#include <LightCore/Core/Log.h>

namespace LightCore
{
	opengl_context::opengl_context(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		LC_ASSERT(m_WindowHandle != nullptr, "Window pointer is null!");
	}

	void opengl_context::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);

		// Load all OpenGL function pointers
		LC_ASSERT(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress), "Failed to initialize GLAD");

		PrintContextInfo();
	}

	void opengl_context::PrintContextInfo()
	{
		LC_CORE_INFO("Vendor: {}", glGetString(GL_VENDOR));
		LC_CORE_INFO("Renderer: {}", glGetString(GL_RENDERER));
		LC_CORE_INFO("OpenGL version: {}", glGetString(GL_VERSION));
		LC_CORE_INFO("GLSL version {}", glGetString(GL_SHADING_LANGUAGE_VERSION));
		LC_CORE_INFO("========================================");
	}

	void opengl_context::SwapBuffers()
	{
		if (m_WindowHandle != nullptr) {
			glfwSwapBuffers(m_WindowHandle);
		}
	}
}