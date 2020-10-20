#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Exception.h"
class GameSound
{
public:
	
	GameSound();
	~GameSound();
	void stopFly();
	void playFly();
	void stopFail();
	void playFail();
	bool isJumpPlaying();
	bool isSuccessPlaying();
	void stopSuccess();
	void playSuccess();
	void stopGift();
	void playGift();
	void playIntro();
	void stopIntro();
	void playExplosion();
	void stopExplosion();
	void playSteps();
	void stopSteps();
	void playGameOver();
	void stopGameOver();
	void playJump();
	void stopJump();
	void playEnemyKilled();
	void stopEnemyKiller();
	void playAmmo();
	void stopAmmo();
	void playPlayerKilled();
	void stopPlayerKilled();
	void playMenu();
	void stopMenu();
	void playGameBackgroud();
	void stopGameBackgroud();
	static GameSound& getInstance();
private:
	bool destroyed = false;
	GameSound(const GameSound&);
	sf::Music catchObj, explosion, Walk, gameover,
		gift, shoot, success, fail, jump, enemy_killed,
		player_killed, menu, game_background, fly;
};

