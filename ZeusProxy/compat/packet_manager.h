#pragma once

#ifndef PACKET_MANAGER_H
#define PACKET_MANAGER_H

#include "packet_handler.h"

namespace compat
{
	class packet_manager
	{
		static packet_handler handler_;
		static packet_manager instance_;
		static bool is_enable_;

	public:
		static void enable();

		static void disable();

		static void broadcast_packet(const packet& packet);

		static packet get_packet(const int& id);

		static packet_handler get_handler();
	};
}

#endif