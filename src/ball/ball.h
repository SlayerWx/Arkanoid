#ifndef BALL_H
#define BALL_H
#include "raylib.h"
class Ball
{
private:
	Vector2 position;
	Vector2 speed;
	int radius;
	bool active;
public:
	Ball(Vector2 initialPosition,Vector2 newSpeed,int newRadius,bool isActive);
};
#endif