#pragma once
#include"MainMenu.h"

using sf::Event;
using sf::VideoMode;
using std::make_unique;
using sf::Vector2f;


class StartMenu : public MainMenu
{
public:
	StartMenu();
	~StartMenu() = default;
	void open();
	bool getSound() const;
	
	void draw();
	

};

