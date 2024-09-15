#ifndef PACKET_PLAY_IN_HELD_ITEM_SLOT_H
#define PACKET_PLAY_IN_HELD_ITEM_SLOT_H

#include "../compat/packet.h"

using namespace compat;

namespace protocols
{
	class packet_play_in_held_item_slot final : public packet
	{
		int idi_;
		int meta_;
		int slot_;
		std::string name_;
		std::string lore_;

	public:
		packet_play_in_held_item_slot(
			const int _id,
			const std::string& _origin,
			double _time_current,
			const int idi,
			const int meta,
			const int slot,
			const std::string& name,
			const std::string& lore
		) : packet(_id, _origin, _time_current)
		{
			idi_ = idi;
			meta_ = meta;
			slot_ = slot;
			name_ = name;
			lore_ = lore;
		}

		int get_id_item() const
		{
			return idi_;
		}

		int get_meta() const
		{
			return meta_;
		}

		int get_slot() const
		{
			return slot_;
		}

		std::string get_name()
		{
			return name_;
		}

		std::string get_lore()
		{
			return lore_;
		}
	};
}

#endif