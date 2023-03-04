#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Cyan {

	class CYAN_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:

		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define CY_CORE_TRACE(...)	::Cyan::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CY_CORE_INFO(...)	::Cyan::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CY_CORE_WARN(...)	::Cyan::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CY_CORE_ERROR(...)	::Cyan::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CY_CORE_FATAL(...)	::Cyan::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define CY_TRACE(...)	::Cyan::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CY_INFO(...)	::Cyan::Log::GetClientLogger()->info(__VA_ARGS__)
#define CY_WARN(...)	::Cyan::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CY_ERROR(...)	::Cyan::Log::GetClientLogger()->error(__VA_ARGS__)
#define CY_FATAL(...)	::Cyan::Log::GetClientLogger()->fatal(__VA_ARGS__)
