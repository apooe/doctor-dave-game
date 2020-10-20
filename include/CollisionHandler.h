#pragma once
#include "GameObject.h"
#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>
#include "DoctorDave.h"
#include "CoronaVirus.h"
#include "FluVirus.h"
#include "Diamond.h"
#include "DarkTile.h"
#include "Trophy.h"
#include "Exception.h"
#include "Virus.h"
#include "Antidote.h"
#include "Bullet.h"
#include "GameTile.h"
#include "JetPack.h"
#include "Fire.h"
#include "Door.h"


// if to object of rectangle collisons
bool checkIfCollision(const sf::FloatRect& ShapA, const sf::FloatRect& ShapB);
// the collision result
void setCollision(GameObject& obj1, GameObject& obj2 );