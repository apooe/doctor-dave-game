#pragma once
const enum Textures
{
	T_doctorDave = '/',T_Antidote = 'a', T_RegVirus = 'v', T_CoronaVirus = 'c', T_rock = 'r', T_GameTile = 'w', T_door = 'D', 
	T_diamond = 'p',T_jetPack = 'j',	T_fire = 'f',T_trophy = 't',
};

enum Keyboard_t { UP, DOWN, LEFT, RIGHT };
const enum Object_t 
{
	o_doctor_dave,o_docDave_jumpR,o_regVirus, o_coronaVirus, o_rock, o_GameTile, o_door, o_Antidote, 
	o_diamond, o_docDave_jumpL, o_docDave_Jet, o_jetPack, o_fire,o_explosion,o_trophy,
	};


enum Direction
{
	Right = 1,
	Left = -1,
};


const int OBJECT_SIZE = 60;
const int LIVES = 3;
const int NUM_OF_TEXTURES = 15;
const int WIDTH = 1000;
const int HEIGHT = 600;
const float SPEED = 0.7f;
const int DIR = 4;
const int TIMER = -1;
