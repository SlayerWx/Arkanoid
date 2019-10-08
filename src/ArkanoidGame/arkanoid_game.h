#ifndef ARKANOIDGAME_H
#define ARKANOIDGAME_H
#include "Menu/menu.h"
namespace arkanoid
{
class ArkanoidGame
{
private:
	enum GameScreen
	{
		MENU, GAMEPLAY
	};
	GameScreen gameStatus;
	static int screenWidth;
	static int screenHeight;
	void gameStage();
	void menuStage(Menu* menu);
public:
	ArkanoidGame(int screenWidth, int screenHeight);
	void game();
	static int getGameScreenWidth();
	static int getGameScreenHeight();
};
}
#endif