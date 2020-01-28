#pragma once

#include "LightCore/Renderer/graphics_context.h"

namespace LightCore
{
	

	struct opengl_context : public graphics_context
	{
		opengl_context(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;
		virtual void PrintContextInfo() override;

		GLFWwindow* m_WindowHandle;
	};
}