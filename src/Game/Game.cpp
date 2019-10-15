#include "Game.h"

Game::Game()
{
	for (int i = 0;i< cantLevelsInGame;i++)
	{
		lvl[i] = new Level();
	}
	currentLevel = 0;
}
GameScreen Game::update(Player* player, Ball* ball)
{
	switch (currentLevel)
	{
	case 0:
		lvl[0]->update(player,ball);
		break;
	case 1:
		lvl[1]->update(player, ball);
		break;
	case 2:
		lvl[2]->update(player, ball);
		break;
	}
	return GAMEPLAY;
}
void Game::Draw(Player* player, Ball* ball)
{
	switch (currentLevel)
	{
	case 0:
		lvl[0]->draw(player, ball);
		break;
	case 1:
		lvl[1]->draw(player, ball);
		break;
	case 2:
		lvl[2]->draw(player, ball);
		break;
	}
}

Game::~Game()
{
	for (int i = 0; i < cantLevelsInGame; i++)
	{
		if(lvl[i])
		delete lvl[i];
	}
}