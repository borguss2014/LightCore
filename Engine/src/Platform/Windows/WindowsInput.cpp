#include "WindowsInput.h"

#include <GLFW/glfw3.h>

namespace LightCore
{
	WindowsInput::WindowsInput()
		: m_Keys{0}
	{

	}

	void WindowsInput::PollEvents()
	{
		glfwPollEvents();
	}

	void WindowsInput::SetKeyPressed(int key, bool state)
	{
		m_Keys[key] = state;
	}

	int WindowsInput::GetKeyState(int key) const
	{
		return m_Keys[key];
	}
}