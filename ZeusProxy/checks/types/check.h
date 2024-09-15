#pragma once

#ifndef CHECK_H
#define CHECK_H

#include "../data/manager/player_data.h"

using namespace data;
using namespace manager;

namespace checks
{
	namespace types
	{
		class check
		{
		public:
			void handle(player_data player_data);
		};
	}
}

#endif