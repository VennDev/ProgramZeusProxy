#ifndef PACKET_PLAY_OUT_ENTITY_EFFECT_H
#define PACKET_PLAY_OUT_ENTITY_EFFECT_H

#include "../compat/packet.h"

using namespace compat;

namespace protocols
{
	class packet_play_out_entity_effect final : public packet
	{
		unsigned char effect_id_;
		float amplifier_;
		float duration_;
		unsigned char flags_;

	public:
		unsigned char const ABSORPTION = 22;
		unsigned char const BAD_OMEN = 24;
		unsigned char const BLINDNESS = 15;
		unsigned char const CONDUIT_POWER = 25;
		unsigned char const DOLPHINS_GRACE = 26;
		unsigned char const FIRE_RESISTANCE = 12;
		unsigned char const GLOWING = 25;
		unsigned char const HASTE = 3;
		unsigned char const HEALTH_BOOST = 21;
		unsigned char const HERO_OF_THE_VILLAGE = 27;
		unsigned char const HUNGER = 17;
		unsigned char const INSTANT_DAMAGE = 2;
		unsigned char const INSTANT_HEALTH = 1;
		unsigned char const INVISIBILITY = 14;
		unsigned char const JUMP = 8;
		unsigned char const LEVITATION = 24;
		unsigned char const LUCK = 23;
		unsigned char const MINING_FATIGUE = 4;
		unsigned char const NAUSEA = 9;
		unsigned char const NIGHT_VISION = 16;
		unsigned char const POISON = 19;
		unsigned char const REGENERATION = 10;
		unsigned char const RESISTANCE = 11;
		unsigned char const SATURATION = 23;
		unsigned char const SLOWNESS = 5;
		unsigned char const SLOW_FALLING = 28;
		unsigned char const SPEED = 1;
		unsigned char const STRENGTH = 5;
		unsigned char const UNLUCK = 22;
		unsigned char const WATER_BREATHING = 13;
		unsigned char const WEAKNESS = 18;
		unsigned char const WITHER = 20;

		unsigned char const ADD = 0;
		unsigned char const MODIFY = 1;
		unsigned char const REMOVE = 2;

		packet_play_out_entity_effect(
			const int _id,
			const std::string& _origin,
			const double _time_current,
			const unsigned char effectId,
			const float amplifier,
			const float duration,
			const unsigned char flags
		) : packet(_id, _origin, _time_current)
		{
			effect_id_ = effectId;
			amplifier_ = amplifier;
			duration_ = duration;
			flags_ = flags;
		}

		unsigned char get_effect_id() const
		{
			return effect_id_;
		}

		float get_amplifier() const
		{
			return amplifier_;
		}

		float get_duration() const
		{
			return duration_;
		}

		unsigned char get_flags() const
		{
			return flags_;
		}
	};
}

#endif