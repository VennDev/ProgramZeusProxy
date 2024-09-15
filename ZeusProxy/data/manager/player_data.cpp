#include "player_data.h"

#include <iostream>

#include "../protocols/protocols.h"
#include "../compat/packet.h"

#include <nlohmann/json.hpp>
#include <utility>

#include "data_manager.h"
#include "../../checks/check_manager.h"
#include "../../utils/blocks.h"
#include "../../utils/date_time.h"
#include "../../utils/zmath.h"
#include "../../utils/zvector.h"

using namespace compat;
using namespace protocols;

namespace data 
{
	namespace manager
	{
	    static constexpr short max_ticks = 9999;

		player_data::player_data(std::string name, std::string xuid) : 
            name_(std::move(name)), 
            xuid_(std::move(xuid)), 
            has_joined_(false), 
            on_ground_(false),
            open_window_(false),
            gamemode_(0),
            ping_(0), 
            death_ticks_(0), 
            respawn_ticks_(0), 
            velocity_ticks_(0),
            vertical_velocity_ticks_(0),
            horizontal_velocity_ticks_(0), 
            horizontal_speed_ticks_(0),
	        on_liquid_ticks_(false),
	        in_web_ticks_(false),
	        on_slippery_ground_ticks_(false),
	        on_elastomers_ticks_(false),
	        on_adhesion_ticks_(false),
	        on_stair_ticks_(false),
            teleport_ticks_(0), 
            move_ticks_(0), 
            ping_ticks_(0), 
            max_ping_ticks_(0), 
            total_ticks_(0), 
            digging_ticks_(0), 
            placing_ticks_(0),
            sneaking_ticks_(0), 
            sprinting_ticks_(0),
            steering_ticks_(0),
	        explosion_ticks_(0),
	        swing_arm_ticks_(0),
            speed_(0.0f),
            delta_x_(0.0f), 
            delta_y_(0.0f), 
            delta_z_(0.0f), 
            last_delta_x_(0.0f), 
            last_delta_y_(0.0f),
            last_delta_z_(0.0f), 
            delta_yaw_(0.0f), 
            last_delta_yaw_(0.0f), 
            delta_pitch_(0.0f), 
            last_delta_pitch_(0.0f),
            delta_xz_(0.0f), 
            last_delta_xz_(0.0f), 
            velocity_x_(0.0f), 
            velocity_y_(0.0f), 
            velocity_z_(0.0f),
            last_velocity_x_(0.0f), 
            last_velocity_y_(0.0f), 
            last_velocity_z_(0.0f)
        {
            //TODO: I don't know
        }

        std::string player_data::get_name() 
        {
            return name_;
        }

        std::string player_data::get_xuid()
        {
            return xuid_;
        }

        bool player_data::has_joined() const
        {
            return has_joined_;
        }

        void player_data::set_has_joined(const bool has_joined) 
        {
            has_joined_ = has_joined;
        }

        bool player_data::is_on_ground() const
        {
            return on_ground_;
        }

        void player_data::set_on_ground(const bool on_ground) 
        {
            on_ground_ = on_ground;
        }

        bool player_data::is_on_liquid() const
        {
            return on_liquid_ticks_ < 10;
        }

        bool player_data::is_in_web() const
        {
            return in_web_ticks_ < 10;
        }

        bool player_data::is_on_slippery_ground() const
        {
            return on_slippery_ground_ticks_ < 10;
        }

        bool player_data::is_on_elastomers() const
        {
            return on_elastomers_ticks_ < 10;
        }

        bool player_data::is_on_adhesion() const
        {
            return on_adhesion_ticks_ < 10;
        }

        bool player_data::is_on_stair() const
        {
            return on_stair_ticks_ < 10;
        }

        bool player_data::is_open_window() const
        {
            return open_window_;
        }

        void player_data::set_open_window(const bool open_window) 
        {
            open_window_ = open_window;
        }

        unsigned char player_data::get_game_mode() const
        {
            return gamemode_;
        }

