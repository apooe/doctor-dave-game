#pragma once
#include "Board.h"
#include "CatchAbleObject.h"
#include "Bullet.h"
#include <iostream>
#include "CollisionHandler.h"
#include "EndMenu.h"
#include "GameFactoryPattern.h"
#include "StartMenu.h"
#include "DataGame.h"
#include "GameSound.h"
#include "CoronaVirus.h"

using namespace std;

class Controller
{
public:
	// Controller C-tor
	Controller();
	// D-Controller C-tor
	~Controller() = default;

	// main function
	void start();

private:
	// handlle events if user click enter or space
	void keyPressed(sf::RenderWindow& m_window, sf::Event& event);
	// fire from antidote
	void is_firing();
	// Update Data Bar
	void updateGadgets();
	// Draw game Objects
	void drawObjects();
	// set game music and check if its first level
	void preGameStart();
	// restart Level 
	void restartLevel();
	void regenerating();
	// clear game objects
	void clearObj();
	void printEndMenu(bool is_winner);
	// new level
	void generateLevel(string fileLevel);
	void nextLevel();
	// dave, and viruses
	void moveObjects();
	// dave fly with jet
	void daveFlyJet();
	void updateJetTime();
	void VirusAttacks();
	void handleCollision();
	void restart();
	void startMusic();
	sf::Clock m_clock;
	sf::RenderWindow m_window;
	
	DataGame m_dataBar;// game data bar
	unique_ptr<Bullet>m_bullet;//dave or virus bullet
	Direction nextDir = Right;
	unique_ptr<Board>m_board; //unique_ptr for game board
	unique_ptr<DoctorDave> m_DoctorDave; //unique_ptr for dave
	vector<unique_ptr<StaticObject>>m_staticObject;//unique_ptr vector for static objects
	vector<unique_ptr<Virus>>m_viruses;//unique_ptr vector for viruses
	vector<unique_ptr<CatchAbleObject>>m_tools; //unique_ptr vector for CatchAbleObject
	unique_ptr<EndMenu> m_menu; 

	bool freqAttack,
		m_firstLvl = true, // if its first level
		m_isFiring,
		pauseTimer;
	//====================== Game Collisons=============================================================
	void DaveVsStatic(); // dave vs static object
	void StaticVsBullet();// bullet vs static object
	void DaveVsTools(); // dave vs catchableobjects
	void DaveVsVirus(); // dave vs virus
	void VirusVsBullet(); // virus vs bullet
	void DaveVsBullet();// dave vs bullet
	void StaticVsVirusBullet(); // staticObject vs bullet

	//======================Music=============================================================
	GameSound& m_music;




};