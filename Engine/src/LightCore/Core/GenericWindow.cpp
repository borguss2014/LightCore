#include "GenericWindow.h"

#include "Platform/Windows/Window.h"

namespace LightCore
{
	std::unique_ptr<GenericWindow> GenericWindow::Create()
	{
		/*TODO(Cristian): Need to identify the current platform based on predefined macros.
		* Application should provide API identification
		*/

		switch (Application::sPlatform) {
		    case Application::Win23:
				return std::make_unique<Win32_Window>(WindowProps());
		    case Application::Linux:
				return std::make_unique<Linux_Window>(WindowProps());
		    default:
				break;
		}

		return 0;
	}
}