#pragma once
#include "SFML/Graphics.hpp"

using sf::Text;
using sf::Color;

const int TEXT_SIZE = 35;

class DataGame
{
public:

	DataGame() = default;//default c_tor
	DataGame(int lvl, int score, int lives);//c_tor
	~DataGame() = default; // default d_tor
	void regenerate(); // regenerate level datas
	void updateScore(int x); // increase score
	int getScore() const; // get the score
	void decreaseLives(int x); //decrease lives number
	int getLives() const; //get lives number
	float getTimerJet() const; // get timer of the jetpack
	void increaseLevel(int x);//increase the level
	int getLevel()const; // get the level
	void SetdoorMsg();
	void setFirstPos(int width, int height);//set position of datas in dataBar
	void draw(sf::RenderWindow& window); // draw databar
	void timeJet();
	void updateTimer(float deltaTime);// restart jet timer
	void setJetTime();
	void addRemTime(float dt); // add time
	float m_jetTime = 30;
	sf::Clock m_gameTime;

private:
	int m_level, m_score, m_lives;

	sf::Font m_font;

	Text m_levelTxt,
		m_scoreTxt,
		m_livesTxt,
		m_jetTimeTxt,
		m_canPassTxt;


	void setCharSize();
	void setFont();
	void setTextColor();
	void setJetIcon();
	void setText();
	bool m_canPass = false; //catch trophy or not
	sf::Texture m_jet;
	sf::RectangleShape m_jetIcon;


};

