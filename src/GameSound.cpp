#include "GameSound.h"
#include <iostream>


GameSound& GameSound::getInstance()
{
	static GameSound sm;
	return sm;
}

GameSound::~GameSound()
{
}

GameSound::GameSound()
{

	if (!catchObj.openFromFile("CollectHeart.ogg"))
		throw(FileNotFoundException("game wav"));
	catchObj.setVolume(70);

	if (!enemy_killed.openFromFile("virusKilled.wav"))
		throw(FileNotFoundException("game wav"));
	enemy_killed.setVolume(70);

	if (!fly.openFromFile("gameJet.wav"))
		throw(FileNotFoundException("game wav"));
	fly.setVolume(70);
	fly.setLoop(true);



	if (!shoot.openFromFile("shoot.ogg"))
		throw(FileNotFoundException("game wav"));
	shoot.setVolume(70);

	if (!Walk.openFromFile("Walk.wav"))
		throw(FileNotFoundException("game wav"));
	Walk.setVolume(60);
	Walk.setLoop(true);

	if (!gameover.openFromFile("gameOver.ogg"))
		throw(FileNotFoundException("game over wav"));
	gameover.setVolume(60);

	if (!player_killed.openFromFile("Life Lost.ogg"))
		throw(FileNotFoundException("game wav"));
	player_killed.setVolume(60);



	if (!game_background.openFromFile("Level Music.ogg"))
		throw(FileNotFoundException("game wav"));
	game_background.setVolume(60);
	game_background.setLoop(true);
	if (!menu.openFromFile("MenuMusic.wav"))
		throw(FileNotFoundException("game wav"));
	menu.setVolume(60);

	if (!success.openFromFile("LevelWin.ogg"))
		throw(FileNotFoundException("success wav"));
	success.setVolume(60);

}

void GameSound::stopFly()
{
	fly.stop();

}
void GameSound::playFly()
{
	if (fly.getStatus() != sf::SoundSource::Playing)
		fly.play();
}

void GameSound::stopFail()
{
	fail.stop();
}
void GameSound::playFail()
{

	fail.play();
}
bool GameSound::isJumpPlaying()
{
	return jump.getStatus() == sf::SoundSource::Playing;
}
bool GameSound::isSuccessPlaying()
{
	return success.getStatus() == sf::SoundSource::Playing;
}
void GameSound::stopSuccess()
{
	success.stop();

}
void GameSound::playSuccess()
{
	success.play();
}
void GameSound::stopGift()
{
	gift.stop();
}
void GameSound::playGift()
{
	gift.play();
}
void GameSound::playIntro()
{
		catchObj.play();
}

void GameSound::stopIntro()
{
	catchObj.stop();
}

void GameSound::playExplosion()
{
	explosion.play();
}

void GameSound::stopExplosion()
{
	explosion.stop();
}

void GameSound::playSteps()
{
	Walk.play();
}

void GameSound::stopSteps()
{
	Walk.stop();
}

void GameSound::playGameOver()
{
	gameover.play();
}

void GameSound::stopGameOver()
{
	gameover.stop();
}

void GameSound::playJump()
{
	jump.play();
}

void GameSound::stopJump()
{
	jump.stop();
}

void GameSound::playEnemyKilled()
{
	enemy_killed.play();
}

void GameSound::stopEnemyKiller()
{
	enemy_killed.stop();
}

void GameSound::playAmmo()
{
	shoot.play();
}

void GameSound::stopAmmo()
{
	shoot.stop();
}

void GameSound::playPlayerKilled()
{
	player_killed.play();
}

void GameSound::stopPlayerKilled()
{
	player_killed.stop();
}

void GameSound::playMenu()
{

		menu.play();
}

void GameSound::stopMenu()
{
	menu.stop();
}

void GameSound::playGameBackgroud()
{
	if (game_background.getStatus() != sf::SoundSource::Playing)
		game_background.play();
}

void GameSound::stopGameBackgroud()
{
	game_background.stop();
}



