#pragma once

#ifdef LC_PLATFORM_WINDOWS

extern LightCore::platform_application* LightCore::CreateApplication();

int main(int argc, char** argv)
{
	LightCore::platform_log::Init();

	auto app = LightCore::CreateApplication();
	app->Run();

	delete app;

	return 0;
}

#endif