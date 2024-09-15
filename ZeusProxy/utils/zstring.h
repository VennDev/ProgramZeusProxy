#pragma once

#ifndef ZSTRING_H
#define ZSTRING_H

#include <iostream>

namespace utils
{
	class z_string
	{
	public:
		static std::string str_replace(const std::string& str, const std::string& search, const std::string& replace);
	};
}

#endif