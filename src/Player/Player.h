#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
class Player
{
private:
	Vector2 position;
	Vector2 size;
	int life;
	static int speed;
	Texture2D myTexture;
	Color myColor;
public:
	Player(Vector2 initialPosition,Vector2 newSize,int newLife,Texture2D newTexture);
	void drawMe();
	void move();
	Vector2 playerPosition();
	Vector2 playerSize();
	static int getSpeed();
	bool isShotBalls();
	void customColor(Color newCustom);
	Color getCustomColor();
};
#endif

