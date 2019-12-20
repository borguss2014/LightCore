#pragma once

#include "LightCore/Renderer/GraphicsContext.h"

struct GLFWwindow;

struct OpenGLContext : public GraphicsContext
{
public:
	OpenGLContext(GLFWwindow* windowHandle);

	virtual void Init() override;
	virtual void SwapBuffers() override;
	virtual void PrintContextInfo() override;
private:
	GLFWwindow* m_WindowHandle;
};