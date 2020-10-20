#pragma once
#include "GameObject.h"

const int OBJECT_CELL_SIZE = 50;
class CatchAbleObject : public GameObject
{
public:
	// C-tor CatchAbleObject
	CatchAbleObject(sf::Vector2f& pos);
	// draw CatchAble Objects
	virtual void draw(sf::RenderWindow & window);
	// d-tor CatchAbleObject
	virtual ~CatchAbleObject() = default;
	CatchAbleObject() = default;
	// Bounds of  CatchAble Objects
	sf::FloatRect getRect()
	{
		auto tmp = m_cell;
		tmp.setScale(0.7, 0.7);
		return tmp.getGlobalBounds();
	}
protected:
	// Sprite of CatchAble Objects
	sf::Sprite m_cell;
	sf::Clock m_timer;
	float m_change;
	int m_transparency;
	sf::Sprite m_background;
};

