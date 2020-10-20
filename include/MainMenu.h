#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include "Button.h"
#include "Board.h"
using std::unique_ptr;
using sf::RenderWindow;
using sf::RectangleShape;

using std::vector;
class MainMenu
{
public:
	//c-tor
	MainMenu();
	//d-tor
	~MainMenu();
	//open the menu window

	virtual void draw() = 0; // draw menu
	void handleEvents();
	void runMenu();
	virtual void open() = 0;
	bool startGame() const;

	void show(const Vector2f mousePos);

	bool checkClosure();
protected:

	sf::Music menu;
	vector<unique_ptr< Button>> m_buttons;
	RenderWindow m_window; 	//window for menu
	RectangleShape m_background;
	bool m_startGame;
	Text m_yes, m_no, m_question, m_commands;
	sf::Font font;
	bool m_gameSound = true;
	void printCmds();
	RectangleShape setWindow(int w, int h);
	void setTextQ();
	
	bool areYouSure();
	RectangleShape setCommands();
	
	

	
};

