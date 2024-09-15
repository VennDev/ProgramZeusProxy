#ifndef PACKET_PLAY_OUT_TRANSACTION_H
#define PACKET_PLAY_OUT_TRANSACTION_H

#include "../compat/packet.h"

using namespace compat;

namespace protocols
{
	class packet_play_out_transaction final : public packet
	{
		int source_type_;
		int source_flags_;
		int slot_;

	public:
		int const SOURCE_CONTAINER = 0;
		int const SOURCE_WORLD = 2;
		int const SOURCE_CREATIVE = 3;
		int const SOURCE_TODO = 99999;
		int const SOURCE_TYPE_CRAFTING_RESULT = -4;
		int const SOURCE_TYPE_CRAFTING_USE_INGREDIENT = -5;
		int const SOURCE_TYPE_ANVIL_RESULT = -12;
		int const SOURCE_TYPE_ANVIL_OUTPUT = -13;
		int const SOURCE_TYPE_ENCHANT_OUTPUT = -17;
		int const SOURCE_TYPE_TRADING_INPUT_1 = -20;
		int const SOURCE_TYPE_TRADING_INPUT_2 = -21;
		int const SOURCE_TYPE_TRADING_USE_INPUTS = -22;
		int const SOURCE_TYPE_TRADING_OUTPUT = -23;
		int const SOURCE_TYPE_BEACON = -24;

		int const ACTION_MAGIC_SLOT_CREATIVE_DELETE_ITEM = 0;
		int const ACTION_MAGIC_SLOT_CREATIVE_CREATE_ITEM = 1;
		int const ACTION_MAGIC_SLOT_DROP_ITEM = 0;
		int const ACTION_MAGIC_SLOT_PICKUP_ITEM = 1;

		packet_play_out_transaction(
			const int _id,
			const std::string& _origin,
			const double _time_current,
			const int source_type,
			const int slot,
			const int source_flags = 0
		) : packet(_id, _origin, _time_current)
		{
			source_type_ = source_type;
			slot_ = slot;
			source_flags_ = source_flags;
		}

		int get_source_type() const
		{
			return source_type_;
		}

		int get_slot() const
		{
			return slot_;
		}

		int get_source_flags() const
		{
			return source_flags_;
		}
	};
}

#endif