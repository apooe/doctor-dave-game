#include "Button.h"


//c-tor of rectangle  button for main menu
Button::Button(const Texture& texture, const Vector2f& position, string text, int isLong)
{
	
	m_button.setTexture(texture);	 //texture btn for main menu with sprite
	m_button.setPosition(position);
	m_button.setOrigin(m_button.getGlobalBounds().width / 2, m_button.getGlobalBounds().height / 2);	// set origin to the middle
	m_text.setString(text);

	m_font.loadFromFile("pixel.ttf");
	m_text.setFont(m_font);	//font					
	m_text.setCharacterSize(30);//size of letters
	int t = (isLong) ? 50 : 50*2;
	m_text.setPosition(m_button.getPosition().x + t, m_button.getPosition().y + 125);
	m_text.setOrigin(m_button.getGlobalBounds().width / 2, m_button.getGlobalBounds().width / 2);

}

void Button::draw(RenderWindow& window)
{
	window.draw(m_button); //for main menu
	window.draw(m_text); //for main menu

}
bool Button::contains(const Vector2f& pos) const
{
	return (m_button.getGlobalBounds().contains(pos));
}

void Button::highlight()
{
	m_button.setColor(sf::Color::Yellow);
	m_text.setFillColor(sf::Color::White);
	m_text.setOutlineThickness(3);
	m_text.setOutlineColor(sf::Color::Black);
	m_text.setCharacterSize(30);
}

void Button::unhighlight()
{
	m_button.setColor(sf::Color::Transparent);
	m_text.setColor(sf::Color::White);
	m_text.setOutlineThickness(0);
	m_text.setCharacterSize(25);
}

Vector2f Button::getPosition() const
{
	return m_button.getPosition();
}
