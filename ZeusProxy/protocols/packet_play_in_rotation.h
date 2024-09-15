#ifndef PACKET_PLAY_IN_ROTATION_H
#define PACKET_PLAY_IN_ROTATION_H

#include "../compat/packet.h"

using namespace compat;

namespace protocols
{
	class packet_play_in_rotation final : public packet
	{
		float yaw_;
		float pitch_;

	public:
		packet_play_in_rotation(
			const int _id,
			const std::string& _origin,
			const double _time_current,
			const float yaw,
			const float pitch
		) : packet(_id, _origin, _time_current)
		{
			yaw_ = yaw;
			pitch_ = pitch;
		}

		float get_yaw() const
		{
			return yaw_;
		}

		float get_pitch() const
		{
			return pitch_;
		}
	};
}

#endif