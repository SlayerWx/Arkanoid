#ifndef ARKANOIDGAME_H
#define ARKANOIDGAME_H
#include "gameScreen/GameScreen.h"
#include "raylib.h"
namespace arkanoid
{
class ArkanoidGame
{
private:
	GameScreen gameStatus;
	GameScreen nextStatus;
	static int screenWidth;
	static int screenHeight;
	bool inGame;
	void initGame();
	void updateGame();
	void DrawGame();
	void changeStage();
	void nextStage(GameScreen newStatus);
	Texture2D titleTexture;
	Texture2D playTexture;
	Texture2D exitTexture;
	Texture2D ballTexture;
	Texture2D playerTexture;
	Texture2D backTexture;
	Texture2D RGBoptionsTexture[3];
	Texture2D RGBPorcentTexture[11];
	Texture2D RGBtexture;
public:
	ArkanoidGame(int screenWidth, int screenHeight);
	void game();
	static int getGameScreenWidth();
	static int getGameScreenHeight();
	~ArkanoidGame();
};
}
#endif