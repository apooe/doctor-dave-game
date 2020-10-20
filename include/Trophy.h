#pragma once
#include "CatchAbleObject.h"
#include "LoadFromFile.h"

class Trophy : public CatchAbleObject
{
public:
	// Trophy C-tor
	Trophy(sf::Vector2f& pos);
	Trophy() = default;
	// Trophy D-tor
	~Trophy() = default;
private:
	void setTrophy();
};

