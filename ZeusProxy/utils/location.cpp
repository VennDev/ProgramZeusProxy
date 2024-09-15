#include "location.h"
#include "zmath.h"

#include <cmath>
#include <algorithm>
#include <iostream>

#include "date_time.h"

namespace utils
{

	location::location()
		: x_(0.0), y_(0.0), z_(0.0), yaw_(0.0), pitch_(0.0), on_ground_(false)
	{
		timestamp_ = date_time::microtime();
	}

	double location::get_x() const
	{
		return x_;
	}

	double location::get_y() const
	{
		return y_;
	}

	double location::get_z() const
	{
		return z_;
	}

	void location::set_x(const double x)
	{
		x_ = x;
	}

	void location::set_y(const double y)
	{
		y_ = y;
	}

	void location::set_z(const double z)
	{
		z_ = z;
	}

	double location::get_yaw() const
	{
		return yaw_;
	}

	double location::get_pitch() const
	{
		return pitch_;
	}

	bool location::is_on_ground() const
	{
		return on_ground_;
	}

	void location::set_yaw(const double yaw)
	{
		yaw_ = yaw;
	}

	void location::set_pitch(const double pitch)
	{
		pitch_ = pitch;
	}

	void location::set_on_ground(const bool on_ground)
	{
		on_ground_ = on_ground;
	}

	void location::add(const double x, const double y, const double z, const double yaw, const double pitch)
	{
		x_ += x;
		y_ += y;
		z_ += z;
		yaw_ += yaw;
		pitch_ += pitch;
	}

	void location::subtract(const double x, const double y, const double z, const double yaw, const double pitch)
	{
		x_ += x;
		y_ += y;
		z_ += z;
		yaw_ += yaw;
		pitch_ += pitch;
	}

	bool location::equals(const location* location) const
	{
		return x_ == location->get_x() && y_ == location->get_y() && z_ == location->get_z() && yaw_ == location->get_yaw() && pitch_ == location->get_pitch() && on_ground_ == location->is_on_ground();
	}

	void location::set_timestamp(const double timestamp)
	{
		timestamp_ = timestamp;
	}

	double location::get_timestamp() const
	{
		return timestamp_;
	}

	std::string location::to_string() const
	{
		std::string string = "Location(";
		string += "x=" + std::to_string(x_) + ", ";
		string += "y=" + std::to_string(y_) + ", ";
		string += "z=" + std::to_string(z_) + ", ";
		string += "yaw=" + std::to_string(yaw_) + ", ";
		string += "pitch=" + std::to_string(pitch_) + ", ";
		string += "onGround=" + std::to_string(on_ground_) + ")";

		return string;
	}

	vector3::vector3(const double x, const double y, const double z)
		: x_(x), y_(y), z_(z)
	{

	}

	double vector3::get_x() const
	{
		return x_;
	}

	double vector3::get_y() const
	{
		return y_;
	}

	double vector3::get_z() const
	{
		return z_;
	}

	void vector3::set_x(const double x)
	{
		x_ = x;
	}

	void vector3::set_y(const double y)
	{
		y_ = y;
	}

	void vector3::set_z(const double z)
	{
		z_ = z;
	}

	void vector3::add(const double x, const double y, const double z)
	{
		x_ += x;
		y_ += y;
		z_ += z;
	}

	void vector3::subtract(const double x, const double y, const double z)
	{
		x_ -= x;
		y_ -= y;
		z_ -= z;
	}

	void vector3::multiply(const double x, const double y, const double z)
	{
		x_ *= x;
		y_ *= y;
		z_ *= z;
	}

	void vector3::divide(const double x, const double y, const double z)
	{
		x_ /= x;
		y_ /= y;
		z_ /= z;
	}

	void vector3::floor_x()
	{
		x_ = floor(x_);
	}

	void vector3::floor_y()
	{
		y_ = floor(y_);
	}

	void vector3::floor_z()
	{
		z_ = floor(z_);
	}

	vector3 vector3::to_ceil() const
	{
		vector3 result;
		result.x_ = ceil(x_);
		result.y_ = ceil(y_);
		result.z_ = ceil(z_);
		return result;
	}

	vector3 vector3::to_floor() const
	{
		vector3 result;

		result.x_ = floor(x_);
		result.y_ = floor(y_);
		result.z_ = floor(z_);

		return result;
	}

