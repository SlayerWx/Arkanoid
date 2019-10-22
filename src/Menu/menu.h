#ifndef MENU_H
#define MENU_H
#include "Player/Player.h"
#include "ball/ball.h"
#include "raylib.h"
#include "gameScreen/GameScreen.h"
namespace menu
{
class Menu
{
public:
	Menu(Texture2D newTitleTexture, Texture2D newPlayTexture, Texture2D newExitTexture);
	GameScreen update(Player* player, Ball* ball);
	void draw(Player* player, Ball* ball);
	bool exitCloseGame();
private:
	Texture2D titleTexture;
	Texture2D playTexture;
	Texture2D exitTexture;
	void colisionWithTexture(Ball* ball);
	bool playIsPressed;
	bool closeGame;
	void menuInit(Player* player, Ball* ball);
	bool firstFrame;
};
}
#endif