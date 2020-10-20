#include "StartMenu.h"
#include "Controller.h"


StartMenu::StartMenu()
{

}

void StartMenu::open()
{
	//create window
	m_window.create(VideoMode(WIDTH, HEIGHT), "Doctor Dave", sf::Style::None);
	m_background.setSize(sf::Vector2f{ WIDTH, HEIGHT });

	sf::Texture back, btn;
	back.loadFromFile("background.png");
	btn.loadFromFile("button.png");
	if (!menu.openFromFile("MenuMusic.wav"))
		throw(FileNotFoundException("game wav"));
	menu.setVolume(60);

	menu.setLoop(true);

	menu.play();

	m_background.setTexture(&back);
	m_buttons.emplace_back((make_unique<Button>(btn, Vector2f(500, 350), "play", 0)));
	m_buttons.emplace_back((make_unique<Button>(btn, Vector2f(500, 430), "quit", 0)));
	m_buttons.emplace_back((make_unique<Button>(btn, Vector2f(500, 515), "sound off", 1)));
	runMenu();
}

bool StartMenu::getSound() const
{
	return m_gameSound;
}


void StartMenu::draw()
{
	m_window.clear();

	//draw buttons and back
	m_window.draw(m_background);

	for (auto& i : m_buttons)
		i->draw(m_window);

	m_window.display();
}






