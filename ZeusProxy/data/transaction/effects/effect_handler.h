#pragma once

#ifndef EFFECT_HANDLER_H
#define EFFECT_HANDLER_H

#include <map>

namespace transaction
{
	namespace effects
	{
		class effect
		{
			int effect_id_;
			int amplifier_;
			int duration_;

		public:
			effect(int effect_id, int amplifier, int duration);

			int get_effect_id() const;

			int get_amplifier() const;

			int get_duration() const;
		};
		
		class effect_handler
		{
			static std::map<int, effect> effects_;
			
		public:
			static void handle_effect(int effect_id, int amplifier, int duration);

			static std::map<int, effect> get_effects();

			static effect get_effect(int effect_id);

			static bool has_effect(int effect_id);

			static bool remove_effect(int effect_id);
		};
	}
}

#endif