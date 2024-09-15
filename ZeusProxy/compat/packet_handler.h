#pragma once

#ifndef PACKET_HANDLER_H
#define PACKET_HANDLER_H

#include "packet.h"

#include <map>

namespace compat
{
	class packet_handler
	{
		static int next_id_;
		static std::map<int, packet> packets_;

	public:
		static void broadcast_packet(const packet& packet);

		static void unset_packet(const int& id);

		static void drop_packets();

		static packet get_packet(const int& id);

		static int get_packet_id(const packet& packet);

		static unsigned long long get_packet_count();

		static std::map<int, packet> get_packet_list();
	};
}

#endif