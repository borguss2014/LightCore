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

	void initAPIContext();
	void createWindow();

	GLFWwindow* getWindow() const;

	~Window();
private:
	WindowProps m_Properties;
	GLFWwindow* m_Window;
};

