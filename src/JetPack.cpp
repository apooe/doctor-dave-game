#include "JetPack.h"



JetPack::JetPack(sf::Vector2f &Position) : CatchAbleObject(Position){m_objectTexture = (LoadFromFile::getInstance().getTexture(o_jetPack));
	setJetAnim(Position);
}

void JetPack::setJetAnim(sf::Vector2f& Position)
{
	m_cell.setTexture(*m_objectTexture); 
	m_cell.setOrigin(sf::Vector2f{ 50 / 2, 50 / 2 });
	m_cell.move(50 / 2, 50 / 2);
}



bool Jet = GameFactoryPattern<CatchAbleObject>::registerit(Textures::T_jetPack,
	[](sf::Vector2f& Position) -> std::unique_ptr<CatchAbleObject>
	{ return std::make_unique<JetPack>(Position); });



