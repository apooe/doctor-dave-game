#pragma once
#include "MainMenu.h"

using sf::Font;
class EndMenu : public MainMenu
{
public:
	EndMenu() = default;
	~EndMenu() = default;
	void open();//open menu
	void draw(); //draw menu
	void setBestScore(bool win, int score); //set the best score
	

	//-----------------------------private----------------------------
private:
	
	bool is_winner; //if player won game
	int m_bestScore ; //best score
	int m_score; //score

	sf::Text setMsg(string m, Vector2f pos, const Font& font); //set msg on window



};

