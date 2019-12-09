workspace "LightCore"
	architecture "x64"
	startproject "Sandbox"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

    flags {
        "MultiProcessorCompile"
    }

output_dir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Engine/vendor/GLFW/include"
IncludeDir["Glad"] = "Engine/vendor/Glad/include"
IncludeDir["glm"] = "Engine/vendor/glm"
IncludeDir["stb_image"] = "Engine/vendor/stb_image"

group "Dependencies"
    include "Engine/vendor/GLFW"
    include "Engine/vendor/Glad"
group ""

project "Engine"
	kind "StaticLib"
	location "Engine"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. output_dir .. "/%{prj.name}")
	objdir ("bin-int/" .. output_dir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.h",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}"
	}

	links {
        "GLFW",
        "Glad",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines {
			"LC_PLATFORM_WINDOWS",
			"LC_BUILD_DLL" ,
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "LC_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "LC_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "LC_DIST"
		runtime "Release"
		optimize "on"


project "Sandbox"
	kind "ConsoleApp"
	location "Sandbox"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. output_dir .. "/%{prj.name}")
	objdir ("bin-int/" .. output_dir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.h"
	}

	includedirs {
		"Engine/src",
		"Engine/vendor",
		"Engine/vendor/spdlog/include",
		"%{IncludeDir.glm}"
	}

	links {
		"Engine"
	}

	filter "system:windows"
		systemversion "latest"

		defines {
			"LC_PLATFORM_WINDOWS"
		}

		filter "configurations:Debug"
		defines "LC_DEBUG"
		runtime "Debug"
		symbols "on"

		filter "configurations:Release"
		defines "LC_RELEASE"
		runtime "Release"
		optimize "on"

		filter "configurations:Dist"
		defines "LC_DIST"
		runtime "Release"
		optimize "on"