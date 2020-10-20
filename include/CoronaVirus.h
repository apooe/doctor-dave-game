#pragma once
#include "Virus.h"
const sf::Vector2f CORONA_DIR = { -0.7f,0 };
class CoronaVirus : public Virus
{
public:
	
	CoronaVirus(sf::Vector2f&); // c_tor
	~CoronaVirus() = default; // default d_tor
	 void move(sf::Vector2f d = Def) override; // move of corona virus
	 void moveBullet( sf::Vector2f direction) override; // move bullet of corona virus
	
	
private:
	static bool m_instance;
	sf::Vector2f m_coronaDirction; // direction of virus
	sf::Vector2f m_coronaPositon; // position
	void setBullet(Bullet & bullet, Direction dir); // set direction of bullet
	void setCorona(); // set texture
	void coronaMovement(); //movement of virus
};

