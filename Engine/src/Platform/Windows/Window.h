#pragma once

#include <memory>

#include <cstdint>
#include <string>

#include <glfw/include/GLFW/glfw3.h>

#include <functional>


#include "../../Platform/OpenGL/OpenGLContext.h"


struct WindowProps
{
	uint32_t	width;
	uint32_t	height;
	std::string title;
	bool		fullscreen;
	bool		vsync;
	bool		center;
};

class Window
{

public:
	Window(const WindowProps& properties);

	void CreateWindow();

	GLFWmonitor** GetAvailableMonitors(int32_t* count) const;
	GLFWmonitor* GetMonitor() const;
	GLFWwindow* GetWindow() const;

	bool IsVSync() const;

	void SetVSync(bool state);
	void SetFullScreen();
	void SetMonitor(GLFWmonitor* monitor);

	// TODO: Move to Mouse input class
	void SetInputMode(int mode);

	std::string GetMonitorName(GLFWmonitor* monitor) const;

	void CenterWindow();

	void OnUpdate();

	~Window();

private: 
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

private:
	WindowProps		m_Properties;
	GLFWwindow*		m_Window;

	GLFWmonitor*	m_Monitor;

	std::unique_ptr<GraphicsContext> m_Context;
};