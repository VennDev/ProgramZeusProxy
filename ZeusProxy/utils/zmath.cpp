#include "zmath.h"

#include <math.h>
#include <cmath>
#include <limits.h>

namespace utils
{

	double z_math::deg2_rad(const double& degrees)
	{
		return degrees * 4.0 * atan(1.0) / 180.0;
	}

	bool z_math::can_double_to_short(const double number)
	{
		return number >= SHRT_MIN && number <= SHRT_MAX;
	}

	float z_math::clamp_180(float angle)
	{
		angle = fmod(angle, 360.0f);
		if (angle > 180.0f)
			angle -= 360.0f;
		if (angle < -180.0f)
			angle += 360.0f;
		return angle;
	}

}