#include "packet_handler.h"

#include <iostream>

namespace compat
{

	int packet_handler::next_id_ = 0;
	std::map<int, packet> packet_handler::packets_;

	void packet_handler::broadcast_packet(const packet& packet)
	{
		packets_.insert(std::make_pair(next_id_, packet));
		next_id_++;
	}

	void packet_handler::unset_packet(const int& id)
	{
		packets_.erase(id);
	}

	void packet_handler::drop_packets()
	{
		packets_.clear();
	}

	packet packet_handler::get_packet(const int& id)
	{
		const auto packet = packets_.find(id);
		return packet->second;
	}

	int packet_handler::get_packet_id(const packet& packet)
	{
		int found_key = 0;

		for (auto it = packets_.begin(); it != packets_.end(); ++it) {
			if (it->second.id == packet.id) {
				found_key = it->first;
				break;
			}
		}

		return found_key;
	}

	unsigned long long packet_handler::get_packet_count()
	{
		return packets_.size();
	}

	std::map<int, packet> packet_handler::get_packet_list()
	{
		std::map<int, packet> result;
		
		for (auto it = packets_.begin(); it != packets_.end(); ++it) result.insert(std::make_pair(it->first, it->second));

		return result;
	}

}