#pragma once
#include "Virus.h"


class FluVirus : public Virus
{
public:
	// flu c-tor
	FluVirus(sf::Vector2f &position);
	FluVirus() = default;
	// flu D-tor
	~FluVirus() = default;
	// flu virus movement
	void move(sf::Vector2f curPos = Def) override;
	// dircection of bullets
	void moveBullet( sf::Vector2f direction)override;
	
private:
	void setFlu();
	void fluMovement();
	sf::Vector2f m_fluDirction; // dirction of flu
	sf::Vector2f m_currentVirusLocation;
};

