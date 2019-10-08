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
public:
	Player(Vector2 initialPosition,Vector2 newSize,int newLife);
	void drawMe();
	void move();
};
#endif