        void player_data::set_game_mode(const unsigned char gamemode)
        {
            gamemode_ = gamemode;
        }

        short int player_data::get_ping() const
        {
            return ping_;
        }

        void player_data::set_ping(const short int ping)
        {
            ping_ = ping;
        }

        short int player_data::get_death_ticks() const
        {
            return death_ticks_;
        }

        void player_data::set_death_ticks(const short int death_ticks)
        {
            death_ticks_ = death_ticks;
        }

        short int player_data::get_respawn_ticks() const
        {
            return respawn_ticks_;
        }

        void player_data::set_respawn_ticks(const short int respawn_ticks)
        {
            respawn_ticks_ = respawn_ticks;
        }

        short int player_data::get_velocity_ticks() const
        {
            return velocity_ticks_;
        }

        void player_data::set_velocity_ticks(const short int velocity_ticks)
        {
            velocity_ticks_ = velocity_ticks;
        }

        short int player_data::get_vertical_velocity_ticks() const
        {
            return vertical_velocity_ticks_;
        }

        void player_data::set_vertical_velocity_ticks(const short int vertical_velocity_ticks)
        {
            vertical_velocity_ticks_ = vertical_velocity_ticks;
        }

        short int player_data::get_horizontal_velocity_ticks() const
        {
            return horizontal_velocity_ticks_;
        }

        void player_data::set_horizontal_velocity_ticks(const short int horizontal_velocity_ticks)
        {
            horizontal_velocity_ticks_ = horizontal_velocity_ticks;
        }

        short int player_data::get_horizontal_speed_ticks() const
        {
            return horizontal_speed_ticks_;
        }

        void player_data::set_horizontal_speed_ticks(const short int horizontal_speed_ticks)
        {
            horizontal_speed_ticks_ = horizontal_speed_ticks;
        }

	    short int player_data::get_on_liquid_ticks() const
        {
            return on_liquid_ticks_;
        }

	    void player_data::set_on_liquid_ticks(const short int on_liquid_ticks)
        {
            on_liquid_ticks_ = on_liquid_ticks;
        }

	    short int player_data::get_in_web_ticks() const
        {
            return in_web_ticks_;
        }

	    void player_data::set_in_web_ticks(const short int in_web_ticks)
        {
            in_web_ticks_ = in_web_ticks;
        }

	    short int player_data::get_on_slippery_ground_ticks() const
        {
            return on_slippery_ground_ticks_;
        }

	    void player_data::set_on_slippery_ground_ticks(const short int on_slippery_ground_ticks)
        {
            on_slippery_ground_ticks_ = on_slippery_ground_ticks;
        }

	    short int player_data::get_on_elastomers_ticks() const
        {
            return on_elastomers_ticks_;
        }

	    void player_data::set_on_elastomers_ticks(const short int on_elastomers_ticks)
        {
            on_elastomers_ticks_ = on_elastomers_ticks;
        }

	    short int player_data::get_on_adhesion_ticks() const
        {
            return on_adhesion_ticks_;
        }

	    void player_data::set_on_adhesion_ticks(const short int on_adhesion_ticks)
        {
            on_adhesion_ticks_ = on_adhesion_ticks;
        }

	    short int player_data::get_on_stair_ticks() const
        {
            return on_stair_ticks_;
        }

	    void player_data::set_on_stair_ticks(const short int on_stair_ticks)
        {
            on_stair_ticks_ = on_stair_ticks;
        }

	    short int player_data::get_explosion_ticks() const
        {
            return explosion_ticks_;
        }

	    void player_data::set_explosion_ticks(const short int explosion_ticks)
        {
            explosion_ticks_ = explosion_ticks;
        }

	    short int player_data::get_swing_arm_ticks() const
        {
            return swing_arm_ticks_;
        }

	    void player_data::set_swing_arm_ticks(const short int swing_arm_ticks)
        {
            swing_arm_ticks_ = swing_arm_ticks;
        }

