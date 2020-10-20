#include "CatchAbleObject.h"
#include "LoadFromFile.h"
#include <iostream>

CatchAbleObject::CatchAbleObject(sf::Vector2f & pos) : GameObject(pos)
{
	m_cell.setPosition(pos.y * (OBJECT_CELL_SIZE + 10), pos.x * (OBJECT_CELL_SIZE+10));
}


void CatchAbleObject::draw(sf::RenderWindow &window)
{
	window.draw(m_cell);
	m_ObjectAnim.makeObjectsAnimation(0.5f, window, m_objectShape, OBJECT_SIZE -8);

}