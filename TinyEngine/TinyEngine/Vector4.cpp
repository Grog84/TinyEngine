#include "stdafx.h"
#include <cassert>

#include "Vector4.h"


Vector4::Vector4()
{
}

Vector4::Vector4(float e0, float e1, float e2, float e3)
{
}


Vector4::~Vector4()
{
}

inline float Vector4::x() const
{
	return e[0];
}

inline float Vector4::y() const
{
	return e[1];
}

inline float Vector4::z() const
{
	return e[2];
}

inline float Vector4::w() const
{
	return e[3];
}

inline float Vector4::r() const
{
	return e[0];
}

inline float Vector4::g() const
{
	return e[1];
}

inline float Vector4::b() const
{
	return e[2];
}

inline float Vector4::a() const
{
	return e[3];
}

inline float Vector4::magnitude() const
{
	return sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2] + e[3] * e[3]);
}

inline float Vector4::sq_magnitude() const
{
	return (e[0] * e[0] + e[1] * e[1] + e[2] * e[2] + e[3] * e[3]);
}

inline void Vector4::Normalize()
{
	float k = 1.0 / sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2] + e[3] * e[3]);
	e[0] *= k;
	e[1] *= k;
	e[2] *= k;
	e[3] *= k;
}

inline const Vector4 & Vector4::operator+() const
{
	return *this;
}

inline const Vector4 & Vector4::operator-() const
{
	return Vector4(-e[0], -e[1], -e[2], -e[3]);
}

inline float Vector4::operator[](int i) const
{
	assert(i >= 0 && i <= 3);
	return e[i];
}

inline float & Vector4::operator[](int i)
{
	assert(i >= 0 && i <= 3);
	return e[i];
}

inline Vector4 & Vector4::operator+=(const Vector4 & other)
{
	e[0] += other.e[0];
	e[1] += other.e[1];
	e[2] += other.e[2];
	e[3] += other.e[3];
	return *this;
}

inline Vector4 & Vector4::operator-=(const Vector4 & other)
{
	e[0] -= other.e[0];
	e[1] -= other.e[1];
	e[2] -= other.e[2];
	e[3] -= other.e[3];
	return *this;
}

inline Vector4 & Vector4::operator*=(const Vector4 & other)
{
	e[0] *= other.e[0];
	e[1] *= other.e[1];
	e[2] *= other.e[2];
	e[3] *= other.e[3];
	return *this;
}

inline Vector4 & Vector4::operator/=(const Vector4 & other)
{
	e[0] /= other.e[0];
	e[1] /= other.e[1];
	e[2] /= other.e[2];
	e[3] /= other.e[3];
	return *this;
}

inline Vector4 & Vector4::operator*=(const float val)
{
	e[0] *= val;
	e[1] *= val;
	e[2] *= val;
	e[3] *= val;
	return *this;
}

inline Vector4 & Vector4::operator/=(const float val)
{
	e[0] /= val;
	e[1] /= val;
	e[2] /= val;
	e[3] /= val;
	return *this;
}

inline std::ostream & Vector4::operator<<(std::ostream & os)
{
	os << e[0] << " " << e[1] << " " << e[2] << " " << e[3];;
	return os;
}
