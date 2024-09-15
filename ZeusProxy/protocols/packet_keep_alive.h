#ifndef PACKET_KEEP_ALIVE_H
#define PACKET_KEEP_ALIVE_H

#include "../compat/packet.h"

using namespace compat;

namespace protocols
{
	class packet_keep_alive final : public packet
	{
		bool cancelled_;

	public:
		packet_keep_alive(
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