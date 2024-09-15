#ifndef PACKET_PLAYER_LOGOUT_H
#define PACKET_PLAYER_LOGOUT_H

#include "../compat/packet.h"

using namespace compat;

namespace protocols
{
	class packet_player_logout final : public packet
	{
		bool cancelled_;
		std::string xuid_;

	public:
		packet_player_logout(
			const int _id,
			const std::string& _origin,
			const double _time_current,
			const std::string& xuid
		) : packet(_id, _origin, _time_current)
		{
			xuid_ = xuid;
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

		std::string get_xuid() const
		{
			return xuid_;
		}
	};
}

#endif