	vector3 vector3::to_round(const int precision, int mode) const
	{
		vector3 vector1;
		vector3 vector2;

		vector1.x_ = round(x_ * pow(10, precision)) / pow(10, precision);
		vector1.y_ = round(y_ * pow(10, precision)) / pow(10, precision);
		vector1.z_ = round(z_ * pow(10, precision)) / pow(10, precision);

		vector2.x_ = static_cast<int>(round(x_ * pow(10, precision)) / pow(10, precision));
		vector2.y_ = static_cast<int>(round(y_ * pow(10, precision)) / pow(10, precision));
		vector2.z_ = static_cast<int>(round(z_ * pow(10, precision)) / pow(10, precision));

		return precision > 0 ? vector1 : vector2;
	}

	vector3 vector3::to_abs() const
	{
		vector3 result;
		result.x_ = abs(x_);
		result.y_ = abs(y_);
		result.z_ = abs(z_);
		return result;
	}

	vector3 vector3::to_normalize() const
	{
		vector3 result(0.0, 0.0, 0.0);
		const double len = get_length_squared();

		if (len > 0) {
			result.divide(sqrt(len), sqrt(len), sqrt(len));
			return result;
		}

		return result;
	}

	vector3 vector3::to_cross(const vector3& vc) const
	{
		vector3 result;

		result.x_ = y_ * vc.get_z() - z_ * vc.get_y();
		result.y_ = z_ * vc.get_x() - x_ * vc.get_z();
		result.z_ = x_ * vc.get_y() - y_ * vc.get_x();

		return result;
	}

	vector3* vector3::get_intermediate_with_x_value(const vector3& vc, const float x) const
	{
		const double diff = vc.get_x() - x_;

		if ((diff * diff) < 0.0000001) {
			return nullptr;
		}

		const double f = (x - x_) / diff;
		if (f < 0 || f > 1) {
			return nullptr;
		}

		auto* result = new vector3();
		result->x_ = x;
		result->y_ = y_ + (vc.y_ - y_) * f;
		result->z_ = z_ + (vc.z_ - z_) * f;

		return result;
	}

	vector3* vector3::get_intermediate_with_y_value(const vector3& vc, const float y) const
	{
		const double diff = vc.get_y() - y_;

		if ((diff * diff) < 0.0000001) {
			return nullptr;
		}

		const double f = (y - y_) / diff;
		if (f < 0 || f > 1) {
			return nullptr;
		}

		auto* result = new vector3();
		result->x_ = x_ + (vc.x_ - x_) * f;
		result->y_ = y;
		result->z_ = z_ + (vc.z_ - z_) * f;

		return result;
	}

	vector3* vector3::get_intermediate_with_z_value(const vector3& vc, const float z) const
	{
		const double diff = vc.get_z() - z_;

		if ((diff * diff) < 0.0000001) {
			return nullptr;
		}

		const double f = (z - z_) / diff;
		if (f < 0 || f > 1) {
			return nullptr;
		}

		auto* result = new vector3();
		result->x_ = x_ + (vc.x_ - x_) * f;
		result->y_ = y_ + (vc.y_ - y_) * f;
		result->z_ = z;

		return result;
	}

	vector3 vector3::get_direction_vector(double pitch, double yaw)
	{
		const double y = -sin(z_math::deg2_rad(pitch));
		const double xz = cos(z_math::deg2_rad(pitch));
		const double x = -xz * sin(z_math::deg2_rad(yaw));
		const double z = xz * cos(z_math::deg2_rad(yaw));

		const vector3 result(x, y, z);
		return result.to_normalize();
	}

	double vector3::distance(const vector3& vector3) const
	{
		return sqrt(distance_squared(vector3));
	}

	double vector3::distance_squared(const vector3& vector3) const
	{
		return pow((x_ - vector3.get_x()), 2) + pow((y_ - vector3.get_y()), 2) + pow((z_ - vector3.get_z()), 2);
	}

	double vector3::max_plain_distance(const double x, const double z) const
	{
		return std::max(abs(x_ - x), abs(z_ - z));
	}

	double vector3::get_length() const
	{
		return sqrt(get_length_squared());
	}

	double vector3::get_length_squared() const
	{
		return x_ * x_ + y_ * y_ + z_ * z_;
	}

	double vector3::to_hypot(const double p1, const double p2)
	{
		return sqrt(p1 * p1 + p2 * p2);
	}

	double vector3::to_dot(const vector3& vector3) const
	{
		return x_ * vector3.get_x() + y_ * vector3.get_y() + z_ * vector3.get_z();
	}

	bool vector3::equals(const vector3& vector3) const
	{
		return x_ == vector3.get_x() && y_ == vector3.get_y() && z_ == vector3.get_z();
	}

}
