#include "stdafx.h"
#include "Vector3.h"
#include<cmath>
#include<cassert>

Vector3::Vector3()
{
}

Vector3::Vector3(float e0, float e1, float e2)
{
}

inline float Vector3::x() const
{
	return e[0];
}

inline float Vector3::y() const
{
	return e[1];
}

inline float Vector3::z() const
{
	return e[2];
}

inline float Vector3::r() const
{
	return e[0];
}

inline float Vector3::g() const
{
	return e[1];
}

inline float Vector3::b() const
{
	return e[2];
}

inline float Vector3::magnitude() const
{
	return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
}

inline float Vector3::sq_magnitude() const
{
	return (e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
}

inline Vector3 Vector3::UnitVector()
{
	return (*this) / (this->magnitude());
}

inline const Vector3 & Vector3::operator+() const
{
	return *this;
}

inline const Vector3 & Vector3::operator-() const
{
	return Vector3(-e[0], -e[1], -e[2]);
}

inline float Vector3::operator[](int i) const
{
	assert(i >= 0 && i <= 2);
	return e[i];
}

inline float & Vector3::operator[](int i)
{
	assert(i >= 0 && i <= 2);
	return e[i];
}

inline Vector3 Vector3::operator+(const Vector3 & other)
{
	return Vector3(e[0] + other.x(), e[1] + other.y(), e[2] + other.z());
}

inline Vector3 Vector3::operator-(const Vector3 & other) const
{
	return Vector3(e[0] - other.x(), e[1] - other.y(), e[2] - other.z());
}

inline Vector3 Vector3::operator*(const Vector3 & other) const
{
	return Vector3(e[0] * other.x(), e[1] * other.y(), e[2] * other.z());
}

inline Vector3 Vector3::operator/(const Vector3 & other) const
{
	return Vector3(e[0] / other.x(), e[1] / other.y(), e[2] / other.z());
}

inline Vector3 Vector3::operator*(const float val) const
{
	return Vector3(e[0] * val, e[1] * val, e[2] * val);
}

inline Vector3 Vector3::operator/(const float val) const
{
	return Vector3(e[0] / val, e[1] / val, e[2] / val);
}

inline Vector3 & Vector3::operator+=(const Vector3 & other)
{
	e[0] += other.x();
	e[1] += other.y();
	e[2] += other.z();
	return *this;
}

inline Vector3 & Vector3::operator-=(const Vector3 & other)
{
	e[0] -= other.x();
	e[1] -= other.y();
	e[2] -= other.z();
	return *this;
}

inline Vector3 & Vector3::operator*=(const Vector3 & other)
{
	e[0] *= other.x();
	e[1] *= other.y();
	e[2] *= other.z();
	return *this;
}

inline Vector3 & Vector3::operator/=(const Vector3 & other)
{
	e[0] /= other.x();
	e[1] /= other.y();
	e[2] /= other.z();
	return *this;
}

inline Vector3 & Vector3::operator*=(const float val)
{
	e[0] *= val;
	e[1] *= val;
	e[2] *= val;
	return *this;
}

inline Vector3 & Vector3::operator/=(const float val)
{
	e[0] /= val;
	e[1] /= val;
	e[2] /= val;
	return *this;
}

inline float Vector3::dot(const Vector3 & other)
{
	return (e[0]*other.x() + e[1]*other.y() + e[2]*other.z());
}

inline Vector3 Vector3::cross(const Vector3 & other)
{
	return Vector3(	(e[1]*other.z() - e[2]*other.y()),
				  (-(e[0]*other.z() - e[2]*other.x())),
					(e[0]*other.y() - e[1]*other.x()));
}

inline std::ostream & Vector3::operator<<(std::ostream & os)
{
	os << e[0] << " " << e[1] << " " << e[2];
	return os;
}

Vector3::~Vector3()
{
}