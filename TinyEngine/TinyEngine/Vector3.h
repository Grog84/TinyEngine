#pragma once
#include <iostream>

class Vector3
{
public:
	Vector3();
	Vector3(float e0, float e1, float e2);
	
	inline float x() const;
	inline float y() const;
	inline float z() const;

	inline float r() const;
	inline float g() const;
	inline float b() const;

	inline float magnitude() const;
	inline float sq_magnitude() const;

	inline Vector3 UnitVector();

	inline const Vector3& operator+() const;
	inline const Vector3& operator-() const;

	inline float operator[](int i) const;
	inline float& operator[](int i);

	/*inline Vector3 operator+(const Vector3 &other) const;
	inline Vector3 operator-(const Vector3 &other) const;
	inline Vector3 operator*(const Vector3 &other) const;
	inline Vector3 operator/(const Vector3 &other) const;*/

	/*inline Vector3 operator*(const float val) const;
	inline Vector3 operator/(const float val) const;*/

	inline Vector3& operator+=(const Vector3 &other);
	inline Vector3& operator-=(const Vector3 &other);
	inline Vector3& operator*=(const Vector3 &other);
	inline Vector3& operator/=(const Vector3 &other);
	inline Vector3& operator*=(const float val);
	inline Vector3& operator/=(const float val);

	/*inline float dot(const Vector3 &other);
	inline Vector3 cross(const Vector3 &other);*/

	inline std::ostream& operator<<(std::ostream &os);

	~Vector3();

	float e[3];
};


inline Vector3 operator+(const Vector3 & v1, const Vector3 & v2)
{
	return Vector3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}

inline Vector3 operator-(const Vector3 & v1, const Vector3 & v2)
{
	return Vector3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}

inline Vector3 operator*(const Vector3 & v1, const Vector3 & v2)
{
	return Vector3(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}

inline Vector3 operator/(const Vector3 & v1, const Vector3 & v2)
{
	return Vector3(v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]);
}

inline Vector3 operator*(const Vector3 & v1, float val)
{
	return Vector3(v1.e[0] * val, v1.e[1] * val, v1.e[2] * val);
}

inline Vector3 operator*(float val, const Vector3 & v1)
{
	return Vector3(v1.e[0] * val, v1.e[1] * val, v1.e[2] * val);
}

inline Vector3 operator/(const Vector3 & v1, float val)
{
	return Vector3(v1.e[0] / val, v1.e[1] / val, v1.e[2] / val);
}



inline float dot(const Vector3 & v1, const Vector3 & v2)
{
	return (v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2]);
}

inline Vector3 cross(const Vector3 & v1, const Vector3 & v2)
{
	return Vector3((v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1]),
		(-(v1.e[0] * v2.e[2] - v1.e[2] * v2.e[0])),
		(v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]));
}