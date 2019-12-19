#pragma once

#include <memory>
#include <cstdint>
#include <string>
#include <functional>

#include "LightCore/Core/GenericWindow.h"

#include "LightCore/Renderer/GraphicsContext.h"

#include <GLFW/glfw3.h>

#include <LightCore\Events\Event.h>

namespace LightCore
{
	struct WindowProps 
	{
		std::string		Title;
		unsigned int	Width;
		unsigned int	Height;

		bool			Fullscreen;
		bool			Vsync;

		WindowProps(const std::string& title = "LightCore Engine",
			unsigned int width = 1920,
			unsigned int height = 1080,
			bool fullscreen = false,
			bool vsync = false)
			: Title(title), Width(width), Height(height),
				Fullscreen(fullscreen), Vsync(vsync)
		{
		}
	};

	class Window : public GenericWindow
	{

	public:
		Window(const WindowProps& properties);
		~Window();

		GLFWmonitor** GetAvailableMonitors(int32_t* count) const;
		GLFWmonitor* GetMonitor() const;

		inline void* GetNativeWindow() const override { return m_Window; };

		bool GetWindowShouldClose() const;

		inline unsigned int GetWidth() const override { return m_Properties.Width; };
		inline unsigned int GetHeight() const override { return m_Properties.Height; };

		void SetVSync(bool enabled) override;
		inline bool IsVSync() const override { return m_Properties.Vsync; };

		void SetFullScreen();
		void SetMonitor(GLFWmonitor* monitor);

		// TODO: Move to Mouse input class
		void SetInputMode(int mode);

		std::string GetMonitorName(GLFWmonitor* monitor) const;

		void CenterWindow();

		void OnUpdate() override;

		void SetEventCallback(std::function<void(Event& e)> fn) override;

		void OnEvent(std::unique_ptr<Event> evt);

	private:
		WindowProps		m_Properties;
		GLFWwindow* m_Window;

		GLFWmonitor* m_Monitor;

		std::unique_ptr<GraphicsContext> m_Context;

	public:
		static std::unique_ptr<Window> Create(const WindowProps& props);

	private:
		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	};
}