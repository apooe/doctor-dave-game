#include "Controller.h"
#include <time.h>

Controller::Controller() : m_dataBar(1, 0, LIVES), m_isFiring(false), pauseTimer(true),
m_menu(std::make_unique<EndMenu>()), m_board(std::make_unique<Board>()), freqAttack(false),  m_music(GameSound::getInstance())
{}
void Controller::start()
{
	preGameStart();
	sf::Event event;
	
	m_music.playGameBackgroud();
	while (m_window.isOpen())
	{
		m_window.clear();
		keyPressed(m_window, event);
		VirusAttacks();
		updateGadgets();

		if (m_isFiring)	is_firing();

		if (!m_DoctorDave->getLife()){
			handleCollision();
			moveObjects();
		}

		else if (m_DoctorDave->restart())
			restart();
		
		if (m_DoctorDave->getWinner()) {
			
			nextLevel();
			m_DoctorDave->setWinner(false);
			m_music.stopSuccess();
		}

		m_music.playGameBackgroud();
		drawObjects();
		m_window.display();
		
	}
	
}

void Controller::drawObjects()
{
	if (m_bullet) {	
		m_bullet->draw(m_window);
		m_bullet->setDir(m_DoctorDave->getDirDave());
	}

	for (auto& i : m_staticObject) 
		i->ObjectAnimtion(m_window);

	m_DoctorDave->ObjectAnimtion(m_window);

	for (auto& i : m_tools)
		i->draw(m_window);

	for (auto& virus : m_viruses) {
		virus->ObjectAnimtion(m_window);
		virus->drawBullet(m_window);
	}

	m_dataBar.draw(m_window);
}

void Controller::DaveVsVirus()
{
	for (auto& i : m_viruses) {
		if (i && checkIfCollision(i->getRect(), m_DoctorDave->getRect())) {
			m_music.stopPlayerKilled();
			m_music.playPlayerKilled();
			setCollision(*m_DoctorDave, *i);
			return;
		}
	}
}
	
void Controller::StaticVsBullet()
{
	for (const auto& statObj : m_staticObject)
	{
		if (m_bullet && checkIfCollision(statObj->getRect(), m_bullet->getRect())) {
			setCollision(*m_bullet, *statObj);
			m_isFiring = false;
			if (m_bullet->getLife()) {
				m_bullet.reset();	
			}
		}
	}
}


void Controller::updateGadgets()
{
	m_DoctorDave->setDirection();
	if (nextDir != m_DoctorDave->getDirDave()) 
		m_bullet.reset();
	
	nextDir = m_DoctorDave->getDirDave();

	if (m_DoctorDave->getAction()->getFly()){
		m_dataBar.setJetTime();
		if (m_dataBar.getTimerJet() <= 0)
			m_DoctorDave->getAction()->setFly(false);	
	}

	if (m_DoctorDave->getTrophy())	m_dataBar.SetdoorMsg();
	m_DoctorDave->setAxe(0, false);
	m_DoctorDave->setAxe(1, false);

}

void Controller::keyPressed(sf::RenderWindow& m_window, sf::Event& event)
{
	if (m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
			case sf::Keyboard::Space:
				if (!m_DoctorDave->getAntidote())
					break;
				m_music.stopAmmo();
				m_music.playAmmo();
				m_isFiring = true;
				break;

			case sf::Keyboard::Enter:
				if (!m_DoctorDave->getJet())
					break;
				daveFlyJet();
				break;
			}
			break;
		}
	}
	
	

}

void Controller::DaveVsStatic()
{
	
	if (m_DoctorDave->getAction()->getMove().y == 0 && !m_DoctorDave->getAction()->getFly())
			m_DoctorDave->getAction()->getMove().y = 1.1; //jump

	for (const auto& staticObj : m_staticObject){
		if (checkIfCollision(staticObj->getRect(), m_DoctorDave->getRect())) 
			setCollision(*m_DoctorDave, *staticObj);	
		
	}
}

void Controller::VirusVsBullet()
{

	int i = -1;
	for (auto &virus : m_viruses){
		i++;
		if (m_bullet && checkIfCollision(virus->getRect(), m_bullet->getRect())){
			setCollision(*virus, *m_bullet);
			if (virus->getLife()) {
				m_music.stopEnemyKiller();
				m_music.playEnemyKilled();
			m_viruses.erase(m_viruses.begin() + i);
			}
				
			m_bullet.reset();
			return;	
		}
		
		
	}
}

void Controller::DaveVsBullet()
{
	for( auto & v : m_viruses)
	{
		for(auto & b : v->getBulletVirus()){
			if (b && checkIfCollision(b->getRect(), m_DoctorDave->getRect())) {
				m_music.stopPlayerKilled();
				m_music.playPlayerKilled();
				setCollision(*m_DoctorDave, *b);
				return;
			}
		}
	}
}

