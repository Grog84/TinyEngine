#pragma once

#include <string>
#include "Vector3.h"

class Actor
{
public:
	Actor();
	~Actor();

	void SetPosition(const Vector3& newSize);
	const Vector3& GetPosition() const;

	void SetRotation(const Vector3& newSize);
	const Vector3& GetRotation() const;

	void SetSize(const Vector3& newSize);
	const Vector3& GetSize() const;

	void MoveTo(const Vector3 & NewPosition);
	void RotateTo(const Vector3 & NewRotation);

	void Tag(const std::string & NewTag);
	void UnTag(const std::string & OldTag);
	const std::string * GetTags() const;

	/*
	* The name set is actually set might be different, but granted to be unique
	*/
	const std::string & SetName(std::string NewName);
	const std::string & GetName() const;
	static Actor * const GetNamed(const std::string & nameLookup);

	virtual void Update(float dt);

	virtual void Render();

protected:

	Vector3 _Position;
	Vector3 _Rotation;
	Vector3 _Size;

	std::string _Name;
	std::string * _Tags;


};

