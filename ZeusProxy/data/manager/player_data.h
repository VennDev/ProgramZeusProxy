#pragma once

#ifndef PLAYER_DATA_H
#define PLAYER_DATA_H

#include "../../utils/location.h"
#include "../data/transaction/effects/effect_handler.h"
#include "../compat/packet.h"

#include <string>

using namespace utils;
using namespace compat;
using namespace transaction;

namespace data 
{
	namespace manager
	{
		class player_data
		{
			std::string name_;
			std::string xuid_;
			bool has_joined_;
			bool on_ground_;
			bool open_window_;
			unsigned char gamemode_;
			short int ping_;
			short int death_ticks_;
			short int respawn_ticks_;
			short int velocity_ticks_;
			short int vertical_velocity_ticks_;
			short int horizontal_velocity_ticks_;
			short int horizontal_speed_ticks_;
			short int on_liquid_ticks_;
			short int in_web_ticks_;
			short int on_slippery_ground_ticks_;
			short int on_elastomers_ticks_;
			short int on_adhesion_ticks_;
			short int on_stair_ticks_;
			short int teleport_ticks_;
			short int move_ticks_;
			short int ping_ticks_;
			short int max_ping_ticks_;
			short int total_ticks_;
			short int digging_ticks_;
			short int placing_ticks_;
			short int sneaking_ticks_;
			short int sprinting_ticks_;
			short int steering_ticks_;
			short int explosion_ticks_;
			short int swing_arm_ticks_;
			float speed_;
			float delta_x_;
			float delta_y_;
			float delta_z_;
			float last_delta_x_;
			float last_delta_y_;
			float last_delta_z_;
			float delta_yaw_;
			float last_delta_yaw_;
			float delta_pitch_;
			float last_delta_pitch_;
			float delta_xz_;
			float last_delta_xz_;
			float velocity_x_;
			float velocity_y_;
			float velocity_z_;
			float last_velocity_x_;
			float last_velocity_y_;
			float last_velocity_z_;
			location location_;
			location last_location_;
			location last_last_location_;
			location recent_teleport_;
			location last_teleport_;
			effects::effect_handler effect_handler_;

			void update_ticks();

		public:
			player_data(std::string name, std::string xuid);
			
			std::string get_name();
			
			std::string get_xuid();

			bool has_joined() const;

			bool is_on_ground() const;

			bool is_on_liquid() const;

			bool is_in_web() const;

			bool is_on_slippery_ground() const;

			bool is_on_elastomers() const;

			bool is_on_adhesion() const;

			bool is_on_stair() const;

			bool is_open_window() const;

			unsigned char get_game_mode() const;

			short int get_ping() const;

			short int get_death_ticks() const;

			short int get_respawn_ticks() const;

			short int get_velocity_ticks() const;

			short int get_vertical_velocity_ticks() const;

			short int get_horizontal_velocity_ticks() const;

			short int get_horizontal_speed_ticks() const;

			short int get_on_liquid_ticks() const;

			short int get_in_web_ticks() const;

			short int get_on_slippery_ground_ticks() const;

			short int get_on_elastomers_ticks() const;

			short int get_on_adhesion_ticks() const;

			short int get_explosion_ticks() const;

			short int get_swing_arm_ticks() const;

			short int get_on_stair_ticks() const;

			short int get_teleport_ticks() const;

			short int get_move_ticks() const;

			short int get_ping_ticks() const;

			short int get_max_ping_ticks() const;

			short int get_total_ticks() const;

			short int get_digging_ticks() const;

			short int get_placing_ticks() const;

			short int get_sneaking_ticks() const;

			short int get_sprinting_ticks() const;

			short int get_steering_ticks() const;

			float get_speed() const;

			float get_delta_x() const;

			float get_delta_y() const;

			float get_delta_z() const;

			float get_last_delta_x() const;

			float get_last_delta_y() const;

			float get_last_delta_z() const;

			float get_delta_yaw() const;

			float get_last_delta_yaw() const;

			float get_delta_pitch() const;

			float get_last_delta_pitch() const;

			float get_delta_xz() const;

			float get_last_delta_xz() const;

			float get_velocity_x() const;

			float get_velocity_y() const;

			float get_velocity_z() const;

			float get_last_velocity_x() const;

			float get_last_velocity_y() const;

			float get_last_velocity_z() const;

			location get_location() const;

			location get_last_location() const;

			location get_last_last_location() const;

			location get_recent_teleport() const;

			location get_last_teleport() const;

			effects::effect_handler get_effect_handler() const;

			void set_has_joined(bool has_joined);

			void set_on_ground(bool on_ground);

			void set_open_window(bool open_window);

			void set_game_mode(unsigned char gamemode);

			void set_ping(short int ping);

			void set_death_ticks(short int death_ticks);

			void set_respawn_ticks(short int respawn_ticks);

			void set_velocity_ticks(short int velocity_ticks);

			void set_vertical_velocity_ticks(short int vertical_velocity_ticks);

			void set_horizontal_velocity_ticks(short int horizontal_velocity_ticks);

			void set_horizontal_speed_ticks(short int horizontal_speed_ticks);

			void set_on_liquid_ticks(short int on_liquid_ticks);

			void set_in_web_ticks(short int in_web_ticks);

			void set_on_slippery_ground_ticks(short int on_slippery_ground_ticks);

			void set_on_elastomers_ticks(short int on_elastomers_ticks);

			void set_on_adhesion_ticks(short int on_adhesion_ticks);

			void set_on_stair_ticks(short int on_stair_ticks);

			void set_explosion_ticks(short int explosion_ticks);

			void set_swing_arm_ticks(short int swing_arm_ticks);

			void set_teleport_ticks(short int teleport_ticks);

			void set_move_ticks(short int move_ticks);

			void set_ping_ticks(short int ping_ticks);

			void set_max_ping_ticks(short int max_ping_ticks);

			void set_total_ticks(short int total_ticks);

			void set_digging_ticks(short int digging_ticks);

			void set_placing_ticks(short int placing_ticks);

			void set_sneaking_ticks(short int sneaking_ticks);

			void set_sprinting_ticks(short int sprinting_ticks);

			void set_steering_ticks(short int steering_ticks);

			void set_speed(float speed);

			void set_delta_x(float delta_x);

			void set_delta_y(float delta_y);

			void set_delta_z(float delta_z);

			void set_last_delta_x(float last_delta_x);

			void set_last_delta_y(float last_delta_y);

			void set_last_delta_z(float last_delta_z);

			void set_delta_yaw(float delta_yaw);

			void set_last_delta_yaw(float last_delta_yaw);

			void set_delta_pitch(float delta_pitch);

			void set_last_delta_pitch(float last_delta_pitch);

			void set_delta_xz(float delta_xz);

			void set_last_delta_xz(float last_delta_xz);

			void set_velocity_x(float velocity_x);

			void set_velocity_y(float velocity_y);

			void set_velocity_z(float velocity_z);

			void set_last_velocity_x(float last_velocity_x);

			void set_last_velocity_y(float last_velocity_y);

			void set_last_velocity_z(float last_velocity_z);

			void set_location(const location& location);

			void set_last_location(const location& last_location);

			void set_last_last_location(const location& last_last_location);

			void set_recent_teleport(const location& recent_teleport);

			void set_last_teleport(const location& last_teleport);

			void set_effect_handler(effects::effect_handler effect_handler);

			void handle_packet(packet* packet);
		};
	}
}

#endif