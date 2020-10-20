#pragma once
#include "StaticObject.h"
class DarkTile :public StaticObject
{
public:
	DarkTile() {};
	DarkTile(sf::Vector2f& position);
	~DarkTile() = default;


private:
	void setDarkTile(sf::Vector2f& position);
};

