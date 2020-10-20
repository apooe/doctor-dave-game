#pragma once
#include "CatchAbleObject.h"
#include "LoadFromFile.h"

class Antidote : public CatchAbleObject
{
public:
	// Antidote c-TOR
	Antidote() {};
	//  Antidote D-TOR
	~Antidote() = default;
	// Antidote c-TOR
	Antidote(sf::Vector2f& pos);

private:
	// set  Antidote texture
	void setAntidote(sf::Vector2f& Position);
	// registerit Antidote
	static bool m_instance;
};

