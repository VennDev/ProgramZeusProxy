#include "date_time.h"

#include <chrono>

namespace utils
{

    double date_time::microtime(const bool get_as_float)
    {
        const auto now = std::chrono::system_clock::now();
        const auto now_ms = std::chrono::time_point_cast<std::chrono::microseconds>(now);
        const auto epoch = now_ms.time_since_epoch();
        const auto value = std::chrono::duration_cast<std::chrono::microseconds>(epoch);
        const auto real_value = static_cast<double> (value.count());

        if (get_as_float) return real_value / 1000000.0;
        
        return real_value;
    }
    
}