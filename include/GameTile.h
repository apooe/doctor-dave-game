#pragma once
#include "StaticObject.h"
#include "LoadFromFile.h"
#include "GameFactoryPattern.h"

using namespace:: sf;
class GameTile : public StaticObject
{
public:

	GameTile(Vector2f& tilePosition);
	~GameTile() {};
	void setTilePos(Vector2f& tilePosition);

private:
	static bool m_instance;

};

