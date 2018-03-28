#pragma once
#include <iostream>

class Vector4
{
public:
	Vector4();
	Vector4(float e0, float e1, float e2, float e3);
	~Vector4();

	inline float x() const;
	inline float y() const;
	inline float z() const;
	inline float w() const;

	inline float r() const;
	inline float g() const;
	inline float b() const;
	inline float a() const;

	inline float magnitude() const;
	inline float sq_magnitude() const;

	inline void Normalize();

	inline const Vector4& operator+() const;
	inline const Vector4& operator-() const;

	inline float  operator[](int i) const;
	inline float& operator[](int i);

	inline Vector4& operator+=(const Vector4 &other);
	inline Vector4& operator-=(const Vector4 &other);
	inline Vector4& operator*=(const Vector4 &other);
	inline Vector4& operator/=(const Vector4 &other);
	inline Vector4& operator*=(const float val);
	inline Vector4& operator/=(const float val);

	inline std::ostream& operator<<(std::ostream &os);

	float e[4];
};

inline Vector4 operator+(const Vector4 & v1, const Vector4 & v2)
{
	return Vector4(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2], v1.e[3] + v2.e[3]);
}

inline Vector4 operator-(const Vector4 & v1, const Vector4 & v2)
{
	return Vector4(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2], v1.e[3] - v2.e[3]);
}

inline Vector4 operator*(const Vector4 & v1, const Vector4 & v2)
{
	return Vector4(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2], v1.e[3] * v2.e[3]);
}

inline Vector4 operator/(const Vector4 & v1, const Vector4 & v2)
{
	return Vector4(v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2], v1.e[3] / v2.e[3]);
}

inline Vector4 operator*(const Vector4 & v1, float val)
{
	return Vector4(v1.e[0] * val, v1.e[1] * val, v1.e[2] * val, v1.e[3] * val);
}

inline Vector4 operator*(float val, const Vector4 & v1)
{
	return Vector4(v1.e[0] * val, v1.e[1] * val, v1.e[2] * val, v1.e[3] * val);
}

inline Vector4 operator/(const Vector4 & v1, float val)
{
	return Vector4(v1.e[0] / val, v1.e[1] / val, v1.e[2] / val, v1.e[3] / val);
}


inline float dot(const Vector4 & v1, const Vector4 & v2)
{
	return (v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2] + v1.e[3] * v2.e[3]);
}


inline Vector4 UnitVector(Vector4 v1)
{
	return v1 / v1.magnitude();
}