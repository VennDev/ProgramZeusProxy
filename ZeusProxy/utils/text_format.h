#pragma once

#ifndef TEXT_FORMAT_H
#define TEXT_FORMAT_H

#include <string>

namespace utils
{
	class text_format
	{
	public:
		static const std::string escape;
		static const std::string eol;
		static const std::string reset;
		static const std::string red;
		static const std::string green;
		static const std::string yellow;
		static const std::string blue;
		static const std::string black;
		static const std::string magenta;
		static const std::string cyan;
		static const std::string white;
		static const std::string gold;
		static const std::string gray;
		static const std::string bold_red;
		static const std::string bold_green;
		static const std::string bold_yellow;
		static const std::string bold_blue;
		static const std::string bold_magenta;
		static const std::string bold_cyan;
		static const std::string bold_white;
		static const std::string bold_gold;

		static std::string colorize(std::string text);
	};
}

#endif