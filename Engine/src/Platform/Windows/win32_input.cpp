#include "win32_input.h"

#include <GLFW/glfw3.h>

namespace LightCore
{
	win32_input::win32_input()
		: m_Keys{0}
	{

	}

	void win32_input::PollEvents()
	{
		glfwPollEvents();
	}

	void win32_input::SetKeyPressed(int key, bool state)
	{
		m_Keys[key] = state;
	}

	int win32_input::GetKeyState(int key) const
	{
		return m_Keys[key];
	}
}