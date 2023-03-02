#pragma once

#ifdef CY_PLATFORM_WINDOWS
	#ifdef CY_BUILD_DLL
		#define CYAN_API __declspec(dllexport)
	#else
		#define CYAN_API __declspec(dllimport)
	#endif
#else
	#error Cyan only support Windows!
#endif
