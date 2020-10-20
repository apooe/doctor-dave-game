#pragma once
#include "CatchAbleObject.h"
#include "LoadFromFile.h"
class Diamond : public CatchAbleObject
{
public:
	Diamond() {}; //default c_tor
	Diamond(sf::Vector2f & pos); //c_tor
	~Diamond() = default;//default d_tor
private:
	void setDiamond(); // create and set dimoand
};

