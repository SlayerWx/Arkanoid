#ifndef OPTIONS_H
#define OPTIONS_H
#include "raylib.h"
#include "Player/Player.h"
#include "ball/ball.h"
#include "gameScreen/GameScreen.h"
namespace options
{
const int countLetterRGB = 3;
const int countPercentRGB = 11;
const int RGBisR = 0;
const int RGBisG = 1;
const int RGBisB = 2;
class Options
{
private:
	bool IsPressedToGameplay;
	bool IsPressedToBack;
	void colisionWithTexture(Ball* ball);
	Texture2D playTexture;
	Texture2D BackTexture;
	Texture2D RGB[countLetterRGB];
	Texture2D RGBPorcentTexture[countPercentRGB];
	Texture2D RGBtexture;
	Color customisedColor;
	Color RGBpercentSelector(Color actualPlayerColor);
	int GetpercentRGB();
	bool RGBPercentTurn;
public:
	GameScreen update(Player* player, Ball* ball);
	void draw(Player* player, Ball* ball);
	Options(Texture2D newPlayTexture, Texture2D newBackTexture, Texture2D RGB[],Texture2D newRGBPorcentTexture[],Texture2D newRGBtexture);
	~Options();
};
}
#endif

