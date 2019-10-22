#ifndef BALL_H
#define BALL_H
#include "raylib.h"
#include "Player/Player.h"
#include "gameScreen/GameScreen.h"
enum ballState
{
	STAY, INVISIBLE, MOVE
};
static const short cantBalls = 2;
class Ball
{
private:
	Vector2 position;
	Vector2 speed;
	float radius;
	ballState ballStatus;
	static short cantBallsInvisible;
	static short multiplierAngel;
	Texture2D myTexture;
	Vector2 beforePosition;
	Vector2 angle;
	float natualSpeed;
	int myID;
public:
	Ball(Vector2 initialPosition,int newRadius,ballState myStartState,Texture2D newTexture, int mynewID);
	void moveInMenu(Player* player);
	void setStatus(ballState newStatus);
	ballState getStatus();
	void drawMe();
	void ShotingMe(bool playerShooting);
	Vector2 getPosition();
	static short getMultiplerAngle();
	int getRadius();
	static int getLength();
	void move(Player* player);
	Vector2 getSpeed();
	void setSpeed(float x, float y);
	void revertToNegativeSpeedX();
	void revertToPositiveSpeedX();
	void revertToPositiveSpeedY();
	void revertToNegativeSpeedY();

};
#endif