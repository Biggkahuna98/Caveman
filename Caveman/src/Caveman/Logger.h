#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Caveman
{
	class CAVEMAN_API Logger
	{
	public:
		static void Init();

	inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return s_EngineLogger; }
	inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_EngineLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Engine logger macros
#define CM_ENGINE_TRACE(...)   ::Caveman::Logger::GetEngineLogger()->trace(__VA_ARGS__)
#define CM_ENGINE_INFO(...)    ::Caveman::Logger::GetEngineLogger()->info(__VA_ARGS__)
#define CM_ENGINE_WARN(...)    ::Caveman::Logger::GetEngineLogger()->warn(__VA_ARGS__)
#define CM_ENGINE_ERROR(...)   ::Caveman::Logger::GetEngineLogger()->error(__VA_ARGS__)
#define CM_ENGINE_FATAL(...)   ::Caveman::Logger::GetEngineLogger()->fatal(__VA_ARGS__)

// Client logger macros
#define CM_TRACE(...)          ::Caveman::Logger::GetClientLogger()->trace(__VA_ARGS__)
#define CM_INFO(...)           ::Caveman::Logger::GetClientLogger()->info(__VA_ARGS__)
#define CM_WARN(...)           ::Caveman::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define CM_ERROR(...)          ::Caveman::Logger::GetClientLogger()->error(__VA_ARGS__)
#define CM_FATAL(...)          ::Caveman::Logger::GetClientLogger()->fatal(__VA_ARGS__)