#include "Diamond.h"
#include "GameFactoryPattern.h"


Diamond::Diamond(sf::Vector2f &pos) :CatchAbleObject(pos){m_objectTexture = (LoadFromFile::getInstance().getTexture(o_diamond));
	setDiamond();
}
static bool m_instance = GameFactoryPattern<CatchAbleObject>::registerit(Textures::T_diamond,
	[](sf::Vector2f &place) -> std::unique_ptr<CatchAbleObject> { return std::make_unique<Diamond>(place); });

void Diamond::setDiamond() {
	m_cell.setTexture(*m_objectTexture);
	m_cell.setOrigin(sf::Vector2f{ 50 / 2, 50 / 2 });
	m_cell.move(50 / 2, 50 / 2);
}