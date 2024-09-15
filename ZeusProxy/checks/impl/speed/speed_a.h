#pragma once

#ifndef SPEED_A_H
#define SPEED_A_H

#include "../../types/check.h"

namespace checks
{
    namespace impl
    {
        namespace speed
        {
            class speed_a final : public types::check
            {
            public:
                static void handle(player_data player_d);
            };
        }
    }
}

#endif
