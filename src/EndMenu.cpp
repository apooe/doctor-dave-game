#include "EndMenu.h"
#include "Controller.h"


void EndMenu::open()
{
	sf::Texture m_back, btn;
	m_buttons.clear();
	m_window.create(VideoMode(WIDTH, HEIGHT), "Doctor Dave", sf::Style::None);
	m_background.setSize({ WIDTH, HEIGHT });

	if (is_winner) m_back.loadFromFile("win.jpg");  //win texture
	else m_back.loadFromFile("lose.jpg");//gameover texture

	m_background.setTexture(&m_back);

	btn.loadFromFile("button.png"); 
	m_buttons.push_back((make_unique<Button>(btn, Vector2f(500, 480), "try again", 1))); 
	m_buttons.push_back((make_unique<Button>(btn, Vector2f(500, 550), "exit", 0)));

	runMenu(); //draw menu and handle event
}
void EndMenu::draw()
{
	m_window.draw(m_background);

	m_window.draw(setMsg("DOCTOR DAVE SCORE: " + to_string(m_score),
		Vector2f(500, 380), font));

	m_window.draw(setMsg("YOUR BEST SCORE IS: " + to_string(m_bestScore),
		Vector2f(500, 100), font));

	for (auto& i : m_buttons)
		i->draw(m_window);

	m_window.display();

}
//compare and set best score
void EndMenu::setBestScore(bool win, int score)
{
	m_score = score;
	if (win)
		m_bestScore = (m_score < m_bestScore) ? m_bestScore : m_score;
	is_winner = win;
}

//set msg window
sf::Text EndMenu::setMsg(string m, Vector2f pos, const Font& font)
{
	Text msg(m, font, 35.0f);
	msg.setPosition(pos);
	msg.setFillColor(sf::Color::White);
	msg.setCharacterSize(40);
	msg.setOrigin(msg.getGlobalBounds().width / 2, msg.getGlobalBounds().height / 2);
	return msg;
}

