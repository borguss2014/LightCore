#include "platform_window.h"

#include "Log.h"

/* NOTE(Cristian): Should platform independent code include every neccessary platform,
* or include only the neccessary files? This might result in bigger binaries.
*/
#ifdef LC_PLATFORM_WINDOWS
	#include "Platform/Windows/win32_window.h"
#endif


namespace LightCore
{
	std::unique_ptr<platform_window> platform_window::Create(const platform_window_props& props)
	{
#ifdef LC_PLATFORM_WINDOWS
		return std::make_unique<win32_window>(props);
#else
		LC_CORE_ASSERT(false, "Undefined Platform::Only Windows supported for now");
		return nullptr;
#endif
	}
}