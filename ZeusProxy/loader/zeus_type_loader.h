#pragma once

#ifndef ZEUS_TYPE_LOADER_H
#define ZEUS_TYPE_LOADER_H

namespace loader
{
	class zeus_type_loader
	{
	public:

		zeus_type_loader() = default;

		static void load();

		static void unload();

	};
}

#endif