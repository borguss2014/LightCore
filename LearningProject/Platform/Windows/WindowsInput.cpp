#include "WindowsInput.h"

#include <GLFW/glfw3.h>

WindowsInput::WindowsInput()
	: m_Keys{0}
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


void WindowsInput::SetKeyStatus()
{
}

void WindowsInput::DispatchEvents()
{
}
