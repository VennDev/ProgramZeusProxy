#include "packet.h"

#include <chrono>
#include <iostream>
#include <utility>

namespace compat 
{

	packet::packet(const int id, std::string origin, const double time_current)
		: id(id), time_current(time_current), origin(std::move(origin))
	{

	}

	packet::~packet() = default;

	int packet::get_id() const
	{
		return id;
	}

	std::string packet::get_origin()
	{
		return origin;
	}

	double packet::get_time_current() const
	{
		return time_current;
	}

};