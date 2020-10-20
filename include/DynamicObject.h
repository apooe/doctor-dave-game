#pragma once
#include "GameObject.h"

class DynamicObject : public GameObject
{
public:

	DynamicObject(sf::Vector2f& pos); //c_tor
	DynamicObject() {};
	virtual ~DynamicObject()  = default;
	virtual void move(sf::Vector2f = Def) = 0; //virtual function that move object
	bool getLife() const { return m_DynamicObjectlife; } // return if object dead
	void setLife(const bool& currLife) { m_DynamicObjectlife = currLife; }//set dead or not

protected:
	sf::Clock m_clock; // for movement
	sf::Texture *m_inFire = nullptr;
	bool m_DynamicObjectlife = false;
};
