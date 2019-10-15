#ifndef GAME_H
#define GAME_H
#include "Level/Level.h"
#include "gameScreen/GameScreen.h"
#include "Player/Player.h"
#include "ball/ball.h"
const int cantLevelsInGame = 3;
class Game
{
public:
	Game();
	~Game();
	GameScreen update(Player* player, Ball* ball);
	void Draw(Player* player, Ball* ball);

private:
	Level* lvl[cantLevelsInGame];
	short currentLevel;

};
#endif