#ifndef ARKANOIDGAME_H
#define ARKANOIDGAME_H
namespace arkanoid
{
class ArkanoidGame
{
private:
	enum GameScreen
	{
		MENU, GAMEPLAY,CREDITS
	};
	GameScreen gameStatus;
	static int screenWidth;
	static int screenHeight;
	bool inGame;
	void initGame();
	void updateGame();
	void DrawGame();
public:
	ArkanoidGame(int screenWidth, int screenHeight);
	void game();
	static int getGameScreenWidth();
	static int getGameScreenHeight();
	~ArkanoidGame();
};
}
#endif