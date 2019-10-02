#ifndef ARKANOIDGAME
#define ARKANOIDGAME
namespace Arkanoid
{
class ArkanoidGame
{
private:
	enum GameScreen
	{
		MENU, GAMEPLAY, ENDING
	};
public:
	ArkanoidGame();
	void game();
	void initMenu();
	void updateMenu();
	void drawMenu();
	
};
}
#endif