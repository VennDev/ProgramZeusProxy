#ifndef PACKET_PLAY_IN_SPRINTING_H
#define PACKET_PLAY_IN_SPRINTING_H

#include "../compat/packet.h"

using namespace compat;

namespace protocols
{
	class packet_play_in_sprinting final : public packet
	{
		bool cancelled_;

	public:
		packet_play_in_sprinting(
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