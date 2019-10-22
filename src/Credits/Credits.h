#ifndef CREDITS_H
#define CREDITS_H
#include "Player/Player.h"
#include "ball/ball.h"
#include "raylib.h"
#include "gameScreen/GameScreen.h"
class Credits
{
public:
	Credits(Texture2D newBackTexture);
	GameScreen update(Player* player, Ball* ball);
	void draw(Player* player, Ball* ball);
private:
	Texture2D backTexture;
	void colisionWithTexture(Ball* ball);
	bool backIsPressed;
	void creditInit(Player* player, Ball* ball);
	bool firstFrame;
};
#endif