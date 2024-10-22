#ifndef PACKET_PLAY_IN_DEATH_H
#define PACKET_PLAY_IN_DEATH_H

#include "../compat/packet.h"

using namespace compat;

namespace protocols
{
	class packet_play_in_death final : public packet
	{
		float x_;
		float y_;
		float z_;

	public:
		packet_play_in_death(
			const int _id,
			const std::string& _origin,
			const double _time_current,
			const float x,
			const float y,
			const float z
		) : packet(_id, _origin, _time_current)
		{
			x_ = x;
			y_ = y;
			z_ = z;
		}

		float get_x() const
		{
			return x_;
		}

		float get_y() const
		{
			return y_;
		}

		float get_z() const
		{
			return z_;
		}
	};
}

#endif