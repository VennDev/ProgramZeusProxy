#pragma once

#ifndef SPEED_B_H
#define SPEED_B_H

#include "../checks/types/check.h"

namespace checks
{
    namespace impl
    {
        namespace speed
        {
            class speed_b final : public types::check
            {
            public:
                static void handle(player_data player_d);
            };
        }
    }
}

#endif
