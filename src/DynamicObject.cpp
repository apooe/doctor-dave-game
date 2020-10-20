#include "DynamicObject.h"
#include "LoadFromFile.h"


DynamicObject::DynamicObject(sf::Vector2f & pos) : GameObject(pos)
{
	m_inFire = LoadFromFile::getInstance().getTexture(o_explosion); // get texture explosion
}

