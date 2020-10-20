#include "CoronaVirus.h"
#include "GameFactoryPattern.h"
#include "LoadFromFile.h"
const int DT = 50;


CoronaVirus::CoronaVirus(sf::Vector2f &dir):Virus(dir), m_coronaDirction(CORONA_DIR) {m_objectTexture = (LoadFromFile::getInstance().getTexture(o_coronaVirus));
	
	setCorona();
}
void CoronaVirus::move(sf::Vector2f d)
{
	//to move vertically
	Clock m_gameClock;//to move
	float dt = m_gameClock.restart().asSeconds();
	if ((m_clock.getElapsedTime().asSeconds()) == TIMER){
		int direction = rand() % DIR;
		switch (direction) {
		case 0:
			m_coronaDirction = sf::Vector2f(0, -1.f * dt);
			break;
		case 1:
			m_coronaDirction = sf::Vector2f(0, 1.f * dt);
			break;
		case 2:
			m_coronaDirction = sf::Vector2f(-1.f * dt, 0);
			break;
		case 3:
			m_coronaDirction = sf::Vector2f(1.f * dt, 0);
			break;
		default:
			m_coronaDirction = sf::Vector2f(0, 0);
			break;
		}
		m_clock.restart();
	}
	else
		coronaMovement();
	
		
}

bool CoronaVirus::m_instance = GameFactoryPattern<Virus>::registerit(Textures::T_CoronaVirus,
	[](sf::Vector2f& place) -> std::unique_ptr<Virus> { return std::make_unique<CoronaVirus>(place); });

void CoronaVirus::moveBullet( sf::Vector2f direction)
{
	//set direction of the bullet in function of dave and move shot
	Direction d = Right;
	if (direction.x > m_objectShape.getPosition().x)
		d = Left;
	for (auto& i : m_bulletVirus) {
		if (!i->getShot()) 
			setBullet(*i, d); // set direction 
		else 
			i->moveBullet(); //shoot
		
	}
		
}
//set direction of bullet
void CoronaVirus::setBullet(Bullet & bullet, Direction dir)
{
	//inverse of dave direction in function of x position
	Direction d = (dir == Right) ? Left : Right;
	bullet.setDir(d);
	bullet.setShot(true);
}

void CoronaVirus::setCorona() //set texture on sprite
{
	m_objectShape.setTexture(*m_objectTexture);
	m_objectShape.setOrigin(sf::Vector2f{ OBJECT_SIZE / 2, OBJECT_SIZE / 2 });
	m_coronaPositon = sf::Vector2f(m_objectShape.getPosition().x, m_objectShape.getPosition().y);
}

void CoronaVirus::coronaMovement() // set move of virus vertically
{
	static int direction = 0;
	if (direction >= DIR) {

		sf::Vector2f currPos = m_objectShape.getPosition();
		if (currPos.x + m_coronaDirction.x < (m_coronaPositon.x - 40) || currPos.x + m_coronaDirction.x >(m_coronaPositon.x + 40))
			m_coronaDirction.x = -m_coronaDirction.x;
		m_objectShape.setPosition(sf::Vector2f(currPos.x + m_coronaDirction.x, currPos.y + m_coronaDirction.y));
		direction = 0;
	}
	direction++;

}