void Controller::moveObjects()
{
	m_DoctorDave->move();
	if (m_bullet) {
		m_bullet->move();
	}
	m_DoctorDave->getPosition().x;
	for (auto& virus : m_viruses) {
		virus->move(m_DoctorDave->getObjSprite().getPosition());	
		virus->moveBullet(m_DoctorDave->getPosition());
	}

}
void Controller::daveFlyJet()
{
	if (m_DoctorDave->getAction()->getFly()) {
		if (!pauseTimer)
			m_clock.restart().asSeconds();
		m_music.stopFly();
		pauseTimer = true;
		m_DoctorDave->getAction()->setFly(false);

	}
	else {
		if (pauseTimer) {
			m_music.stopFly();
			m_dataBar.addRemTime(m_clock.getElapsedTime().asSeconds());
		}
		m_music.playFly();
		pauseTimer = false;
		m_DoctorDave->getAction()->setFly(true);
			
	}
}

void Controller::updateJetTime()
{
	pauseTimer = true;
	m_clock.restart();
}

void Controller::VirusAttacks()
{
	if (!freqAttack) {
		for (auto& i : m_viruses) {
			if (rand() % 15 > 1) continue;
			i->setBullet();		
		}
		freqAttack = true;
	}
	//increase frequency of bullets from viruses
	if (rand() % 650 <= m_dataBar.getLevel())
		freqAttack = false;
}

void Controller::handleCollision()
{
	DaveVsStatic();
	DaveVsTools();
	VirusVsBullet();
	StaticVsBullet();
	StaticVsVirusBullet();
	DaveVsBullet();
	DaveVsVirus();
}

void Controller::restart()
{
	m_music.stopFly();
	restartLevel();
	m_dataBar.decreaseLives(m_dataBar.getLives() - 1);
	if (m_dataBar.getLives() == 0) {
		m_music.stopFly();
		m_music.stopGameBackgroud();
		m_music.playGameOver();
		printEndMenu(false);
	}
}

void Controller::startMusic()
{
	m_music.stopFly();
	m_music.stopGameBackgroud();
	m_music.playSuccess();
}

void Controller::StaticVsVirusBullet()
{
	
	for (auto& item : m_staticObject) {
		for (auto& v : m_viruses){
			int i = -1;
			for (auto& b : v->getBulletVirus()) {
				++i;
				if (b && checkIfCollision(b->getRect(), item->getRect())) {
					setCollision(*b, *item);
					if (b->getLife() ) // GameTile/rock - bullet
						v->getBulletVirus().erase(v->getBulletVirus().begin() + i);
					
					return;
				}
			}
		}
	}
}


void Controller::DaveVsTools()
{
	bool col = false;
	
	for (size_t i = 0; i < m_tools.size(); i++){
		if (checkIfCollision(m_tools[i]->getRect(), m_DoctorDave->getRect())) {
			setCollision(*m_DoctorDave, *m_tools[i]);
			m_tools.erase(m_tools.begin() + i);
			m_music.stopIntro();
			m_music.playIntro();
			
		}
	}


}


void Controller::preGameStart()
{
	if (m_firstLvl){
		
		unique_ptr<StartMenu> m_menu = make_unique<StartMenu>();
		std::cout << m_menu->getSound();
		if (!m_menu->getSound()) { m_music.playGameOver(); }
		m_menu->open();


		
		   
		m_firstLvl = false;
	}
	regenerating();

}

void Controller::regenerating()
{
	m_dataBar.regenerate();
	clearObj();
	generateLevel("Stage"+to_string(m_dataBar.getLevel())+".txt");
	drawObjects();
	m_window.display();
	
}

void Controller::clearObj()
{
	m_staticObject.clear();
	m_DoctorDave.reset();
	m_viruses.clear();
	m_tools.clear();
}

void Controller::printEndMenu(bool is_winner)
{
	m_menu->setBestScore(is_winner, m_dataBar.getScore());
	m_menu->open();
	if (m_menu->startGame())
		preGameStart();
	m_music.stopGameOver();
	m_music.playGameBackgroud();
}


void Controller::generateLevel(string fileLevel)
{
	if (!m_board->ReadLevel(fileLevel, m_staticObject, m_DoctorDave, m_tools, m_viruses))
		printEndMenu(true);

	m_window.create(m_board->getSize(), 0u, sf::Style::Default);
	m_DoctorDave->setDatas(&m_dataBar);
	m_dataBar.setFirstPos(m_board->getSize().width, m_board->getSize().height);	
}

void Controller::nextLevel()
{
	startMusic();
	m_dataBar.increaseLevel(m_dataBar.getLevel() + 1);
	clearObj();
	pauseTimer = false;

	generateLevel("stage"+to_string(m_dataBar.getLevel())+".txt");
	drawObjects();

	m_window.display();

	updateJetTime();
	m_dataBar.updateTimer(60 /m_dataBar.getLevel());
}


void Controller::is_firing()
{
	m_bullet = make_unique<Bullet>(sf::Vector2f(10, 5));
	m_bullet->setFirstPos(sf::Vector2f(m_DoctorDave->getPosition()));
	m_isFiring = false;
}

void Controller::restartLevel()
{
	m_DoctorDave->setsetLife(false);
	m_DoctorDave->setFirstPos();

	for (auto& v : m_viruses) 
		v->setFirstPos();

	m_DoctorDave->getObjSprite().move(OBJECT_SIZE / 2, OBJECT_SIZE / 2);
	updateJetTime();

	m_dataBar.addRemTime(m_clock.getElapsedTime().asSeconds());
	
}

