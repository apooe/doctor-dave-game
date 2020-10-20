#pragma once
#include "StaticObject.h"
class Door : public StaticObject
{
public:
	// Door C-tor
	Door() {};
	// Door D-tor
	Door(sf::Vector2f& pos);
	~Door() = default;
	
private:
	// create and set door
	void setDoor();
};

