#pragma once

#ifndef BADPACKETS_A_H
#define BADPACKETS_A_H

#include "../../types/check.h"

namespace checks
{
    namespace impl
    {
        namespace bad_packets
        {
            class bad_packets_a final : public types::check
            {
            public:
                static void handle(player_data player_d);
            };
        }
    }
}

#endif
