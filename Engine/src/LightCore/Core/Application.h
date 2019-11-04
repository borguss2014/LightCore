#pragma once

#include "Core.h"

namespace LightCore 
{

	class LIGHTCORE_API Application
	{
	public: 
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}