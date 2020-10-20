#include "Board.h"
#include "GameFactoryPattern.h"


bool Board::ReadLevel(string fileName, vector<unique_ptr<StaticObject>>& staticBoard, unique_ptr<DoctorDave>& dave, vector<unique_ptr<CatchAbleObject>>& toolBoard, vector<unique_ptr<Virus>>& virus) 
{
	ifstream m_level;
	m_level.open(fileName);
	
	if (!m_level.is_open()) {
		if(dave)
			throw FileNotFoundException(fileName.c_str());
		return false;
	}
	m_level >> m_row;
	m_level >> m_col;

	sf::Vector2f loc;

	for (int i = 0; i < m_row; i++) {
		m_level.get();
		for (int j = 0; j < m_col; j++) {

			char c = m_level.get();
			loc.x = (float)(i + 1);
			loc.y = (float)j;

			if (c == Textures::T_doctorDave)
			{
				if (!dave) dave = std::make_unique<DoctorDave>(loc);
				else dave->getObjSprite().setPosition({ loc.y * OBJECT_SIZE, loc.x * OBJECT_SIZE });
				
			}
			auto obj1 = GameFactoryPattern<StaticObject>::create(c, loc);
			if (obj1) {
				staticBoard.emplace_back(move(obj1));
				continue;
			}

			auto obj2 = GameFactoryPattern<CatchAbleObject>::create(c, loc);
			if (obj2) {
				toolBoard.emplace_back(move(obj2));
				continue;
			}

			auto obj3 = GameFactoryPattern<Virus>::create(c, loc);
			if (obj3) {
				virus.emplace_back(move(obj3));
				continue;
			}
		}
	}
	m_level.close();
	return true;
}

