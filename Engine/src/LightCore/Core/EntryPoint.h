#pragma once

#ifdef LC_PLATFORM_WINDOWS

extern LightCore::Application* LightCore::CreateApplication();

int main(int argc, char** argv)
{
	auto app = LightCore::CreateApplication();
	app->Run();

	delete app;
}

#endif