        short int player_data::get_teleport_ticks() const
        {
            return teleport_ticks_;
        }

        void player_data::set_teleport_ticks(const short int teleport_ticks)
        {
            teleport_ticks_ = teleport_ticks;
        }

        short int player_data::get_move_ticks() const
        {
            return move_ticks_;
        }

        void player_data::set_move_ticks(const short int move_ticks)
        {
            move_ticks_ = move_ticks;
        }

        short int player_data::get_ping_ticks() const
        {
            return ping_ticks_;
        }

        void player_data::set_ping_ticks(const short int ping_ticks)
        {
            ping_ticks_ = ping_ticks;
        }

        short int player_data::get_max_ping_ticks() const
        {
            return max_ping_ticks_;
        }

        void player_data::set_max_ping_ticks(const short int max_ping_ticks)
        {
            max_ping_ticks_ = max_ping_ticks;
        }

        short int player_data::get_total_ticks() const
        {
            return total_ticks_;
        }

        void player_data::set_total_ticks(const short int total_ticks)
        {
            total_ticks_ = total_ticks;
        }

        short int player_data::get_digging_ticks() const
        {
            return digging_ticks_;
        }

        void player_data::set_digging_ticks(const short int digging_ticks)
        {
            digging_ticks_ = digging_ticks;
        }

        short int player_data::get_placing_ticks() const
        {
            return placing_ticks_;
        }

        void player_data::set_placing_ticks(const short int placing_ticks)
        {
            placing_ticks_ = placing_ticks;
        }

        short int player_data::get_sneaking_ticks() const
        {
            return sneaking_ticks_;
        }

        void player_data::set_sneaking_ticks(const short int sneaking_ticks)
        {
            sneaking_ticks_ = sneaking_ticks;
        }

        short int player_data::get_sprinting_ticks() const
        {
            return sprinting_ticks_;
        }

        void player_data::set_sprinting_ticks(const short int sprinting_ticks)
        {
            sprinting_ticks_ = sprinting_ticks;
        }

        short int player_data::get_steering_ticks() const
        {
            return steering_ticks_;
        }

        void player_data::set_steering_ticks(const short int steering_ticks)
        {
            steering_ticks_ = steering_ticks;
        }

        float player_data::get_speed() const
        {
            return speed_;
        }

        void player_data::set_speed(const float speed)
        {
            speed_ = speed;
        }

        float player_data::get_delta_x() const
        {
            return delta_x_;
        }

        void player_data::set_delta_x(const float delta_x) 
        {
            delta_x_ = delta_x;
        }

        float player_data::get_delta_y() const
        {
            return delta_y_;
        }

        void player_data::set_delta_y(const float delta_y) 
        {
            delta_y_ = delta_y;
        }

        float player_data::get_delta_z() const
        {
            return delta_z_;
        }

        void player_data::set_delta_z(const float delta_z) 
        {
            delta_z_ = delta_z;
        }

        float player_data::get_last_delta_x() const
        {
            return last_delta_x_;
        }

        void player_data::set_last_delta_x(const float last_delta_x) 
        {
            last_delta_x_ = last_delta_x;
        }

        float player_data::get_last_delta_y() const
        {
            return last_delta_y_;
        }

        void player_data::set_last_delta_y(const float last_delta_y) 
        {
            last_delta_y_ = last_delta_y;
        }

        float player_data::get_last_delta_z() const
        {
            return last_delta_z_;
        }

        void player_data::set_last_delta_z(const float last_delta_z) 
        {
            last_delta_z_ = last_delta_z;
        }

        float player_data::get_delta_yaw() const
        {
            return delta_yaw_;
        }

        void player_data::set_delta_yaw(const float delta_yaw) 
        {
            delta_yaw_ = delta_yaw;
        }

        float player_data::get_last_delta_yaw() const
        {
            return last_delta_yaw_;
        }

        void player_data::set_last_delta_yaw(const float last_delta_yaw) 
        {
            last_delta_yaw_ = last_delta_yaw;
        }

