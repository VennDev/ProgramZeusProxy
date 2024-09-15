#pragma once

#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include "player_data.h"

#include <iostream>
#include <string>

namespace data
{
	namespace manager
	{
		class data_manager
		{
			static std::map<std::string, player_data> player_data_;

		public:
			static std::map<std::string, player_data> get_players_data();

			static void set_players_data(std::map<std::string, player_data> data);

			static player_data get_player_data(const std::string& origin);

			static void update_player_data(const std::string& xuid, player_data data);

			static void inject(const std::string& name, const std::string& xuid);

			static void uninject(const std::string& origin);
		};
	}
}

#endif