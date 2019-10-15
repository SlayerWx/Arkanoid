#ifndef BALL_H
#define BALL_H
#include "raylib.h"
#include "Player/Player.h"
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
	float radius;
	ballState ballStatus;
	static short cantBallsInvisible;
	Texture2D myTexture;
public:
	Ball(Vector2 initialPosition,Vector2 newSpeed,int newRadius,ballState myStartState,Texture2D newTexture);
	void moveInMenu(Player* player);
	void setStatus(ballState newStatus);
	void drawMe();
	void ShotingMe(bool playerShooting);
	Vector2 getPosition();
	int getRadius();
};
#endif