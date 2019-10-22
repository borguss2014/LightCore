#pragma once

#include <cstdint>
#include <string>

#include <GLFW/glfw3.h>
#include <functional>

struct WindowProps
{
	uint32_t	width;
	uint32_t	height;
	std::string title;
	bool		fullscreen;
	bool		vsync;
};

class Window
{

public:
	Window(const WindowProps& properties);

	void InitAPIContext();
	void CreateWindow();

	GLFWmonitor** GetAvailableMonitors(int32_t* count) const;

	GLFWmonitor* GetMonitor() const;

	GLFWwindow* GetWindow() const;

	bool IsVSync() const;

	void SetVSync(bool state);

	void SetFullScreen();

	void SetMonitor(GLFWmonitor* monitor);

	std::string GetMonitorName(GLFWmonitor* monitor) const;

	void CenterWindow();

	~Window();

private: 
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

private:
	WindowProps		m_Properties;
	GLFWwindow*		m_Window;

	GLFWmonitor*	m_Monitor;
};