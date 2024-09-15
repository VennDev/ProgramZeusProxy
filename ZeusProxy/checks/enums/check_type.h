#pragma once

#ifndef CHECK_TYPES_H
#define CHECK_TYPES_H

namespace checks
{
	namespace enums
	{
        enum class check_category 
        {
            combat,
            world,
            movement,
            others
        };

        enum class check_type 
        {
            aim,
            auto_clicker,
            bad_packets,
            fly,
            kill_aura,
            scaffold,
            speed,
            motion,
            no_fall,
            jesus,
            vehicle,
            ely_tra,
            timer,
            om_ni_sprint,
            no_slow,
            reach,
            velocity,
            inventory,
            interact,
            fast_climb,
            hit_box
        };
	}
}

#endif