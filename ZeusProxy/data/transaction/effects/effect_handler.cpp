#include "effect_handler.h"

#include <iostream>

namespace transaction
{
	namespace effects
	{
		
		effect::effect(const int effect_id, const int amplifier, const int duration)
			: effect_id_(effect_id), amplifier_(amplifier), duration_(duration)
		{
			//TODO: Add effect to player
		}

		int effect::get_effect_id() const
		{
			return effect_id_;
		}

		int effect::get_amplifier() const
		{
			return amplifier_;
		}

		int effect::get_duration() const
		{
			return duration_;
		}

		std::map<int, effect> effect_handler::effects_;

		void effect_handler::handle_effect(int effect_id, const int amplifier, const int duration)
		{
			effect effect(effect_id, amplifier, duration);
			effects_.insert(std::make_pair(effect_id, effect));
		}

		std::map<int, effect> effect_handler::get_effects()
		{
			return effects_;
		}

		effect effect_handler::get_effect(const int effect_id)
		{
			const std::map<int, effect>::iterator effect = effects_.find(effect_id);
			return effect->second;
		}

		bool effect_handler::has_effect(const int effect_id)
		{
			const std::map<int, effect>::iterator effect = effects_.find(effect_id);
			return effect != effects_.end();
		}

		bool effect_handler::remove_effect(const int effect_id)
		{
			const std::map<int, effect>::iterator effect = effects_.find(effect_id);

			if (effect != effects_.end()) {
				effects_.erase(effect);
				return true;
			}

			return false;
		}

	}
}