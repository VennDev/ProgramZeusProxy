#ifndef PACKET_PLAYER_ARM_ANIMATION_H
#define PACKET_PLAYER_ARM_ANIMATION_H

#include "../compat/packet.h"

using namespace compat;

namespace protocols
{
	class packet_player_arm_animation final : public packet
	{
		bool cancelled_;

	public:
		packet_player_arm_animation(
			const int _id,
			const std::string& _origin,
			const double _time_current
		) : packet(_id, _origin, _time_current)
		{
			cancelled_ = false;
		}

		void cancel()
		{
			cancelled_ = true;
		}

		bool is_cancelled() const
		{
			return cancelled_;
		}
	};
}

#endif