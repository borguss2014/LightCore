#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace LightCore
{
	struct Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger> GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger> GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define LC_CORE_TRACE(...)	::LightCore::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LC_CORE_INFO(...)	::LightCore::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LC_CORE_WARN(...)	::LightCore::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LC_CORE_ERROR(...)	::LightCore::Log::GetCoreLogger()->error(__VA_ARGS__)

#define LC_TRACE(...)	::LightCore::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LC_INFO(...)	::LightCore::Log::GetClientLogger()->info(__VA_ARGS__)
#define LC_WARN(...)	::LightCore::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LC_ERROR(...)	::LightCore::Log::GetClientLogger()->error(__VA_ARGS__)