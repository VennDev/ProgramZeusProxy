#include "speed_a.h"
#include "speed_b.h"

#include <iostream>
#include <ostream>

namespace checks
{
    namespace impl
    {
        namespace speed
        {
            void speed_a::handle(player_data player_d)
            {
                short int ping = player_d.get_ping(); // i don't think this is needed

                bool is_on_ground = player_d.is_on_ground();

                short int death_ticks = player_d.get_death_ticks();
                short int respawn_ticks = player_d.get_respawn_ticks();
                short int velocity_ticks = player_d.get_velocity_ticks();
                short int move_ticks = player_d.get_move_ticks();

                float delta_yaw = player_d.get_delta_yaw();
                
                float delta_xz = player_d.get_delta_xz();
                float last_delta_xz = player_d.get_last_delta_xz();

                float accel = abs(delta_xz - last_delta_xz);

                if (is_on_ground && death_ticks != 0 && respawn_ticks != 0 && velocity_ticks != 0 && move_ticks < 3 && delta_yaw > 2.5F && delta_xz > .3F && accel < 1.0e-04) {
                    std::cout << "accel: " << accel << " delta_yaw: " << delta_yaw << " delta_xz: " << delta_xz << " last_delta_xz: " << last_delta_xz << std::endl;
                }
            }

            void speed_b::handle(player_data player_d)
            {
                
            }
        }
    }
}
