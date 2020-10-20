#pragma once
#include "StaticObject.h"
class Fire : public StaticObject
{
public:
	// Fire C-tor
	Fire(sf::Vector2f& ); 
	// Fire D-tor
	Fire() {};
	~Fire() = default;
	// make animetion for fire
	void ObjectAnimtion(sf::RenderWindow& window) override {
		m_ObjectAnim.makeObjectsAnimation(0.2f, window, m_objectShape, OBJECT_SIZE - 8);};
	//current fire direction
	sf::Vector2f getFireDir()const{return  m_fireDirction;}
private:
	sf::Vector2f m_fireDirction;
};

