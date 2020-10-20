#include "..\include\MainMenu.h"
#include "MainMenu.h"
#include <iostream>

using sf::VideoMode;
using std::make_unique;
using sf::Vector2f;
using sf::Event;
using sf::Keyboard;


//default d-tor
MainMenu::MainMenu() :  m_startGame(false){

	font.loadFromFile("pixel.ttf");
}

MainMenu::~MainMenu() {}

void MainMenu::handleEvents()
{
	Event event;
	while (m_window.pollEvent(event)) {
		
		switch (event.type) {

		case Event::Closed:
			m_window.close();
			break;

		case Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Button::Left) {

				
				const Vector2f mousePos = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
				//start the game
				if (m_buttons[0]->contains(mousePos)) {
					if(m_buttons.size() > 2)
						printCmds();
					m_startGame = true;
					m_window.close();

				}
				else if (m_buttons[1]->contains(mousePos)) 
				{
					if (checkClosure()) {
						m_window.close();
						exit(EXIT_FAILURE);
					}
				}
				if (m_buttons.size() > 2 && m_buttons[2]->contains(mousePos)) { menu.stop(); }
			}
			break;

		case Event::MouseMoved:
			const Vector2f mousePos = m_window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y });
			show(mousePos);

		}
	}

}

void MainMenu::runMenu()
{
	while (m_window.isOpen())
	{
		draw(); // draw buttons and back
		handleEvents();

	}
}

bool MainMenu::startGame() const
{
	return m_startGame;
}

void MainMenu::show(const Vector2f mousePos)
{
	sf::Cursor hand, arrow;
	hand.loadFromSystem(sf::Cursor::Hand);
	arrow.loadFromSystem(sf::Cursor::Arrow);

	for (auto& i : m_buttons) {
		if (i->contains(mousePos)) {
			i->highlight();
			m_window.setMouseCursor(hand);

			break;
		}

		else {
			i->unhighlight();
			m_window.setMouseCursor(arrow);
		}
	}
}

RectangleShape MainMenu::setWindow(int w, int h)
{
	RectangleShape windowMsg;
	windowMsg.setSize(sf::Vector2f(w, h));
	windowMsg.setFillColor(sf::Color::Black);
	windowMsg.setOutlineThickness(5);
	windowMsg.setOutlineColor(sf::Color::White);
	windowMsg.setPosition(m_window.getView().getCenter());
	windowMsg.setOrigin(windowMsg.getGlobalBounds().width / 2, windowMsg.getGlobalBounds().height / 2);
	return windowMsg;
}

void MainMenu::setTextQ()
{
	m_question = Text("Are you sure ?", font, 35.0f);
	m_question.setPosition(320, 200);
	m_yes = Text("yes", font, 35.0f);
	m_yes.setPosition(370, 320);
	m_no = Text("no ", font, 35.0f);
	m_no.setPosition(550, 320);
}

bool MainMenu::checkClosure()
{
	setTextQ();
	m_window.draw(setWindow(450, 350));
	m_window.draw(m_question);
	m_window.draw(m_yes); 
	m_window.draw(m_no);
	
	m_window.display();

	return areYouSure();
}

bool MainMenu::areYouSure()
{
	while (m_window.isOpen()) {
		Event event;
		while (m_window.pollEvent(event)) {
			switch (event.type) {
			case Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Button::Left) {

					const Vector2f mousePos = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
					if (m_yes.getGlobalBounds().contains(mousePos))
						return true;

					else if (m_no.getGlobalBounds().contains(mousePos)) { m_window.close(); }
				}
				break;

			}
		}
	}
	return false;
}

RectangleShape MainMenu::setCommands()
{
	string str =
		"  It's your first time ?! Here the different COMMANDS : \n\n\n"
		"  1. ARROWS: Use the arrows on your\n    keyboard to move.\n\n"
		"  2. ENTER: Activate the jetpack in\n    your possession.\n\n"
		"  3. SPACE: Shoot and eliminate viruses.\n\n\n"
		"  Press enter to continue...";

	m_commands = Text(str, font, 20.0f);
	m_commands.setPosition(m_question.getPosition().x + 100, m_question.getPosition().y + 150);
	return setWindow(WIDTH - 100, HEIGHT - 100);
}

void MainMenu::printCmds()
{
	
	m_window.draw(setCommands());
	m_window.draw(m_commands);
	m_window.display();

	Event event;
	while (m_window.waitEvent(event))
		if (event.type == Event::KeyReleased) 
			if (event.key.code == Keyboard::Enter)
				break;
}









