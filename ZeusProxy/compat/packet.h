#pragma once

#ifndef PACKET_H
#define PACKET_H

#include <string>

namespace compat
{
	class packet
	{
	public:

		int id;
		double time_current;
		std::string origin;

		packet(int id, std::string origin, double time_current);

		virtual ~packet();

		int get_id() const;

		std::string get_origin();

		double get_time_current() const;

	};
}

#endif