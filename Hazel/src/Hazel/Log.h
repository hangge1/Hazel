#pragma once

//#define SPDLOG_FMT_PRINTF

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Hazel {

	class HAZEL_API Log
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

//Core log macros
#define HZ_CORE_TRACE(...) ::Hazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_INFO(...)  ::Hazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...)  ::Hazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...) ::Hazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_FATAL(...) ::Hazel::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define HZ_TRACE(...) ::Hazel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HZ_INFO(...)  ::Hazel::Log::GetClientLogger()->info(__VA_ARGS__)
#define HZ_WARN(...)  ::Hazel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HZ_ERROR(...) ::Hazel::Log::GetClientLogger()->error(__VA_ARGS__)
#define HZ_FATAL(...) ::Hazel::Log::GetClientLogger()->fatal(__VA_ARGS__)


//Log Obj
#define HZ_CORE_OBJ_TRACE(obj) ::Hazel::Log::GetCoreLogger()->trace("{0}",obj)
#define HZ_CORE_OBJ_INFO(obj)  ::Hazel::Log::GetCoreLogger()->info("{0}",obj)
#define HZ_CORE_OBJ_WARN(obj)  ::Hazel::Log::GetCoreLogger()->warn("{0}",obj)
#define HZ_CORE_OBJ_ERROR(obj) ::Hazel::Log::GetCoreLogger()->error("{0}",obj)
#define HZ_CORE_OBJ_FATAL(obj) ::Hazel::Log::GetCoreLogger()->fatal("{0}",obj)

#define HZ_OBJ_TRACE(obj) ::Hazel::Log::GetClientLogger()->trace("{0}",obj)
#define HZ_OBJ_INFO(obj)  ::Hazel::Log::GetClientLogger()->info("{0}",obj)
#define HZ_OBJ_WARN(obj)  ::Hazel::Log::GetClientLogger()->warn("{0}",obj)
#define HZ_OBJ_ERROR(obj) ::Hazel::Log::GetClientLogger()->error("{0}",obj)
#define HZ_OBJ_FATAL(obj) ::Hazel::Log::GetClientLogger()->fatal("{0}",obj)

// if dist build
