#include "FluVirus.h"
#include "GameFactoryPattern.h"
#include "LoadFromFile.h"
#include <iostream>

FluVirus::FluVirus(sf::Vector2f & pos)
	:Virus(pos), m_fluDirction(FLU_DIR)
{
	m_objectTexture = (LoadFromFile::getInstance().getTexture(o_regVirus));
    setFlu();
}

void FluVirus::move(sf::Vector2f )
{	
	Clock m_gameClock;
	float dt = m_gameClock.restart().asSeconds();
	if ((m_clock.getElapsedTime().asSeconds()) == TIMER)
	{
		int direction = rand() % DIR;//choose direction
		switch (direction) {
		case 0:
			m_fluDirction = sf::Vector2f(0, -1.f * dt);
			break;
		case 1:
			m_fluDirction = sf::Vector2f(0, 1.f * dt);
			break;
		case 2:
			m_fluDirction = sf::Vector2f(-1.f * dt, 0);
			break;
		case 3:
			m_fluDirction = sf::Vector2f(1.f * dt, 0);
			break;
		default:
			m_fluDirction = sf::Vector2f(0, 0);
			break;
		}
		m_clock.restart();
	}
	else
		fluMovement();

	
}

//move bullet of viruses in left direction
void FluVirus::moveBullet(sf::Vector2f direction)
{
	for (auto& i : m_bulletVirus) {
		i->setDir(Left);
		i->moveBullet();
	}
}
static bool m_instance = GameFactoryPattern<Virus>::registerit(Textures::T_RegVirus,
	[](sf::Vector2f& place) -> std::unique_ptr<Virus> { return std::make_unique<FluVirus>(place); });

void FluVirus::setFlu()
{
	m_objectShape.setTexture(*m_objectTexture);
	m_objectShape.setOrigin(sf::Vector2f{ OBJECT_SIZE / 2, OBJECT_SIZE / 2 });
	m_currentVirusLocation = sf::Vector2f(m_objectShape.getPosition().x, m_objectShape.getPosition().y);
}

void FluVirus::fluMovement()
{
	static int dirction = 0;
	if (dirction >= DIR) {

		sf::Vector2f currPos = m_objectShape.getPosition();
		if (currPos.y + m_fluDirction.y < (m_currentVirusLocation.y - 40) || currPos.y + m_fluDirction.y >(m_currentVirusLocation.y + 40))
			m_fluDirction.y = -m_fluDirction.y;
		m_objectShape.setPosition(sf::Vector2f(currPos.x + m_fluDirction.x, currPos.y + m_fluDirction.y));
		dirction = 0;
	}
	dirction++;
}



