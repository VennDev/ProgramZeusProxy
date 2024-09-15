#ifndef PACKET_PLAY_OUT_BLOCKS_DOWN_H
#define PACKET_PLAY_OUT_BLOCKS_DOWN_H

#include "../compat/packet.h"

#include <vector>

using namespace compat;

namespace protocols
{
	class packet_play_out_blocks_down final : public packet
	{
		 std::vector<int> blocks_;

	public:
		packet_play_out_blocks_down(
			const int _id,
			const std::string& _origin,
			const double _time_current,
			const std::vector<int>& blocks
		) : packet(_id, _origin, _time_current)
		{
			blocks_ = blocks;
		}

		std::vector<int> get_blocks() const
		{
			return blocks_;
		}
	};
}

#endif