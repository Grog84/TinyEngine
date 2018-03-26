#include "stdafx.h"
#include "Ray.h"


Ray::Ray()
{
}

Ray::Ray(const Vector3 & origin, const Vector3 & direction)
{
	Origin = origin;
	Direction = direction;
}

inline Vector3 Ray::GetOrigin() const
{
	return Origin;
}

inline Vector3 Ray::GetDirection() const
{
	return Direction;
}

Vector3 Ray::PointAtPosition(float t) const
{
	return Origin + Direction*t;
}


Ray::~Ray()
{
}
