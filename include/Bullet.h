#pragma once
#include"GameObject.H"

#include <SFML/Graphics.hpp>

class Bullet : public DynamicObject {
public:
	// set Bullet
    Bullet(sf::Vector2f size) {
        bullet.setSize(size);
        bullet.setFillColor(sf::Color::Red);
        isShot = false;
    }

    sf::FloatRect getRect() { return bullet.getGlobalBounds(); }

    void draw(sf::RenderWindow& window) {
        window.draw(bullet);       
    }
	// set the dirction of bullet
    void setDir(Direction dir) { m_dir = dir; }
    Direction getDir() { return m_dir; }

	// set bullet position
    void setFirstPos(sf::Vector2f newPos) {
        bullet.setPosition(newPos);
    }
    
	// set bullet MOVEMENT
    void move(sf::Vector2f = { 0.f, 0.f }) override {
        if (m_dir == -1) bullet.move(-1, 0);
        else bullet.move(1, 0); };

    void moveBullet() {
        float dir = (m_dir == 1) ? 1 : -1;
        bullet.move(dir, 0);
    };

    void setShot(bool b) { isShot = b; }
    bool getShot() { return isShot; }
	void setsetLife(bool t) {};
private:
	// bullet Shape
    sf::RectangleShape bullet;
	// bullet Diriction
    Direction m_dir;
    bool isShot;
    

};