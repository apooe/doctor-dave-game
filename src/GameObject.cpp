#include "GameObject.h"


GameObject::GameObject() {}

GameObject::~GameObject() {}

void GameObject::ObjectAnimtion(sf::RenderWindow & window)
{
	m_objectShape.setTexture(*m_objectTexture);
	window.draw(m_objectShape);
}


sf::FloatRect GameObject::getRect()
{
	return m_objectShape.getGlobalBounds();
}

sf::Sprite& GameObject::getObjSprite()
{
	return m_objectShape;
}

void GameObject::setFirstPos()
{
	m_objectShape.setPosition({ m_objectPos.y * 60, m_objectPos.x * 60 });
}


sf::Vector2f GameObject::getPosition() const
{
	return m_objectShape.getPosition();
}

void GameObject::setPosition(const sf::Vector2f& Location)
{
	m_objectPos = Location;
}
