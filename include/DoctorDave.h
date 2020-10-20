#pragma once
#include <iostream>
#include "DynamicObject.h"
#include "DataGame.h"

using namespace std;

class DoctorDave : public DynamicObject
{
public:
	DoctorDave() = default; //default c_tor
	DoctorDave(sf::Vector2f& pos); //c_tor
	~DoctorDave() = default; //d_tor
	void setDirection(); // set Direction of dave
	sf::FloatRect getRect() override; //get bounds of sprite
	void move(sf::Vector2f d = {0,0}) override; // dave move
	bool getAxe(int i)const { return m_axes[i]; } //help for collision
	void setAxe(int i, bool temp) { m_axes[i] = temp; }
	unique_ptr<DaveMotion>& getAction() { return m_action; } //return action chosen
	bool getAntidote() const { return m_haveAntidote; } // if dave has gun
	void setAntidote(const bool& antidote) { m_haveAntidote = antidote; }
	bool getJet() const { return m_haveJet; } //if dave has jetpack
	void setJet(const bool& jet) { m_haveJet = jet; }

	bool getTrophy() const { return m_haveTrophy; } //if dave has trophy
	void setTrophy(const bool& trophy) { m_haveTrophy = trophy; }

	void ObjectAnimtion(sf::RenderWindow& window) override;
	bool restart() const; //restart level
	void setWinner(const bool& win) { m_win = win; }//if player won
	bool getWinner() const { return m_win; }
	void setDatas(DataGame * info);
	void setsetLife(bool t); // set if dave dead
	void addScore(); // update score
	Direction getDirDave() const; // get direction of dave
	void setFly(); 
	bool setFireOnObject(sf::RenderWindow& window); 


private:
	DataGame* m_dataBar;
	unique_ptr<DaveMotion>m_action;//movement of dave
	sf::Sprite m_JetSprite;
	sf::Texture* m_Jet = nullptr;
	bool m_haveAntidote, //picure to eliminate viruses
		m_haveJet, //jet to fly
		m_axes[2],//temp
		m_win, //to know if player won
		m_haveTrophy; //must have it to pass door

	
};