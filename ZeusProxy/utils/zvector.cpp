#include "zvector.h"

namespace utils
{

    bool z_vector::is_exists_int(const std::vector<int>& vec, const int& value)
    {
        return std::find(vec.begin(), vec.end(), value) != vec.end();
    }

    bool z_vector::is_exists_string(const std::vector<std::string>& vec, const std::string& value)
    {
        return std::find(vec.begin(), vec.end(), value) != vec.end();
    }
    
}
