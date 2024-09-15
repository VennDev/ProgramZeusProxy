#include "data_manager.h"

#include <utility>

namespace data
{
	namespace manager
	{
		std::map<std::string, player_data> data_manager::player_data_;

		std::map<std::string, player_data> data_manager::get_players_data()
		{
			return player_data_;
		}

		void data_manager::set_players_data(std::map<std::string, player_data> data)
		{
			player_data_ = std::move(data);
		}

		player_data data_manager::get_player_data(const std::string& origin)
		{
			player_data found_key = player_data("null", "null");

			for (auto it = player_data_.begin(); it != player_data_.end(); ++it) {
				if (it->second.get_name() == origin) {
					found_key = it->second;
					break;
				}
			}

			return found_key;
		}

		void data_manager::update_player_data(const std::string& xuid, player_data data)
		{
			player_data_.at(xuid) = data;
		}

		void data_manager::inject(const std::string& name, const std::string& xuid)
		{
			player_data data = get_player_data(xuid);

			if (data.get_name() == "null" && data.get_xuid() == "null") player_data_.insert(std::make_pair(xuid, player_data(name, xuid)));
		}

		void data_manager::uninject(const std::string& origin)
		{
			player_data data = get_player_data(origin);

			if (data.get_name() != "null" && data.get_xuid() != "null") player_data_.erase(data.get_xuid());
		}

	}
}