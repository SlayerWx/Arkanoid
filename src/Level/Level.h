#ifndef LEVEL_H
#define LEVEL_H
#include "Player/Player.h"
#include "ball/ball.h"
#include "gameScreen/GameScreen.h"
#include "Bar/Bar.h"
#if DEBUG
#include <iostream>
#endif
using namespace std;
class Level
{
public:
	Level();
	~Level();
	int visibleBarNumber;
	void init(Player* player, Ball* ball[]);
	void update(Player* player, Ball* ball[], int currentLevel, int cantLevelsInGame);
	void draw(Player* player, Ball* ball[], int currentLevel,int cantLevelsInGame);
	void CheckColisionBarWithBalls(Ball* ball[], int currentLevel, int cantLevelsInGame);
	void setLevel(Brick::BarState newMapLogic[countBarHeight][countBarWidth]);
	bool AllBarInvisible(Ball* ball[], int currentLevel, int cantLevelsInGame);
private:
	Brick::Bar* map[countBarHeight][countBarWidth];
};
#endif