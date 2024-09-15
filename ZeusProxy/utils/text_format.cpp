#include "text_format.h"

namespace utils
{

	const std::string text_format::escape = "&";
	const std::string text_format::eol = "\n";
	const std::string text_format::reset = "\033[0m";
	const std::string text_format::red = "\033[31m";
	const std::string text_format::green = "\033[32m";
	const std::string text_format::yellow = "\033[33m";
	const std::string text_format::blue = "\033[34m";
	const std::string text_format::black = "\033[30m";
	const std::string text_format::magenta = "\033[35m";
	const std::string text_format::cyan = "\033[36m";
	const std::string text_format::white = "\033[37m";
	const std::string text_format::gold = "\033[38;5;214m";
	const std::string text_format::gray = "\033[90m";
	const std::string text_format::bold_red = "\033[1;31m";
	const std::string text_format::bold_green = "\033[1;32m";
	const std::string text_format::bold_yellow = "\033[1;33m";
	const std::string text_format::bold_blue = "\033[1;34m";
	const std::string text_format::bold_magenta = "\033[1;35m";
	const std::string text_format::bold_cyan = "\033[1;36m";
	const std::string text_format::bold_white = "\033[1;37m";
	const std::string text_format::bold_gold = "\033[1;38;5;214m";

	std::string text_format::colorize(std::string text)
	{
		return text;
	}

}