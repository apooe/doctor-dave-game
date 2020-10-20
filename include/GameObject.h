#pragma once
#include "DaveMotion.h"
#include "ObjectAnim.h"

const float DEFAULT = 0.f;

const sf::Vector2f Def = { 0.f, 0.f };
using sf::Sprite;
using sf::Texture;


class GameObject
{
public:
	GameObject();
	GameObject(sf::Vector2f& Location) : m_objectTexture(nullptr), m_objectPos(Location)
	{
		m_objectShape.setPosition({ m_objectPos.y * OBJECT_SIZE, m_objectPos.x * OBJECT_SIZE });
	};
	virtual ~GameObject() = 0;
	sf::Vector2f getPosition() const; //get position of the object
	void setPosition(const sf::Vector2f& Location); //set position of the object
	virtual void ObjectAnimtion(sf::RenderWindow& window);//virtual function draw
	virtual void move(sf::Vector2f = { DEFAULT, DEFAULT }) {}; //virtual function move 
	virtual sf::FloatRect getRect(); //get bounds of the object
	sf::Sprite& getObjSprite(); //get sprite of the object
	void setFirstPos(); //set firt position of object

protected:

	Sprite m_objectShape; 
	Texture *m_objectTexture; 
	ObjectAnim m_ObjectAnim; 
	

private:
	sf::Vector2f m_objectPos;


};