        float player_data::get_delta_pitch() const
        {
            return delta_pitch_;
        }

        void player_data::set_delta_pitch(const float delta_pitch) 
        {
            delta_pitch_ = delta_pitch;
        }

        float player_data::get_last_delta_pitch() const
        {
            return last_delta_pitch_;
        }

        void player_data::set_last_delta_pitch(const float last_delta_pitch) 
        {
            last_delta_pitch_ = last_delta_pitch;
        }

        float player_data::get_delta_xz() const
        {
            return delta_xz_;
        }

        void player_data::set_delta_xz(const float delta_xz) 
        {
            delta_xz_ = delta_xz;
        }

        float player_data::get_last_delta_xz() const
        {
            return last_delta_xz_;
        }

        void player_data::set_last_delta_xz(const float last_delta_xz) 
        {
            last_delta_xz_ = last_delta_xz;
        }

        float player_data::get_velocity_x() const
        {
            return velocity_x_;
        }

        void player_data::set_velocity_x(const float velocity_x) 
        {
            velocity_x_ = velocity_x;
        }

        float player_data::get_velocity_y() const
        {
            return velocity_y_;
        }

        void player_data::set_velocity_y(const float velocity_y) 
        {
            velocity_y_ = velocity_y;
        }

        float player_data::get_velocity_z() const
        {
            return velocity_z_;
        }

        void player_data::set_velocity_z(const float velocity_z) 
        {
            velocity_z_ = velocity_z;
        }

        float player_data::get_last_velocity_x() const
        {
            return last_velocity_x_;
        }

        void player_data::set_last_velocity_x(const float last_velocity_x) 
        {
            last_velocity_x_ = last_velocity_x;
        }

        float player_data::get_last_velocity_y() const
        {
            return last_velocity_y_;
        }

        void player_data::set_last_velocity_y(const float last_velocity_y) 
        {
            last_velocity_y_ = last_velocity_y;
        }

        float player_data::get_last_velocity_z() const
        {
            return last_velocity_z_;
        }

        void player_data::set_last_velocity_z(const float last_velocity_z) 
        {
            last_velocity_z_ = last_velocity_z;
        }

        location player_data::get_location() const
        {
            return location_;
        }

        void player_data::set_location(const location& location) 
        {
            location_ = location;
        }

        location player_data::get_last_location() const
        {
            return last_location_;
        }

        void player_data::set_last_location(const location& last_location) 
        {   
            last_location_ = last_location;
        }

        location player_data::get_last_last_location() const
        {
            return last_last_location_;
        }

        void player_data::set_last_last_location(const location& last_last_location)
        {
            last_last_location_ = last_last_location;
        }

        location player_data::get_recent_teleport() const
        {
            return recent_teleport_;
        }

        void player_data::set_recent_teleport(const location& recent_teleport)
        {
            recent_teleport_ = recent_teleport;
        }

        location player_data::get_last_teleport() const
        {
            return last_teleport_;
        }

        void player_data::set_last_teleport(const location& last_teleport)
        {
            last_teleport_ = last_teleport;
        }

        effects::effect_handler player_data::get_effect_handler() const
        {
            return effect_handler_;
        }

        void player_data::set_effect_handler(const effects::effect_handler effect_handler)
        {
            effect_handler_ = effect_handler;
        }

