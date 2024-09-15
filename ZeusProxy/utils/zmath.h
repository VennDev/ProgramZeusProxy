#pragma once

#ifndef Z_MATH_H
#define Z_MATH_H

namespace utils
{
	class z_math
	{
	public:
		static double deg2_rad(const double& degrees);

		static bool can_double_to_short(double number);

		static float clamp_180(float angle);
	};
}

#endif