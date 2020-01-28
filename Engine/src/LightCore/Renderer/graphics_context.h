#pragma once

#include <memory>

#include <GLFW/glfw3.h>

namespace LightCore
{
	struct __declspec(novtable) graphics_context
	{
		virtual ~graphics_context() = default;

		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;
		virtual void PrintContextInfo() = 0;

		static std::unique_ptr<graphics_context> Create(GLFWwindow* windowHandle);
	};
}