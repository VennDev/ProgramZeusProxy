#pragma once

#ifndef Z_VECTOR_H
#define Z_VECTOR_H

#include <vector>
#include <string>

namespace utils
{
    class z_vector
    {
    public:
        static bool is_exists_int(const std::vector<int>& vec, const int& value);
        
        static bool is_exists_string(const std::vector<std::string>& vec, const std::string& value);
    };
}

#endif