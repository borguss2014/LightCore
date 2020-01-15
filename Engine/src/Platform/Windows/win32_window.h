#pragma once

#include <memory>
#include <cstdint>
#include <string>
#include <functional>

#include "LightCore/Core/platform_window.h"

#include "LightCore/Renderer/GraphicsContext.h"

#include <GLFW/glfw3.h>

#include <LightCore\Events\Event.h>

namespace LightCore
{
	struct platform_window_props
	{
		std::string		title;
		unsigned int	width;
		unsigned int	height;
		bool			fullscreen;
		bool			vsync;
	};

	struct win32_window : public platform_window
	{
		win32_window(const platform_window_props& properties);
		~win32_window();

		GLFWmonitor** GetAvailableMonitors(int32_t* count) const;
		GLFWmonitor* GetMonitor() const;

		inline void* GetNativeWindow() const override { return m_Window; };

		bool GetWindowShouldClose() const;

		inline unsigned int GetWidth() const override { return wProps.width; };
		inline unsigned int GetHeight() const override { return wProps.height; };

		void SetVSync(bool enabled) override;
		inline bool IsVSync() const override { return wProps.vsync; };

		void SetFullScreen();
		void SetMonitor(GLFWmonitor* monitor);

		// TODO(Cristian): Move to Mouse input class
		void SetInputMode(int mode);

		std::string GetMonitorName(GLFWmonitor* monitor) const;

		void CenterWindow();

		void OnUpdate() override;

		void SetEventCallback(std::function<void(Event& e)> fn) override;

		void OnKeyEvent(std::unique_ptr<Event> evt);

		platform_window_props	wProps;
		GLFWwindow*		m_Window;

		GLFWmonitor*	m_Monitor;

		std::unique_ptr<GraphicsContext> m_Context;

		static void Framebuffer_Size_Callback(GLFWwindow* window, int width, int height);
		static void Key_Callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void Window_Close_Callback(GLFWwindow* window);
	};
}