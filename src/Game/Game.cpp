#include "Game.h"
#include "gameScreen/GameScreen.h"
int currentLevel = 0;
Game::Game()
{
	for (int i = 0;i< cantLevelsInGame;i++)
	{
		lvl[i] = new Level();
	}
	currentLevel = 0;
	firstFrame = true;
}
void Game::init(Player* player)
{
	refreshLogicArray();
	//lvl 1(0)
	for (int i = 0; i < countBarWidth; i++)
	{
		for (int t = 0; t < countBarHeight; t++)
		{
			if (t % 2 == 0)
			{
				aux[t][i] = Brick::VISIBLE;
			}
			else
			{
				aux[t][i] = Brick::INVISIBLE;
			}
		}
	}
	lvl[0]->setLevel(aux);
	refreshLogicArray();
	//lvl 2(1)
	for (int i = 0; i < countBarHeight; i++)
	{
		for (int t = 0; t < countBarWidth; t++)
		{
			if (i == 0 || i == countBarHeight - 1 || t % 2 == 0)
			{
				aux[i][t] = Brick::VISIBLE;
			}
			else
			{
				aux[i][t] = Brick::INVISIBLE;
			}
		}
	}
	lvl[1]->setLevel(aux);
	refreshLogicArray();
	// lvl 3(2)
	for (int i = 0; i < countBarHeight; i++)
	{
		for (int t = 0; t < countBarWidth; t++)
		{
			if (i == 0 || t == 0 || t== countBarWidth-1 || t % 2 == 0 || i % 2 == 0)
			{
				aux[i][t] = Brick::VISIBLE;
			}
			else
			{
				aux[i][t] = Brick::INVISIBLE;
			}
		}
	}
	lvl[2]->setLevel(aux);
	refreshLogicArray();
	player->setPlayerPosition(GetScreenWidth()/2.0f,player->playerPosition().y * 1.0f);
}
void Game::update(Player* player, Ball* ball[])
{
	if (firstFrame)
	{
		currentLevel = 0;
		init(player);
		firstFrame = false;
	}
	if (lvl[currentLevel]->AllBarInvisible(ball, currentLevel, cantLevelsInGame,player))
	{
		currentLevel++;
#if DEBUG
		cout << "currentLevel:"<< currentLevel+1 << endl;
#endif
	}
	 lvl[currentLevel]->update(player,ball,currentLevel,cantLevelsInGame);
	 if (currentLevel > 2)
	 {
		 firstFrame = true;
	 }
}
void Game::Draw(Player* player, Ball* ball[])
{
	lvl[currentLevel]->draw(player, ball,currentLevel, cantLevelsInGame);
}
void Game::refreshLogicArray()
{
	for (int i = 0; i < countBarHeight; i++)
	{
		for (int t = 0; t < countBarWidth; t++)
		{
			aux[i][t] = Brick::INVISIBLE;
		}
	}
}
Game::~Game()
{
	for (int i = 0; i < cantLevelsInGame; i++)
	{
		if (lvl[i])
		{
			delete lvl[i];
		}
	}
}
bool Game::endGame()
{
	if (currentLevel >= cantLevelsInGame)
	{
		return true;
	}
	return false;
}