	    void player_data::update_ticks()
        {
            if (sneaking_ticks_ >= max_ticks) sneaking_ticks_ = 0;
            if (sprinting_ticks_ >= max_ticks) sprinting_ticks_ = 0;
            if (steering_ticks_ >= max_ticks) steering_ticks_ = 0;
            if (digging_ticks_ >= max_ticks) digging_ticks_ = 0;
            if (placing_ticks_ >= max_ticks) placing_ticks_ = 0;
            if (ping_ticks_ >= max_ticks) ping_ticks_ = 0;
            if (max_ping_ticks_ >= max_ticks) max_ping_ticks_ = 0;
            if (velocity_ticks_ >= max_ticks) velocity_ticks_ = 0;
            if (vertical_velocity_ticks_ >= max_ticks) vertical_velocity_ticks_ = 0;
            if (horizontal_velocity_ticks_ >= max_ticks) horizontal_velocity_ticks_ = 0;
            if (horizontal_speed_ticks_ >= max_ticks) horizontal_speed_ticks_ = 0;
            if (on_adhesion_ticks_ >= max_ticks) on_adhesion_ticks_ = 0;
            if (on_elastomers_ticks_ >= max_ticks) on_elastomers_ticks_ = 0;
            if (on_slippery_ground_ticks_ >= max_ticks) on_slippery_ground_ticks_ = 0;
            if (on_stair_ticks_ >= max_ticks) on_stair_ticks_ = 0;
            if (on_liquid_ticks_ >= max_ticks) on_liquid_ticks_ = 0;
            if (in_web_ticks_ >= max_ticks) in_web_ticks_ = 0;
            if (explosion_ticks_ >= max_ticks) explosion_ticks_ = 0;
            if (swing_arm_ticks_ >= max_ticks) swing_arm_ticks_ = 0;
            if (teleport_ticks_ >= max_ticks) teleport_ticks_ = 0;
            if (move_ticks_ >= max_ticks) move_ticks_ = 0;
            if (total_ticks_ >= max_ticks) total_ticks_ = 0;

		    respawn_ticks_++;
		    death_ticks_++;
            sneaking_ticks_++;
            sprinting_ticks_++;
            steering_ticks_++;
            digging_ticks_++;
            placing_ticks_++;
            ping_ticks_++;
            max_ping_ticks_++;
            velocity_ticks_++;
            vertical_velocity_ticks_++;
            horizontal_velocity_ticks_++;
            horizontal_speed_ticks_++;
            on_adhesion_ticks_++;
            on_elastomers_ticks_++;
            on_slippery_ground_ticks_++;
            on_stair_ticks_++;
            on_liquid_ticks_++;
            in_web_ticks_++;
            explosion_ticks_++;
            swing_arm_ticks_++;
            teleport_ticks_++;
            move_ticks_++;
            total_ticks_++;
        }

