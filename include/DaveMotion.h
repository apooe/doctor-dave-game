#pragma once
#include <memory>
#include <SFML\Graphics.hpp>
#include "Utilities.h"
#include <map>
#include <functional>

using sf::Clock;
using sf::Time;
using sf::Keyboard;



class DoctorDave;

class DaveMotion
{
public:

	DaveMotion(DoctorDave&); //c_tor
	virtual ~DaveMotion() = default;//d_tor
	sf::Vector2f& getMove() { return m_move; };//get vector
	bool getJump() const { return m_jump; } //if can jump
	void setJump(const bool& jump) { m_jump = jump; } //set if can jump
	Direction getDir() const { return m_dir; } // right or left
	void setFly(const bool& fly) { m_fly = fly; } // set if can fly
	bool getFly() const { return m_fly; } //get if can fly
	void daveFlyJet();//check mvt of jetpack
	void daveAction(DoctorDave& dave, float speed); //handler move of dave
	void setDirDave(); // set direction



protected:

	sf::Vector2f m_move; // movement of dave

	bool m_jump = false,
		m_fly = false,
		isCenter = false,
		m_anim;

	Direction m_dir = Right;
	float m_speed; // speed of dave
	Time m_moveTimer = sf::seconds(0.2f); // timer for animation
	Clock m_clock;//for animation
	std::map<Keyboard::Key, std::function<void(void)>> m_moves;//directions of dave
	DoctorDave& m_DoctorDave;//dave
	int m_walk = 0; 
	void setFunctions(Keyboard_t d);
	void restartWalk(); // for animation

};

