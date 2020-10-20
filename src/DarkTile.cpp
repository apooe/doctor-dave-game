#include "DarkTile.h"
#include "LoadFromFile.h"
#include "GameFactoryPattern.h"

DarkTile::DarkTile(sf::Vector2f & position){m_objectTexture = LoadFromFile::getInstance().getTexture(o_rock);
	setDarkTile(position);
}

void DarkTile::setDarkTile(sf::Vector2f& position)
{
	m_objectShape.setTexture(*m_objectTexture);
	m_objectShape.setPosition({ position.y * OBJECT_SIZE, position.x * OBJECT_SIZE });
}

static bool m_instance = GameFactoryPattern<StaticObject>::registerit(Textures::T_rock,
	[](sf::Vector2f &place) -> std::unique_ptr<StaticObject> { return std::make_unique<DarkTile>(place); });