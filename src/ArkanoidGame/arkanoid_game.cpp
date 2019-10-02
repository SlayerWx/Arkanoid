#include "arkanoid_game.h"
namespace arkanoid
{
ArkanoidGame::ArkanoidGame()
{
}
void ArkanoidGame::gameLoop()
{
	switch (gameStatus)
	{
	case MENU:
		menu();
		break;
	case GAMEPLAY:
		game();
		break;
	}
}
}