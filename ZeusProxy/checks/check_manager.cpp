#include "check_manager.h"

#include "impl/badpackets/badpackets_a.h"
#include "impl/speed/speed_a.h"

using namespace checks::impl::bad_packets;
using namespace checks::impl::speed;

namespace checks
{
    
    void check_manager::checks(player_data player_data)
    {
        bad_packets_a::handle(player_data);
        speed_a::handle(player_data);
    }
    
}
