#pragma once
#include "DynamicObject.h"
#include "Bullet.h"

const sf::Vector2f FLU_DIR = { 0,-0.7f };
class Virus : public DynamicObject
{
public:
	// Virus C-tor
	Virus(sf::Vector2f& VirusPos);
	// Virus D-tor
	virtual ~Virus() = default;
	// virus movement
	virtual void move(sf::Vector2f VirusPos = Def) = 0;
	// make animetion for virus
	void ObjectAnimtion(sf::RenderWindow & window)
	{
		m_objectShape.setTexture(*m_objectTexture);
		m_ObjectAnim.makeObjectsAnimation(0.5f, window, m_objectShape, 52);
	}
	bool setFireOnObject(sf::RenderWindow& window);
	// create monster bullet 
	void setBullet();
	void drawBullet(sf::RenderWindow& window);
	virtual void moveBullet( sf::Vector2f direction) = 0;
	std::vector<std::unique_ptr<Bullet>> & getBulletVirus();
protected:
	std::vector<std::unique_ptr<Bullet>>m_bulletVirus; // vector of bullets for viruses
	
};