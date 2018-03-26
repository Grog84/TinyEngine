#pragma once
#include"Vector3.h"

class Ray
{
public:

	Ray();
	Ray(const Vector3& origin, const Vector3& direction);

	inline Vector3 GetOrigin() const;
	inline Vector3 GetDirection() const;

	Vector3 PointAtPosition(float t) const;

	~Ray();

	Vector3 Origin;
	Vector3 Direction;

};

