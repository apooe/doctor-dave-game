#include "Door.h"
#include "LoadFromFile.h"
#include "GameFactoryPattern.h"

Door::Door(sf::Vector2f &position) : StaticObject(position){m_objectTexture = LoadFromFile::getInstance().getTexture(o_door);
	setDoor();
}

void Door::setDoor()
{
	m_objectShape.setTexture(*m_objectTexture);
	m_objectShape.setOrigin(sf::Vector2f{ 50 / 2, 50 / 2 });
	m_objectShape.move(50 / 2, 50 / 2);
}


static bool m_instance= GameFactoryPattern<StaticObject>::registerit(Textures::T_door,
	[](sf::Vector2f &place) -> std::unique_ptr<StaticObject> { return std::make_unique<Door>(place); });