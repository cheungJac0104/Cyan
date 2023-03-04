#include "Log.h"



namespace Cyan {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%d~%b~%Y %a %T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("CYAN");
		s_CoreLogger->set_level(spdlog::level::trace);
		s_ClientLogger = spdlog::stdout_color_mt("SLAVE");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}