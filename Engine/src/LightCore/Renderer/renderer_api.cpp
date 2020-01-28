#include "renderer_api.h"

#include <Platform/OpenGL/opengl_renderer_api.h>

namespace LightCore
{
	renderer_api::API renderer_api::s_API = renderer_api::API::OpenGL;

	std::unique_ptr<renderer_api> renderer_api::Create()
	{
		switch (s_API)
		{
			case API::OpenGL:
				return std::make_unique<opengl_renderer_api>();
			case API::None:
				return nullptr;
		}
	}
}