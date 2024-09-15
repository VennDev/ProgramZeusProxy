#ifndef PACKET_PLAYER_POSITION_H
#define PACKET_PLAYER_POSITION_H

#include "../compat/packet.h"

using namespace compat;

namespace protocols
{
	class packet_player_position final : public packet
	{
		double x_;
		double y_;
		double z_;
		double yaw_;
		double pitch_;
		bool on_ground_;

	public:
		packet_player_position(
			const int _id,
			const std::string& _origin,
			const double _time_current,
			const double x,
			const double y,
			const double z,
			const double yaw,
			const double pitch,
			const bool on_ground
		) : packet(_id, _origin, _time_current)
		{
			x_ = x;
			y_ = y;
			z_ = z;
			yaw_ = yaw;
			pitch_ = pitch;
			on_ground_ = on_ground;
		}

		double get_x() const
		{
			return x_;
		}

		double get_y() const
		{
			return y_;
		}

		double get_z() const
		{
			return z_;
		}

		double get_yaw() const
		{
			return yaw_;
		}

		double get_pitch() const
		{
			return pitch_;
		}

		bool is_on_ground() const
		{
			return on_ground_;
		}
	};
}

#endif