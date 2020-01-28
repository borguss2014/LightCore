#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace LightCore
{
	std::shared_ptr<spdlog::logger> platform_log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> platform_log::s_ClientLogger;

	void platform_log::Init()
	{
		s_CoreLogger = spdlog::stdout_color_mt("LightCore");
		s_CoreLogger->set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("Client");
		s_ClientLogger->set_pattern("%^[%T] %n: %v%$");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}