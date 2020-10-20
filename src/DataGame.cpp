#include "DataGame.h"
#include <iostream>     
#include <iomanip>  
#include <algorithm> 


DataGame::DataGame(int level, int score, int lives)
	: m_level(level), m_score(score), m_lives(lives), m_canPass(false)
{
	setFont();
	setCharSize();
	setTextColor();
	setJetIcon();

}
//regenerate all datas
void DataGame::regenerate()
{

	m_level = 1;
	m_score = 0;
	m_lives = 3;
	m_jetTime = 40;
	m_canPass = false;

}

void DataGame::updateScore(int score)
{
	m_score = score;
}

int DataGame::getScore() const
{
	return m_score;
}

void DataGame::decreaseLives(int live)
{
	m_lives = live;
}

int DataGame::getLives() const
{
	return m_lives;
}

float DataGame::getTimerJet() const
{
	return m_jetTime;
}

void DataGame::increaseLevel(int level)
{
	m_level = level;
	m_canPass = false;
}

int DataGame::getLevel() const
{
	return m_level;
}

void DataGame::SetdoorMsg()
{
	m_canPass = true; // if has trophy
}


void DataGame::setFirstPos(int width, int height)
{

	m_levelTxt.setPosition(10, 10);
	m_scoreTxt.setPosition(360, 10);
	m_livesTxt.setPosition(700, 10);
	m_jetTimeTxt.setPosition(1010, 10);
	m_canPassTxt.setPosition(400, 620);

}



void DataGame::draw(sf::RenderWindow& window)
{

	setText();
	window.draw(m_jetIcon);
	if (m_jetTime >= 0)

		window.draw(m_jetTimeTxt);

	window.draw(m_levelTxt);

	window.draw(m_livesTxt);

	window.draw(m_scoreTxt);

	if (m_canPass)
		window.draw(m_canPassTxt);
}

//set format of jet text
void DataGame::timeJet()
{
	int seconds = static_cast<int>(m_jetTime);

	m_jetTimeTxt.setString(+"00:" + std::to_string(seconds));

	if (m_jetTime > 10)
		m_jetTimeTxt.setColor(Color::White);
	else {
		m_jetTimeTxt.setString(+"00:0" + std::to_string(seconds));
		m_jetTimeTxt.setColor(Color::Red);
	}


}

void DataGame::updateTimer(float deltaTime)
{
	m_gameTime.restart();
	m_jetTime = deltaTime;
}



void DataGame::setCharSize()
{
	m_levelTxt.setCharacterSize(TEXT_SIZE);
	m_livesTxt.setCharacterSize(TEXT_SIZE);
	m_scoreTxt.setCharacterSize(TEXT_SIZE);
	m_canPassTxt.setCharacterSize(TEXT_SIZE - 10);
	m_jetTimeTxt.setCharacterSize(TEXT_SIZE - 5);
}

void DataGame::setFont()
{
	m_font.loadFromFile("pixel.ttf");
	m_levelTxt.setFont(m_font);
	m_scoreTxt.setFont(m_font);
	m_livesTxt.setFont(m_font);
	m_jetTimeTxt.setFont(m_font);
	m_canPassTxt.setFont(m_font);

}

void DataGame::setTextColor()
{
	m_levelTxt.setFillColor(Color::White);
	m_scoreTxt.setFillColor(Color::Yellow);
	m_jetTimeTxt.setFillColor(Color::Cyan);
	m_livesTxt.setFillColor(Color::Magenta);
	m_canPassTxt.setFillColor(Color::White);

}

void DataGame::setJetIcon()
{

	m_jet.loadFromFile("jet.png");
	m_jetIcon.setTexture(&m_jet);
	m_jetIcon.setSize({ 50, 50 });
	m_jetIcon.setPosition(980, 35);
	m_jetIcon.setOrigin(m_jetIcon.getGlobalBounds().width / 2,
		m_jetIcon.getGlobalBounds().height / 2);
}

void DataGame::setText()
{
	timeJet();
	m_levelTxt.setString("level: " + std::to_string(m_level));
	m_scoreTxt.setString("score: " + std::to_string(m_score));
	m_livesTxt.setString("life: " + std::to_string(m_lives));
	m_canPassTxt.setString("GO TO THE DOOR!!!");

}

void DataGame::setJetTime() //update jet time
{
	float dt = m_gameTime.restart().asSeconds();
	m_jetTime -= dt;
}

void DataGame::addRemTime(float dt) // add the time without jet
{
	m_jetTime += dt;
}



