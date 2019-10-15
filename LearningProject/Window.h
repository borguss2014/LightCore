#pragma once

#include <cstdint>
#include <string>

#include <GLFW/glfw3.h>

struct WindowProps
{
	uint32_t	width;
	uint32_t	height;
	std::string title;
	bool		fullscreen;
};

class Window
{

public:
	Window(const WindowProps& properties);

	void InitAPIContext();
	void CreateWindow();

	GLFWmonitor** GetAvailableMonitors(int32_t* count) const;

	GLFWwindow* GetWindow() const;

	void SetFullScreen();

	void SetMonitor(GLFWmonitor* monitor);

	void CenterWindow();

	~Window();
private:
	WindowProps		m_Properties;
	GLFWwindow*		m_Window;

	GLFWmonitor*	m_Monitor;
};

