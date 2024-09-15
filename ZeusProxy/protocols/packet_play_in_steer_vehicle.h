#ifndef PACKET_PLAY_IN_STEER_VEHICLE_H
#define PACKET_PLAY_IN_STEER_VEHICLE_H

#include "../compat/packet.h"

using namespace compat;

namespace protocols
{
	class packet_play_in_steer_vehicle final : public packet
	{
		float strafe_;
		float forward_;

	public:
		packet_play_in_steer_vehicle(
			const int _id,
			const std::string& _origin,
			const double _time_current,
			const float strafe,
			const float forward
		) : packet(_id, _origin, _time_current)
		{
			strafe_ = strafe;
			forward_ = forward;
		}

		float get_strafe() const
		{
			return strafe_;
		}

		float get_forward() const
		{
			return forward_;
		}
	};
}

#endif