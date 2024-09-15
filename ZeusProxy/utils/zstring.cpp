#include "zstring.h"

namespace utils
{

    std::string z_string::str_replace(const std::string& str, const std::string& search, const std::string& replace) 
    {
        std::string result = str;
        size_t pos = 0;

        while ((pos = result.find(search, pos)) != std::string::npos) {
            result.replace(pos, search.length(), replace);
            pos += replace.length();
        }

        return result;
    }

}