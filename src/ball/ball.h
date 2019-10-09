#ifndef BALL_H
#define BALL_H
#include "raylib.h"
enum ballState
{
	STAY, INVISIBLE, MOVE
};
static const short cantBalls = 10;
class Ball
{
private:
	Vector2 position;
	Vector2 speed;
	short radius;
	ballState ballStatus;
	static short cantBallsInvisible;
public:
	Ball(Vector2 initialPosition,Vector2 newSpeed,int newRadius,ballState myStartState);
	void moveInMenu();
	void setInPlayerBar(Vector2 playerPosition,float playerWidthSize,float newDistanceOfBar);
};
#endif