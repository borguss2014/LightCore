#pragma once

#ifdef LC_PLATFORM_WINDOWS
	#if LC_DYNAMIC_LINK
		#ifdef LC_BUILD_DLL
			#define LIGHTCORE_API __declspec(dllexport)
		#else
			#define LIGHTCORE_API __declspec(dllimport)
		#endif
	#else
		#define LIGHTCORE_API
	#endif
#else
	#error Only Windows is supported at this moment!
#endif

#ifdef LC_DEBUG
	#define LC_ENABLE_ASSERTS
#endif

#ifdef LC_ENABLE_ASSERTS
	#define LC_ASSERT(x, ...) { if(!(x)) { LC_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define LC_CORE_ASSERT(x, ...) { if(!(x)) { LC_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define LC_ASSERT(x, ...)
	#define LC_CORE_ASSERT(x, ...)
#endif