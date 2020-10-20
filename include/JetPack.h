#pragma once
#include "CatchAbleObject.h"
#include "LoadFromFile.h"
#include "GameFactoryPattern.h"
class JetPack : public CatchAbleObject
{
public:
	// dave fly
	JetPack() {};
	JetPack(sf::Vector2f& Position);
	~JetPack() = default;
	// set and create the jetpack
	void setJetAnim(sf::Vector2f& Position);

};


