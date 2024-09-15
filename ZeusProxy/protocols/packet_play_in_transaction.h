#ifndef PACKET_PLAY_IN_TRANSACTION_H
#define PACKET_PLAY_IN_TRANSACTION_H

#include "../compat/packet.h"

using namespace compat;

namespace protocols
{
	class packet_play_in_transaction final : public packet
	{
		int source_type_;
		int source_flags_;
		unsigned char slot_;

	public:
		const unsigned char SOURCE_CONTAINER = 0;
		const unsigned char SOURCE_WORLD = 2;
		const unsigned char SOURCE_CREATIVE = 3;
		const unsigned int SOURCE_TODO = 99999;
		const signed char SOURCE_TYPE_CRAFTING_RESULT = -4;
		const signed char SOURCE_TYPE_CRAFTING_USE_INGREDIENT = -5;
		const signed char SOURCE_TYPE_ANVIL_RESULT = -12;
		const signed char SOURCE_TYPE_ANVIL_OUTPUT = -13;
		const signed char SOURCE_TYPE_ENCHANT_OUTPUT = -17;
		const signed char SOURCE_TYPE_TRADING_INPUT_1 = -20;
		const signed char SOURCE_TYPE_TRADING_INPUT_2 = -21;
		const signed char SOURCE_TYPE_TRADING_USE_INPUTS = -22;
		const signed char SOURCE_TYPE_TRADING_OUTPUT = -23;
		const signed char SOURCE_TYPE_BEACON = -24;
		const unsigned char ACTION_MAGIC_SLOT_CREATIVE_DELETE_ITEM = 0;
		const unsigned char ACTION_MAGIC_SLOT_CREATIVE_CREATE_ITEM = 1;
		const unsigned char ACTION_MAGIC_SLOT_DROP_ITEM = 0;
		const unsigned char ACTION_MAGIC_SLOT_PICKUP_ITEM = 1;

		packet_play_in_transaction(
			const int _id,
			const std::string& _origin,
			const double _time_current,
			const int sourceType,
			const int sourceFlags,
			unsigned char slot
		) : packet(_id, _origin, _time_current)
		{
			source_type_ = sourceType;
			source_flags_ = sourceFlags;
			slot_ = slot;
		}

		int get_source_type() const
		{
			return source_type_;
		}

		int get_source_flags() const
		{
			return source_flags_;
		}

		unsigned char get_slot() const
		{
			return slot_;
		}
	};
}

#endif