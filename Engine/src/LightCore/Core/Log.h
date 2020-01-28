#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

/* TODO(Cristian): This log system doesn't seem extensible.
*  Won't be able to change log library during development
*/

namespace LightCore
{
	struct platform_log
	{
		static void Init();

		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define LC_CORE_TRACE(...)	::LightCore::platform_log::s_CoreLogger->trace(__VA_ARGS__)
#define LC_CORE_INFO(...)	::LightCore::platform_log::s_CoreLogger->info(__VA_ARGS__)
#define LC_CORE_WARN(...)	::LightCore::platform_log::s_CoreLogger->warn(__VA_ARGS__)
#define LC_CORE_ERROR(...)	::LightCore::platform_log::s_CoreLogger->error(__VA_ARGS__)

#define LC_TRACE(...)	::LightCore::platform_log::s_ClientLogger->trace(__VA_ARGS__)
#define LC_INFO(...)	::LightCore::platform_log::s_ClientLogger->info(__VA_ARGS__)
#define LC_WARN(...)	::LightCore::platform_log::s_ClientLogger->warn(__VA_ARGS__)
#define LC_ERROR(...)	::LightCore::platform_log::s_ClientLogger->error(__VA_ARGS__)