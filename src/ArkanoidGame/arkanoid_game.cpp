#include "arkanoid_game.h"
#include "Menu/menu.h"
#include "raylib.h"
namespace arkanoid
{
int ArkanoidGame::screenWidth = 0;
int ArkanoidGame::screenHeight = 0;
ArkanoidGame::ArkanoidGame(int newScreenWidth, int newScreenHeight)
{
	screenWidth = newScreenWidth;
	screenHeight = newScreenHeight;
	InitWindow(screenWidth, screenHeight, "Ruffo Maximiliano - arkanoid");
	gameStatus = MENU;
}
void ArkanoidGame::game()
{
	Menu* menu = new Menu();
	//while () {
		switch (gameStatus)
		{
		case MENU:
			menuStage(menu);
			break;
		case GAMEPLAY:
			gameStage();
			break;
		}
	//}
}
void ArkanoidGame::menuStage(Menu* menu)
{
	menu->loop();
}
void ArkanoidGame::gameStage()
{

}
int ArkanoidGame::getGameScreenWidth()//static
{
	return screenWidth;
}
int ArkanoidGame::getGameScreenHeight()//static
{
	return screenHeight;
}
}