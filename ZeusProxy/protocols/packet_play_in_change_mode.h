#ifndef PACKET_PLAY_IN_CHANGE_MODE_H
#define PACKET_PLAY_IN_CHANGE_MODE_H

#include "../compat/packet.h"

using namespace compat;

namespace protocols
{
	class packet_play_in_change_mode final : public packet
	{
		unsigned char mode_;

	public:
		const unsigned char SURVIVAL = 0;
		const unsigned char CREATIVE = 1;
		const unsigned char ADVENTURE = 2;
		const unsigned char SPECTATOR = 3;
		const unsigned char OTHER = 4;

		packet_play_in_change_mode(
			const int _id,
			const std::string& _origin,
			const double _time_current,
			const unsigned char mode
		) : packet(_id, _origin, _time_current)
		{
			mode_ = mode;
		}

		unsigned char get_mode() const
		{
			return mode_;
		}
	};
}

#endif