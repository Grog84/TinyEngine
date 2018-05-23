#include "stdafx.h"
#include "Actor.h"

Actor::Actor()
{ 
	SetPosition(Vector3(0, 0, 0));
	SetRotation(Vector3(0, 0, 0));
	SetSize(Vector3(0, 0, 0));

}

Actor::~Actor()
{
}

void Actor::SetPosition(const Vector3 & NewPosition)
{
	_Position = NewPosition;
}

const Vector3 & Actor::GetPosition() const
{
	// TODO: insert return statement here
}

void Actor::SetRotation(const Vector3 & NewRotation)
{
	_Rotation = NewRotation;
}

const Vector3 & Actor::GetRotation() const
{
	// TODO: insert return statement here
}

void Actor::SetSize(const Vector3 & NewSize)
{
	_Size = NewSize;
}

const Vector3 & Actor::GetSize() const
{
	// TODO: insert return statement here
}

void Actor::Tag(const std::string & NewTag)
{
	bool hasTag = false;
	// std::vector<std::string>::iterator it;

	for (auto it = _Tags.begin(); it != _Tags.end(); it++)
	{
		if (*it == NewTag)
		{
			hasTag = true;
			break;
		}
	}

	if (!hasTag)
	{
		_Tags.push_back(NewTag);
	}

}

void Actor::UnTag(const std::string & OldTag)
{
	for (auto it = _Tags.begin(); it != _Tags.end(); it++)
	{
		if (*it == OldTag)
		{
			_Tags.erase(it);
			break;
		}
	}
}

const std::list<std::string> & Actor::GetTags() const
{
	return _Tags;
}

const std::string & Actor::SetName(std::string NewName)
{
	//overkill for sure, but who knows how many unique actors we'll need
	static unsigned long long nameIndex = 0;

	if (NewName.length == 0)
	{
		NewName = SetName("Actor");
	}
	else
	{
		NewName[0] = toupper(NewName[0]);
		const Actor * preNamed = GetNamed(NewName);
		if ((preNamed == nullptr) || (preNamed == this))
		{
			_Name = NewName;
		}
		else
		{
			_Name = NewName + std::to_string(++nameIndex);
		}

		
		std::pair<std::map<std::string, Actor *>::iterator, bool> search = _NameList.insert(std::pair<std::string, Actor *>(_Name, this));
		
		if (!search.second)
		{
			printf("Failed to add to the Actor list the Actor with name: %s", _Name);
		}


	}

	return _Name;
}

const std::string & Actor::GetName() const
{
	return _Name;
}

Actor * const Actor::GetNamed(const std::string & NameLookup)
{
	std::map<std::string, Actor*>::iterator it = _NameList.find(NameLookup);
	if (it != _NameList.end())
	{
		return it->second;
	}

	return nullptr;
}

void Actor::Update(float dt)
{
}

void Actor::Render()
{
}
