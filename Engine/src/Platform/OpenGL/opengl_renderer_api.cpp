#include "opengl_renderer_api.h"

namespace LightCore
{
	void opengl_renderer_api::SetViewport(GLuint x, GLuint y, GLuint width, GLuint height)
	{
		glViewport(x, y, width, height);
	}

	void opengl_renderer_api::SetClearColor(const glm::vec4& color)
	{
		glClearColor(color.x, color.y, color.z, color.a);
	}
	void opengl_renderer_api::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}
}