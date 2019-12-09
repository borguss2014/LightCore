#include "WindowsInput.h"

#include <GLFW/glfw3.h>

namespace LightCore
{
	WindowsInput::WindowsInput()
		: m_Keys{ 0 }
	{

	}

	void WindowsInput::PollEvents()
	{
		glfwPollEvents();
	}

	void WindowsInput::SetKeyPressed(int key)
	{
		m_Keys[key] = true;
	}

	void WindowsInput::SetKeyReleased(int key)
	{
		m_Keys[key] = false;
	}

	int WindowsInput::GetKeyState(int key) const
	{
		return m_Keys[key];
	}

	void WindowsInput::DispatchEvents()
	{
	}
}