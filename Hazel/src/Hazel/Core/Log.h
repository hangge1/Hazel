#pragma once

#include "Hazel/Core/Base.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Hazel {

	class Log
	{
	public:
		static void Init();

		inline static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};

}

//Core log macros
#define HZ_CORE_TRACE(...) ::Hazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_INFO(...)  ::Hazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...)  ::Hazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...) ::Hazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_CRITICAL(...) ::Hazel::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Client log macros
#define HZ_TRACE(...) ::Hazel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HZ_INFO(...)  ::Hazel::Log::GetClientLogger()->info(__VA_ARGS__)
#define HZ_WARN(...)  ::Hazel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HZ_ERROR(...) ::Hazel::Log::GetClientLogger()->error(__VA_ARGS__)
#define HZ_CRITICAL(...) ::Hazel::Log::GetClientLogger()->critical(__VA_ARGS__)


//Log Obj
#define HZ_CORE_OBJ_TRACE(obj) ::Hazel::Log::GetCoreLogger()->trace("{0}",obj)
#define HZ_CORE_OBJ_INFO(obj)  ::Hazel::Log::GetCoreLogger()->info("{0}",obj)
#define HZ_CORE_OBJ_WARN(obj)  ::Hazel::Log::GetCoreLogger()->warn("{0}",obj)
#define HZ_CORE_OBJ_ERROR(obj) ::Hazel::Log::GetCoreLogger()->error("{0}",obj)
#define HZ_CORE_OBJ_CRITICAL(obj) ::Hazel::Log::GetCoreLogger()->critical("{0}",obj)

#define HZ_OBJ_TRACE(obj) ::Hazel::Log::GetClientLogger()->trace("{0}",obj)
#define HZ_OBJ_INFO(obj)  ::Hazel::Log::GetClientLogger()->info("{0}",obj)
#define HZ_OBJ_WARN(obj)  ::Hazel::Log::GetClientLogger()->warn("{0}",obj)
#define HZ_OBJ_ERROR(obj) ::Hazel::Log::GetClientLogger()->error("{0}",obj)
#define HZ_OBJ_CRITICAL(obj) ::Hazel::Log::GetClientLogger()->critical("{0}",obj)

// if dist build
