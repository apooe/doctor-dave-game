#pragma once
#include "Utilities.h"
#include <SFML/Graphics.hpp>
#include <vector>

class LoadFromFile
{

public:
	static LoadFromFile& getInstance();
	sf::Texture * getTexture(const Object_t & index);//get texture of object

private:
	LoadFromFile();
	~LoadFromFile() {};
	std::vector<sf::Texture> m_pics;



};
