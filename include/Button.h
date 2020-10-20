#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include"Utilities.h"
using namespace std;

using sf::RectangleShape;
using sf::Texture;
using sf::Vector2f;
using sf::RenderWindow;
using sf::Text;


class Button
{
public:
	
	Button() = default;//default c-tor
	~Button() = default;
	Button(const Texture& texture, const Vector2f& position, string text, int isLong);	
	void draw(RenderWindow& window); //draw menu btn
	Vector2f getPosition() const; // get position of menu button
	bool contains(const Vector2f& pos) const; //mouse contains or not
	void highlight(); // highlight button
	void unhighlight(); // unhighlight button
private:

	sf::Sprite  m_button; // main menu btn
	Text m_text; // text play exit
	sf::Font m_font;
};