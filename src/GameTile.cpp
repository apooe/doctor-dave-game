#include "GameTile.h"


GameTile::GameTile(sf::Vector2f& tilePosition) : StaticObject(tilePosition)
{
	m_objectTexture = (LoadFromFile::getInstance().getTexture(o_GameTile));
	setTilePos(tilePosition);
}

void GameTile::setTilePos(sf::Vector2f& tilePosition)
{

	m_objectShape.setTexture(*m_objectTexture);
	m_objectShape.setPosition({ tilePosition.y * OBJECT_SIZE, tilePosition.x * OBJECT_SIZE });
}


bool isTile = GameFactoryPattern<StaticObject>::registerit(Textures::T_GameTile,
	[](sf::Vector2f &place) -> std::unique_ptr<StaticObject> { return std::make_unique<GameTile>(place); });