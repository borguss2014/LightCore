#pragma once

#ifdef LC_PLATFORM_WINDOWS

	#ifdef LC_BUILD_DLL
		#define LIGHTCORE_API __declspec(dllexport)
	#else
		#define	LIGHTCORE_API __declspec(dllimport)
	#endif
#else
	#error Only Windows is supported at this moment!
#endif