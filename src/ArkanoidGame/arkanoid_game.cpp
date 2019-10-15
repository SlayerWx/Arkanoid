#include "arkanoid_game.h"
#include "ball/ball.h"
#include "Menu/menu.h"
#include "Options/options.h"
#include "Game/Game.h"
namespace arkanoid
{
using namespace menu;
int ArkanoidGame::screenWidth = 0;
int ArkanoidGame::screenHeight = 0;
options::Options* options;
Menu* menu;
Game* gameStage;
Player* player;
Ball* balls[cantBalls];
Vector2 PlayerSize = { 70,20 };
int playerMaxLifes = 5;
float initialSpeedBalls = 300;
Vector2 savedBallsPosition = { -10,0 };
int radiusBalls = 10;
ArkanoidGame::ArkanoidGame(int newScreenWidth, int newScreenHeight)
{
	screenWidth = newScreenWidth;
	screenHeight = newScreenHeight;
	InitWindow(screenWidth, screenHeight, "Ruffo Maximiliano - arkanoid");
	gameStatus = MENU;
	inGame = true;
	titleTexture = LoadTexture("resource/assets/img/Title.png");
	playTexture = LoadTexture("resource/assets/img/Play.png");
	exitTexture = LoadTexture("resource/assets/img/Exit.png");
	backTexture = LoadTexture("resource/assets/img/Back.png");
	ballTexture = LoadTexture("resource/assets/img/Kenney.nl/png/ballGrey.png");
	playerTexture = LoadTexture("resource/assets/img/Kenney.nl/png/Player.png");
	RGBtexture = LoadTexture("resource/assets/img/RGB.png");
	playerTexture.width = static_cast<int>(PlayerSize.x);
	playerTexture.height = static_cast<int>(PlayerSize.y);

	RGBoptionsTexture[0] = LoadTexture("resource/assets/img/R.png");
	RGBoptionsTexture[1] = LoadTexture("resource/assets/img/G.png");
	RGBoptionsTexture[2] = LoadTexture("resource/assets/img/B.png");

	RGBPorcentTexture[0] = LoadTexture("resource/assets/img/0.png");
	RGBPorcentTexture[1] = LoadTexture("resource/assets/img/10.png");
	RGBPorcentTexture[2] = LoadTexture("resource/assets/img/20.png");
	RGBPorcentTexture[3] = LoadTexture("resource/assets/img/30.png");
	RGBPorcentTexture[4] = LoadTexture("resource/assets/img/40.png");
	RGBPorcentTexture[5] = LoadTexture("resource/assets/img/50.png");
	RGBPorcentTexture[6] = LoadTexture("resource/assets/img/60.png");
	RGBPorcentTexture[7] = LoadTexture("resource/assets/img/70.png");
	RGBPorcentTexture[8] = LoadTexture("resource/assets/img/80.png");
	RGBPorcentTexture[9] = LoadTexture("resource/assets/img/90.png");
	RGBPorcentTexture[10] = LoadTexture("resource/assets/img/100.png");

}
void ArkanoidGame::game()
{	
	initGame();
	while (inGame) 
	{
		updateGame();
		DrawGame();
		changeStage();
	}
}
void ArkanoidGame::initGame()
{
	menu = new Menu(titleTexture,playTexture, exitTexture);
	options = new options::Options(playTexture, backTexture, RGBoptionsTexture, RGBPorcentTexture, RGBtexture);

	player = new Player({ static_cast<float>(ArkanoidGame::getGameScreenWidth()) / 2,
						  static_cast<float>(ArkanoidGame::getGameScreenHeight()) - PlayerSize.y },PlayerSize, playerMaxLifes, playerTexture);
	for (int i = 0; i < cantBalls; i++)
	{
		balls[i] = new Ball(savedBallsPosition, { initialSpeedBalls,initialSpeedBalls }, radiusBalls, INVISIBLE, ballTexture);
		if (i == 0)
		{
			balls[0]->setStatus(STAY);
		}
	}
}
void ArkanoidGame::updateGame()
{
	switch (gameStatus)
	{
	case MENU:
		nextStage(menu->update(player,balls[0]));
		break;
	case OPTIONS:
		nextStage(options->update(player,balls[0]));
		break;
	case GAMEPLAY:
		nextStage(gameStage->update(player, balls[0]));
		break;
	case CREDITS:
		break;
	}
}
void ArkanoidGame::DrawGame()
{
	BeginDrawing();
	ClearBackground(DARKBLUE);
	switch (gameStatus)
	{
	case MENU:
		menu->draw(player,balls[0]);
		break;
	case OPTIONS:
		options->draw(player,balls[0]);
		break;
	case GAMEPLAY:
		gameStage->Draw(player, balls[0]);
		break;
	case CREDITS:
		break;
	}
	EndDrawing();
}
void ArkanoidGame::changeStage()
{
	gameStatus = nextStatus;
}
void ArkanoidGame::nextStage(GameScreen newStatus)
{
	nextStatus = newStatus;
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
		if (balls[i]) { delete balls[i]; }
	}
	if (player) { delete player; }
	if (menu)   { delete menu; } 
	if (options){ delete options; }
	if (gameStage) { delete gameStage; }

	UnloadTexture(playTexture);
	UnloadTexture(exitTexture);
	UnloadTexture(playTexture);
	UnloadTexture(titleTexture);
	UnloadTexture(backTexture);
	UnloadTexture(ballTexture);
	UnloadTexture(RGBtexture);
	for (int i = 0;i< 3; i++)
	{
		UnloadTexture(RGBoptionsTexture[i]);
	}
	for (int i = 0; i < 11; i++)
	{
		UnloadTexture(RGBPorcentTexture[i]);
	}
	CloseWindow();
}
}