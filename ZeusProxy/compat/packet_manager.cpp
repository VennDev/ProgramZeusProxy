#include "packet_manager.h"
#include "../alert/alert_manager.h"

#include <iostream>

using namespace alert;

namespace compat
{

	packet_handler packet_manager::handler_;
	packet_manager packet_manager::instance_;
	bool packet_manager::is_enable_;

	void packet_manager::enable()
	{
		is_enable_ = true;
		alert_manager::alert_info("Loading PacketManager...");
	}

	void packet_manager::disable()
	{
		is_enable_ = false;
	}

	void packet_manager::broadcast_packet(const packet& packet)
	{
		packet_handler::broadcast_packet(packet);
	}

	packet packet_manager::get_packet(const int& id)
	{
		return packet_handler::get_packet(id);
	}

	packet_handler packet_manager::get_handler()
	{
		return handler_;
	}

}