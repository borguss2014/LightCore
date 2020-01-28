#include "LightCore/Renderer/graphics_context.h"

#include "LightCore/Renderer/renderer_api.h"
#include <LightCore\Core\Log.h>

#include "Platform/OpenGL/opengl_context.h"

namespace LightCore
{
	std::unique_ptr<graphics_context> graphics_context::Create(GLFWwindow* windowHandle)
	{
		switch (renderer_api::s_API)
		{
			case renderer_api::API::OpenGL:
				return std::make_unique<opengl_context>(windowHandle);
			case renderer_api::API::None:
				LC_CORE_ASSERT(false, "Renderer::No rendering API ");
				return nullptr;
		}

		return nullptr;
	}
}