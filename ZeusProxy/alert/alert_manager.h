#pragma once

#ifndef ALERT_MANAGER_H
#define ALERT_MANAGER_H

#include "../utils/text_format.h"

#include <iostream>
#include <string>

using namespace utils;

namespace alert
{
	class alert_manager
	{
	public:

		static void load();

		static void alert(const std::string& text);

		static void alert_info(const std::string& text);

		static void alert_error(const std::string& text);

		static void alert_warning(const std::string& text);

		static void alert_notice(const std::string& text);

		static void alert_success(const std::string& text);

		static void alert_debug(const std::string& text);

		static void alert_failed(const std::string& text);
	};
}

#endif