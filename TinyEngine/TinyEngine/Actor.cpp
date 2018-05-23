#include "stdafx.h"
#include "Actor.h"


Actor::Actor()
{ 
}


Actor::~Actor()
{
}

void Actor::SetPosition(const Vector3 & newSize)
{
}

const Vector3 & Actor::GetPosition() const
{
	// TODO: insert return statement here
}

void Actor::SetRotation(const Vector3 & newSize)
{
}

const Vector3 & Actor::GetRotation() const
{
	// TODO: insert return statement here
}

void Actor::SetSize(const Vector3 & newSize)
{
}

const Vector3 & Actor::GetSize() const
{
	// TODO: insert return statement here
}

void Actor::MoveTo(const Vector3 & NewPosition)
{
}

void Actor::RotateTo(const Vector3 & NewRotation)
{
}

void Actor::Tag(const std::string & NewTag)
{
}

void Actor::UnTag(const std::string & OldTag)
{
}

const std::string * Actor::GetTags() const
{
	return nullptr;
}

const std::string & Actor::SetName(std::string NewName)
{
	// TODO: insert return statement here
}

const std::string & Actor::GetName() const
{
	// TODO: insert return statement here
}

Actor * const Actor::GetNamed(const std::string & nameLookup)
{
	return nullptr;
}

void Actor::Update(float dt)
{
}

void Actor::Render()
{
}
