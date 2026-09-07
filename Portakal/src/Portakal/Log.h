#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Portakal {
	class PRTKL_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private: 
		static std :: shared_ptr<spdlog::logger> s_CoreLogger;
		static std :: shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

//core log macro
#define PRTKL_CORE_TRACE(...)::Portakal::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PRTKL_CORE_INFO(...) ::Portakal::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PRTKL_CORE_WARN(...) ::Portakal::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PRTKL_CORE_ERROR(...)::Portakal::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PRTKL_CORE_FATAL(...)::Portakal::Log::GetCoreLogger()->fatal(__VA_ARGS__)
//clinet log macro
#define PRTKL_TRACE(...)::Portakal::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PRTKL_INFO(...) ::Portakal::Log::GetClientLogger()->info(__VA_ARGS__)
#define PRTKL_WARN(...) ::Portakal::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PRTKL_ERROR(...)::Portakal::Log::GetClientLogger()->error(__VA_ARGS__)
#define PRTKL_FATAL(...)::Portakal::Log::GetClientLogger()->fatal(__VA_ARGS__)

