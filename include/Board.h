#pragma once
#include "StaticObject.h"
#include "Virus.h"
#include "CatchAbleObject.h"
#include "DoctorDave.h"
#include "Exception.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <string>


using namespace std;


class Board
{
public:
	// Reading the level from files and set every item to his object
	bool ReadLevel(string fileName, vector<unique_ptr<StaticObject>>& staticBoard, 
		unique_ptr<DoctorDave>& DoctorDave, vector<unique_ptr<CatchAbleObject>>& toolBoard,
		vector<unique_ptr<Virus>>& virus);
	~Board() = default;
	// size of data bar
	sf::VideoMode getSize()const { return sf::VideoMode(m_col * 60, m_row * 70); };

private:
	// Board col and row
	int m_row, m_col;
};

