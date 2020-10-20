#include "DoctorDave.h"
#include "LoadFromFile.h"

DoctorDave::DoctorDave(sf::Vector2f& pos) : DynamicObject(pos), m_win(false)
							,m_haveAntidote(false), m_haveJet(false), m_haveTrophy(false)
{
	m_objectTexture = LoadFromFile::getInstance().getTexture(o_doctor_dave);
	m_objectShape.setTexture(*m_objectTexture);
	m_objectShape.setOrigin(sf::Vector2f{ OBJECT_SIZE /2, OBJECT_SIZE /2 });
	m_objectShape.move(OBJECT_SIZE/2,OBJECT_SIZE/2);
	m_action = std::move(make_unique<DaveMotion>(*this));

	m_Jet = LoadFromFile::getInstance().getTexture(o_docDave_Jet);
}

void DoctorDave::ObjectAnimtion(sf::RenderWindow &window)
{
	if (setFireOnObject(window)) //if dave dead
		return;
	else if (m_action->getFly()) {//if dave fly
		m_objectShape.setTexture(*m_Jet);
		m_ObjectAnim.makeObjectsAnimation(0.8f,window, m_objectShape, OBJECT_SIZE - 8);
	}
		
	else //regular dave 
		m_objectShape.setTexture(*m_objectTexture);

	window.draw(m_objectShape);
}

bool DoctorDave::restart() const
{
	return m_clock.getElapsedTime().asSeconds() >= 1; //dead time
}

void DoctorDave::setDatas(DataGame * data)
{
	m_dataBar = data;
}
void DoctorDave::setsetLife(bool t)
{
	if (!t) 
		m_DynamicObjectlife = t;

	else { //if dave dead
		m_DynamicObjectlife = t;
		m_clock.restart();
	}
}
sf::FloatRect DoctorDave::getRect()
{
	return m_objectShape.getGlobalBounds();
}

void DoctorDave::addScore()
{
	m_dataBar->updateScore(m_dataBar->getScore() + 10); //update the score
}

Direction DoctorDave::getDirDave() const 
{
	return m_action->getDir(); // get direction of dave
}

void DoctorDave::setFly()
{
	m_action->setFly(false); // cant fly
}

bool DoctorDave::setFireOnObject(sf::RenderWindow& window)
{
	if (getLife()) { // if dave getLife 
		m_objectShape.setTexture(*m_inFire);
		m_ObjectAnim.makeObjectsAnimation(0.5f, window, m_objectShape, OBJECT_SIZE - 8);
		return true;
	}
	return false;
}

void DoctorDave::setDirection()
{
	m_action->setDirDave(); //set direction of the movement
}

void DoctorDave::move(sf::Vector2f d)
{
	float speed = 0.5f; //speed of dave
	m_action->daveAction(*this, speed);	//dave move
}



