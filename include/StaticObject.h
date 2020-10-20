#pragma once
#include "GameObject.h"
class StaticObject : public GameObject
{
public:
	// C-tor StaticObject
	StaticObject(sf::Vector2f& pos) : GameObject(pos) {};
	// D-tor StaticObject
	StaticObject() {};
	virtual ~StaticObject() {};
};

