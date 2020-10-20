#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class ObjectAnim
{
public:
	ObjectAnim() { m_timer.restart(); };
	~ObjectAnim() {};
	void makeDaveAnimation(sf::RenderWindow& window, sf::Sprite& nurseSize, int size);
	void makeObjectsAnimation(float seconds, sf::RenderWindow&, sf::Sprite&, int);
	sf::Clock getTimer() {
		return m_timer;		
	}
	void setAnimTimer(sf::Clock timer) {
		m_timer = timer;
	}
protected:
	sf::Clock m_timer;
	 
};
