#pragma once

#ifndef CHECK_MANAGER_H
#define CHECK_MANAGER_H
#include "../data/manager/player_data.h"

namespace checks
{
	class check_manager
	{
	public:
		static void checks(data::manager::player_data player_data);
	};
}

#endif