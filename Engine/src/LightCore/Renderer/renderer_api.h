#pragma once

#include <memory>
#include <glm/glm.hpp>

#include <glad/glad.h>
#include <gl/GL.h>

namespace LightCore
{
	struct __declspec(novtable) renderer_api
	{
		enum struct API
		{
			None = 0,
			OpenGL
		};

		virtual void SetViewport(GLuint x, GLuint y, GLuint width, GLuint height) = 0;
		virtual void SetClearColor(const glm::vec4& color) = 0;
		virtual void Clear() = 0;

		static std::unique_ptr<renderer_api> Create();

		static API s_API;
	};
}