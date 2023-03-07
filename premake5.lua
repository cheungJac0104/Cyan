workspace "Cyan"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

 outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Cyan"
	location "Cyan"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines
		{
			"CY_PLATFORM_WINDOWS",
			"CY_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "CY_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CY_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CY_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Cyan/vendor/spdlog/include",
		"Cyan/src"
	}

	links
	{
		"Cyan"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines
		{
			"CY_PLATFORM_WINDOWS"
		}


	filter "configurations:Debug"
		defines "CY_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CY_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CY_DIST"
		optimize "On"