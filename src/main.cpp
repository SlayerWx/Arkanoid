#include "ArkanoidGame/arkanoid_game.h"
using namespace arkanoid;
const int screenWidth = 800;
const int screenHeight = 450;
int main()
{
	ArkanoidGame* videoGame = new ArkanoidGame(screenWidth, screenHeight);
	videoGame->game();
	delete videoGame;
	return 0;
}