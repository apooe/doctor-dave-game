#include "ObjectAnim.h"

const int FARME = 3;


void ObjectAnim::makeDaveAnimation(sf::RenderWindow & window, sf::Sprite & nurseSize, int size)
{

	sf::IntRect rectSourceSprite(size, 0, size, size);

	sf::Clock clock;

		if (clock.getElapsedTime().asSeconds() > 1.0f) {
			if (rectSourceSprite.left == 600)
				rectSourceSprite.left = 0;
			else
				rectSourceSprite.left += 300;

			nurseSize.setTextureRect(rectSourceSprite);
			clock.restart();
		}
	

}

void ObjectAnim::makeObjectsAnimation(float seconds,sf::RenderWindow& window, sf::Sprite& object, int objectSize) {
	 static int farme = 0;
if (m_timer.getElapsedTime().asSeconds()  >= sf::seconds(seconds).asSeconds())
{
	farme++;
	m_timer.restart();
}
sf::IntRect rectSourceSprite(objectSize *(farme / FARME), 0, objectSize, objectSize);
object.setTextureRect(rectSourceSprite);
window.draw(object);
if (farme / FARME >= FARME) 
   farme = 0;
}