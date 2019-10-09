#include "arkanoid_game.h"
#include "Menu/menu.h"
#include "raylib.h"
#include "ball/ball.h"
namespace arkanoid
{
int ArkanoidGame::screenWidth = 0;
int ArkanoidGame::screenHeight = 0;
Menu* menu;
Player* player;
Ball* balls[cantBalls];
ArkanoidGame::ArkanoidGame(int newScreenWidth, int newScreenHeight)
{
	screenWidth = newScreenWidth;
	screenHeight = newScreenHeight;
	InitWindow(screenWidth, screenHeight, "Ruffo Maximiliano - arkanoid");
	gameStatus = MENU;
	inGame = true;
}
void ArkanoidGame::game()
{	
	initGame();
	while (inGame) 
	{
		updateGame();
		DrawGame();
	}
}
void ArkanoidGame::initGame()
{
	menu = new Menu();
	player = new Player({ static_cast<float>(ArkanoidGame::getGameScreenWidth()) / 2,
						  static_cast<float>(ArkanoidGame::getGameScreenHeight()) - 15 },
																			{ 70,40 }, 1);
	for (int i = 0; i < cantBalls; i++)
	{
		balls[i] = new Ball({ -10,0 }, { 10,10 }, 20, ballState::INVISIBLE);
	}
}
void ArkanoidGame::updateGame()
{
	switch (gameStatus)
	{
	case MENU:
		menu->update(player,balls);
		break;
	case GAMEPLAY:
		break;
	case CREDITS:
		break;
	}
}
void ArkanoidGame::DrawGame()
{
	BeginDrawing();
	ClearBackground(WHITE);
	switch (gameStatus)
	{
	case MENU:
		menu->draw(player);
		break;
	case GAMEPLAY:
		break;
	case CREDITS:
		break;
	}
	EndDrawing();
}
int ArkanoidGame::getGameScreenWidth()//static
{
	return screenWidth;
}
int ArkanoidGame::getGameScreenHeight()//static
{
	return screenHeight;
}
ArkanoidGame::~ArkanoidGame()
{
	for (int i = 0; i < cantBalls; i++)
	{
		if (balls[i])
		{
			delete balls[i];
		}
	}
	if (player)
	{
		delete	player;
	}
	if (menu)
	{
		delete menu;
	}
}
}