#ifndef PACKET_PLAY_IN_USE_ENTITY_H
#define PACKET_PLAY_IN_USE_ENTITY_H

#include "../compat/packet.h"

using namespace compat;

namespace protocols
{
	class packet_play_in_use_entity final : public packet
	{
		float origin_x_;
		float origin_y_;
		float origin_z_;
		float origin_yaw_;
		float origin_pitch_;
		float target_x_;
		float target_y_;
		float target_z_;
		float target_yaw_;
		float target_pitch_;

	public:
		packet_play_in_use_entity(
			const int _id,
			const std::string& _origin,
			const double _time_current,
			const float origin_x,
			const float origin_y,
			const float origin_z,
			const float origin_yaw,
			const float origin_pitch,
			const float target_x,
			const float target_y,
			const float target_z,
			const float target_yaw,
			const float target_pitch
		) : packet(_id, _origin, _time_current)
		{
			origin_x_ = origin_x;
			origin_y_ = origin_y;
			origin_z_ = origin_z;
			origin_yaw_ = origin_yaw;
			origin_pitch_ = origin_pitch;
			target_x_ = target_x;
			target_y_ = target_y;
			target_z_ = target_z;
			target_yaw_ = target_yaw;
			target_pitch_ = target_pitch;
		}

		float get_origin_x() const
		{
			return origin_x_;
		}

		float get_origin_y() const
		{
			return origin_y_;
		}

		float get_origin_z() const
		{
			return origin_z_;
		}

		float get_origin_yaw() const
		{
			return origin_yaw_;
		}

		float get_origin_pitch() const
		{
			return origin_pitch_;
		}

		float get_target_x() const
		{
			return target_x_;
		}

		float get_target_y() const
		{
			return target_y_;
		}

		float get_target_z() const
		{
			return target_z_;
		}

		float get_target_yaw() const
		{
			return target_yaw_;
		}

		float get_target_pitch() const
		{
			return target_pitch_;
		}
	};
}

#endif