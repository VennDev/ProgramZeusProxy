#include "alert_manager.h"

namespace alert
{

	const std::string info = text_format::green + "[INFO] " + text_format::reset;
	const std::string error = text_format::red + "[ERROR] " + text_format::reset;
	const std::string warning = text_format::yellow + "[WARNING] " + text_format::reset;
	const std::string notice = text_format::gold + "[NOTICE] " + text_format::reset;
	const std::string success = text_format::cyan + "[SUCCESS] " + text_format::reset;
	const std::string debug = text_format::magenta + "[DEBUG] " + text_format::reset;
	const std::string failed = text_format::red + "[FAILED] " + text_format::reset;

	void alert_manager::load()
	{
		alert_info("Loading AlertManager...");
	}

	void alert_manager::alert(const std::string& text)
	{
		std::cout << text << std::endl;
	}

	void alert_manager::alert_info(const std::string& text)
	{
		alert(info + text);
	}

	void alert_manager::alert_error(const std::string& text)
	{
		alert(error + text);
	}

	void alert_manager::alert_warning(const std::string& text)
	{
		alert(warning + text);
	}

	void alert_manager::alert_notice(const std::string& text)
	{
		alert(notice + text);
	}

	void alert_manager::alert_success(const std::string& text)
	{
		alert(success + text);
	}

	void alert_manager::alert_debug(const std::string& text)
	{
		alert(debug + text);
	}

	void alert_manager::alert_failed(const std::string& text)
	{
		alert(failed + text);
	}

}