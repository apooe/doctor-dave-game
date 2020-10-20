#include "Fire.h"
#include "GameFactoryPattern.h"
#include "LoadFromFile.h"



Fire::Fire(sf::Vector2f &pos) : StaticObject(pos)
{
	m_objectTexture = LoadFromFile::getInstance().getTexture(o_fire);
	m_objectShape.setTexture(*m_objectTexture);
	m_objectShape.setPosition({ pos.y * OBJECT_SIZE, pos.x * OBJECT_SIZE });
	m_objectShape.move({ 5,5 });
}



static bool m_instance = GameFactoryPattern<StaticObject>::registerit(Textures::T_fire,
	[](sf::Vector2f &place) -> std::unique_ptr<StaticObject> { return std::make_unique<Fire>(place); });