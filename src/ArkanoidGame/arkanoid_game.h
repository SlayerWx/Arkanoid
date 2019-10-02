#ifndef ARKANOIDGAME
#define ARKANOIDGAME
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
public:
	ArkanoidGame();
	void gameLoop();
	void menu();
	void game();
};
}
#endif