#include "LoadFromFile.h"
const std::string pic = "pic";
const std::string type = ".png";

sf::Texture * LoadFromFile::getTexture(const Object_t & index)
{
	return &m_pics.at(index);
}

LoadFromFile& LoadFromFile::getInstance()
{
	static LoadFromFile instance;
	return instance;
}

LoadFromFile::LoadFromFile()
{
	m_pics.resize(NUM_OF_TEXTURES);
	std::string p;

	for (int i = 0; i < NUM_OF_TEXTURES; i++)
	{
		p = pic + std::to_string(i) + type;
		m_pics[i].loadFromFile(p);
	}

}
