#include "ArkanoidGame/arkanoid_game.h"
using namespace arkanoid;
int main()
{
	ArkanoidGame* videoGame = new ArkanoidGame(screenWidth,screenHeight);
	videoGame->game();
	delete videoGame;
	return 0;
}