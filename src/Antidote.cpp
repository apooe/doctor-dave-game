#include "Antidote.h"
#include "GameFactoryPattern.h"


Antidote::Antidote(sf::Vector2f &pos) : CatchAbleObject(pos){ m_objectTexture = (LoadFromFile::getInstance().getTexture(o_Antidote));
	setAntidote(pos);
}

bool Antidote::m_instance = GameFactoryPattern<CatchAbleObject>::registerit(Textures::T_Antidote,
	[](sf::Vector2f &place) -> std::unique_ptr<CatchAbleObject> { return std::make_unique<Antidote>(place); });

void Antidote::setAntidote(sf::Vector2f& Position)
{
	m_cell.setTexture(*m_objectTexture);
	m_cell.setOrigin(sf::Vector2f{ OBJECT_CELL_SIZE / 2, OBJECT_CELL_SIZE / 2 });
	m_cell.move(OBJECT_CELL_SIZE / 2, OBJECT_CELL_SIZE / 2);
}