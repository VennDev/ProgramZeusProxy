#include "badpackets_a.h"

#include <iostream>
#include <ostream>

namespace checks
{
    namespace impl
    {
        namespace bad_packets
        {
            void bad_packets_a::handle(player_data player_d)
            {
                const location loc = player_d.get_location();
                const int x = static_cast<int>(loc.get_x());
                const int y = static_cast<int>(loc.get_y());
                const int z = static_cast<int>(loc.get_z());
                
                const location last_loc = player_d.get_last_location();
                const int last_x = static_cast<int>(last_loc.get_x());
                const int last_y = static_cast<int>(last_loc.get_y());
                const int last_z = static_cast<int>(last_loc.get_z());

                const short int move_ticks = player_d.get_move_ticks();
                const short int velocity_ticks = player_d.get_velocity_ticks();

                if (velocity_ticks > 5 && move_ticks < 5 && !loc.is_on_ground() && x == last_x && y == last_y && z == last_z) {
                    const double delay = loc.get_timestamp() - last_loc.get_timestamp();
                    const double diff = abs(50 - delay);
                    
                    if (diff < 154) {
                        //std::cout << "diff: " << diff << std::endl;
                    }
                }
            }
        }
    }
}
