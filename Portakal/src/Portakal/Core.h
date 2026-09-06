#pragma once


#ifdef PRTKL_PLATFORM_WINDOWS
	#ifdef PRTKL_BUILD_DLL
		#define PRTKL_API __declspec(dllexport)
	#else 
		#define PRTKL_API __declspec(dllimport)
	#endif // PRTKL_BUILD_DLL	

#else 
#error Portakal Engine only support windows :D

#endif  PRTKL_PLATFORM_WINDOWS
