#pragma once

#include "LightCore/Renderer/renderer_api.h"

namespace LightCore
{
	struct opengl_renderer_api : renderer_api
	{
		void SetViewport(GLuint x, GLuint y, GLuint width, GLuint height) override;
		void SetClearColor(const glm::vec4& color) override;
		void Clear() override;
	};
}