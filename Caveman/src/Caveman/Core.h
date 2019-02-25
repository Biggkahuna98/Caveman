#pragma once

#ifdef CM_PLATFORM_WINDOWS
	#ifdef CM_BUILD_DLL
		#define CAVEMAN_API __declspec(dllexport)
	#else
		#define CAVEMAN_API __declspec(dllimport)
	#endif
#else
	#error Caveman is only supported by Windows
#endif