#pragma once

#ifndef LOCATION_H
#define LOCATION_H

#define VECTOR_3_M_PI_2 1.57079632679489661923
#define VECTOR_3_M_PI_4 0.785398163397448309616
#define VECTOR_3_M_1_PI 0.318309886183790671538
#define VECTOR_3_M_2_PI 0.636619772367581343076

#include <string>

namespace utils
{
	class vector3
	{
		double x_;
		double y_;
		double z_;
		
	public:
		
		vector3(double x, double y, double z);

		vector3() = default;

		double get_x() const;

		double get_y() const;

		double get_z() const;

		void set_x(double x);

		void set_y(double y);

		void set_z(double z);

		void add(double x, double y, double z);

		void subtract(double x, double y, double z);

		void multiply(double x, double y, double z);

		void divide(double x, double y, double z);

		void floor_x();

		void floor_y();

		void floor_z();

		vector3 to_ceil() const;

		vector3 to_floor() const;

		vector3 to_round(int precision, int mode) const;

		vector3 to_abs() const;

		vector3 to_normalize() const;

		vector3 to_cross(const vector3& vector3) const;

		vector3* get_intermediate_with_x_value(const vector3& vector3, float x) const;

		vector3* get_intermediate_with_y_value(const vector3& vector3, float y) const;

		vector3* get_intermediate_with_z_value(const vector3& vector3, float z) const;

		static vector3 get_direction_vector(double pitch, double yaw);

		double distance(const vector3& vector3) const;

		double distance_squared(const vector3& vector3) const;

		double max_plain_distance(double x, double z) const;

		double get_length() const;

		double get_length_squared() const;

		static double to_hypot(double p1, double p2);

		double to_dot(const vector3& vector3) const;

		bool equals(const vector3& vector3) const;
	};

	class location
	{
		double x_;
		double y_;
		double z_;
		double yaw_;
		double pitch_;
		bool on_ground_;
		double timestamp_;

	public:
		location();

		double get_x() const;

		void set_x(double x);

		double get_y() const;

		void set_y(double y);

		double get_z() const;

		void set_z(double z);

		double get_yaw() const;

		void set_yaw(double yaw);

		double get_pitch() const;

		void set_pitch(double pitch);

		bool is_on_ground() const;

		void set_on_ground(bool on_ground);

		void add(double x, double y, double z, double yaw, double pitch);

		void subtract(double x, double y, double z, double yaw, double pitch);

		bool equals(const location* location) const;

		void set_timestamp(double timestamp);

		double get_timestamp() const;

		std::string to_string() const;
	};
}

#endif