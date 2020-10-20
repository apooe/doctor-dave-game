#include "DaveMotion.h"
#include "GameObject.h"
#include "LoadFromFile.h"
#include "DoctorDave.h"
#include <iostream>

static int walkTime = 0;
static int timeUp = 0;
static int timeDown = 0;

DaveMotion::DaveMotion(DoctorDave& DoctorDave) :m_DoctorDave(DoctorDave),
m_speed(SPEED), m_anim(false)
{
	m_moves.emplace(Keyboard::Up, [&]() {setFunctions(UP); });
	m_moves.emplace(Keyboard::Down, [&]() {setFunctions(DOWN); });
	m_moves.emplace(Keyboard::Right, [&]() {setFunctions(RIGHT); });
	m_moves.emplace(Keyboard::Left, [&]() {setFunctions(LEFT); });

}

//function to add to m_moves in function of direction
void DaveMotion::setFunctions(Keyboard_t d)
{
	switch (d) {
	case UP: {
		if (m_move.y != 0) // cant go up
			return;

		float i = (m_dir == Right) ? 1 : -1;
		m_DoctorDave.getObjSprite().setScale({ i,1 });

		if (!m_jump && !m_fly) // if cant jump and cant fly 
			return;

		m_move.y = -m_speed; //go up
		walkTime++;
		break;
	}
	case DOWN:
		if (!m_fly) //if cant fly
			return;
		m_move.y = m_speed; // go down
		m_DoctorDave.getObjSprite().setScale({ Right,1 });
		break;

	case RIGHT:
		m_move.x = m_speed; //go right
		m_dir = Right;
		m_DoctorDave.getObjSprite().setScale({ Right,1 });

		break;

	case LEFT:
		m_move.x = -m_speed; // go left
		m_dir = Left;
		m_DoctorDave.getObjSprite().setScale({ Left,1 });
		break;
	}
}
//for animation
void DaveMotion::restartWalk()
{
	if (m_clock.getElapsedTime().asSeconds() >= m_moveTimer.asSeconds()) {
		if (m_anim) {
			m_clock.restart();
			m_walk++;
		}
	}
	if (m_walk >= 3) {
		m_walk = 0;
	}
}

//set move with jet and jump
void DaveMotion::daveFlyJet()
{
	if (m_move.y < 0)
		walkTime++;

	if (m_fly) {
		if (m_move.y < 0) { //up
			timeUp++;
			if (timeUp >= 70) {
				timeUp = 0;
				m_move.y = 0;
			}
		}
		else if (m_move.y > 0) {//down
			timeDown++;
			if (timeDown >= 70) {
				timeDown = 0;
				m_move.y = 0;
			}
		}
		return;
	}

	if (walkTime >= 270) { // for jump 
		walkTime = 0;
		m_move = { 0, m_speed };
		m_jump = false;
	}
}

void DaveMotion::daveAction(DoctorDave& player, float speed)
{

	m_speed = speed;
	if (m_fly) { // if dave can fly
		sf::IntRect obj(0, 0, OBJECT_SIZE, OBJECT_SIZE);
		m_DoctorDave.getObjSprite().setTextureRect(obj);
	}

	else { //if dave cant fly
		restartWalk();
		if (m_move.y == 0) {
			sf::IntRect obj((OBJECT_SIZE - 10) * m_walk, 0, OBJECT_SIZE - 10, OBJECT_SIZE - 10);
			m_DoctorDave.getObjSprite().setTextureRect(obj);
		}
	}

	m_DoctorDave.getObjSprite().move(m_move); // dave move
	m_move.x = 0;

}
//set direction animation
//set movement of keyboard pressed
void DaveMotion::setDirDave()
{
	bool isPressed = false;

	for (auto& i : m_moves) {
		if (Keyboard::isKeyPressed(i.first)) {
			i.second(); //movement
			m_anim = true;
			isPressed = true;
		}
	}
	if (!isPressed)//if dave not pressed
		m_anim = false;

	daveFlyJet();//set move with jet 

}