        void player_data::handle_packet(packet* packet)
        {
            if (dynamic_cast<packet_keep_alive*>(packet)) {
                total_ticks_ = 0;
            } 
            else if (dynamic_cast<packet_player_login*>(packet)) {
                has_joined_ = true;
                xuid_ = dynamic_cast<packet_player_login*>(packet)->get_xuid();
            }
            else if (dynamic_cast<packet_player_logout*>(packet)) {
                has_joined_ = false;
            }
            else if (dynamic_cast<packet_play_in_change_mode*>(packet))
            {
                gamemode_ = dynamic_cast<packet_play_in_change_mode*>(packet)->get_mode();
            }
            else if (dynamic_cast<packet_play_in_death*>(packet))
            {
                death_ticks_ = 0;
            }
            else if (dynamic_cast<packet_play_in_open_window*>(packet))
            {
                open_window_ = true;
            }
            else if (dynamic_cast<packet_play_in_close_window*>(packet))
            {
                open_window_ = false;
            }
            else if (dynamic_cast<packet_play_in_sneaking*>(packet))
            {
                sneaking_ticks_ = 0;
            }
            else if (dynamic_cast<packet_play_out_respawn*>(packet))
            {
                respawn_ticks_ = 0;
            }
            else if (dynamic_cast<packet_player_place_block*>(packet))
            {
                placing_ticks_ = 0;
            }
            else if (dynamic_cast<packet_player_break_block*>(packet))
            {
                digging_ticks_ = 0;
            }
            else if (dynamic_cast<packet_play_in_sprinting*>(packet))
            {
                sprinting_ticks_ = 0;
            }
            else if (dynamic_cast<packet_player_position*>(packet))
            {
                const packet_player_position* pk = dynamic_cast<packet_player_position*>(packet);

                // Last last location
                set_last_last_location(last_location_);

                // Last location
                set_last_location(location_);

                // This is new location
                location_.set_x(pk->get_x());
                location_.set_y(pk->get_y());
                location_.set_z(pk->get_z());
                location_.set_yaw(pk->get_yaw());
                location_.set_pitch(pk->get_pitch());
                location_.set_on_ground(pk->is_on_ground());
                location_.set_timestamp(date_time::microtime());
                set_on_ground(pk->is_on_ground());

                // This is new delta
                const float delta_x = static_cast<float>(location_.get_x() - last_location_.get_x());
                const float delta_y = static_cast<float>(location_.get_y() - last_location_.get_y());
                const float delta_z = static_cast<float>(location_.get_z() - last_location_.get_z());
                const float delta_yaw = abs(z_math::clamp_180(abs(static_cast<float>(location_.get_yaw() - last_location_.get_yaw()))));
                const float delta_pitch = abs(static_cast<float>(location_.get_pitch() - last_location_.get_pitch()));
                
                set_last_delta_x(get_delta_x());
                set_last_delta_y(get_delta_y());
                set_last_delta_z(get_delta_z());
                set_last_delta_yaw(get_delta_yaw());
                set_last_delta_pitch(get_delta_pitch());
                set_last_delta_xz(get_delta_xz());
                set_delta_x(delta_x);
                set_delta_y(delta_y);
                set_delta_z(delta_z);
                set_delta_xz(hypot(delta_x, delta_z));
                set_delta_yaw(delta_yaw);
                set_delta_pitch(delta_pitch);
                
                move_ticks_ = 0;
            }
            else if (dynamic_cast<packet_play_in_rotation*>(packet))
            {
                const packet_play_in_rotation* pk = dynamic_cast<packet_play_in_rotation*>(packet);
                location_.set_yaw(pk->get_yaw());
                location_.set_pitch(pk->get_pitch());
            }
            else if (dynamic_cast<packet_play_out_blocks_down*>(packet))
            {
                const packet_play_out_blocks_down* pk = dynamic_cast<packet_play_out_blocks_down*>(packet);
                const std::vector<int> blocks = pk->get_blocks();
                for (const int block : blocks) {
                    if (z_vector::is_exists_int(blocks::get_adhesive(), block)) {
                        on_adhesion_ticks_ = 0;
                        break;
                    }
                    
                    if (z_vector::is_exists_int(blocks::get_elastomers(), block)) {
                        on_elastomers_ticks_ = 0;
                        break;
                    }
                    
                    if (z_vector::is_exists_int(blocks::get_slippery(), block)) {
                        on_slippery_ground_ticks_ = 0;
                        break;
                    }
                    
                    if (z_vector::is_exists_int(blocks::get_stairs(), block)) {
                        on_stair_ticks_ = 0;
                        break;
                    }
                    
                    if (z_vector::is_exists_int(blocks::get_liquid(), block)) {
                        on_liquid_ticks_ = 0;
                        break;
                    }
                    
                    if (z_vector::is_exists_int(blocks::get_web(), block)) {
                        in_web_ticks_ = 0;
                        break;
                    }
                }
            }
            else if (dynamic_cast<packet_play_out_explosion*>(packet))
            {
                explosion_ticks_ = 0;
            }
            else if (dynamic_cast<packet_play_out_entity_teleport*>(packet))
            {
                teleport_ticks_ = 0;
            }
            else if (dynamic_cast<packet_play_out_transaction*>(packet))
            {
                // TODO: I don't know
            }
            else if (dynamic_cast<packet_player_arm_animation*>(packet))
            {
                swing_arm_ticks_ = 0;
            }

		    // This update ticks for all packets
            update_ticks();

		    // This checks for all packets is player cheating
		    checks::check_manager::checks(*this);

		    // This updates player data in database
		    data_manager::update_player_data(xuid_, *this);
        }

    }
}