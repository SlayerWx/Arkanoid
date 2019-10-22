#include "ball.h"
short Ball::cantBallsInvisible = 0;
short Ball::multiplierAngel = 200;
using namespace std;
Ball::Ball(Vector2 initialPosition, int newRadius, ballState myStartStatus, Texture2D newTexture,int mynewID)
{
	position = initialPosition;
	natualSpeed = 300;
	speed = { 0,natualSpeed};
	radius = static_cast<float>(newRadius);
	ballStatus = myStartStatus;
	cantBallsInvisible = 0;
	myTexture = newTexture;
	myID = mynewID;
}
void Ball::moveInMenu(Player* player)
{
	if (ballStatus == STAY)
	{
		position = { (player->playerPosition().x + player->playerSize().x / 2),(player->playerPosition().y - radius)};
	}
	else if (ballStatus == MOVE)
	{
		position = {position.x,(position.y-speed.y * GetFrameTime())};
	}
}
void Ball::setStatus(ballState newStatus)
{
	ballStatus = newStatus;
}
ballState Ball::getStatus()
{
	return ballStatus;
}
void Ball::drawMe() 
{
	if (ballStatus != INVISIBLE)
	{
		DrawTexture(myTexture, static_cast<int>(position.x - radius - 1), static_cast<int>(position.y - radius - 1), WHITE);
	}
}
void Ball::ShotingMe(bool playerShooting)
{
	if (ballStatus == STAY && playerShooting)
	{
		ballStatus = MOVE;
	}
}
Vector2 Ball::getPosition()
{
	return position;
}
short Ball::getMultiplerAngle()
{
	return static_cast<short>(multiplierAngel);
}
int Ball::getRadius()
{
	return static_cast<int>(radius);
}
int Ball::getLength()
{
	return cantBalls;
}
Vector2 Ball::getSpeed()
{
	return speed;
}
void Ball::setSpeed(float x,float y)
{
	speed.x = x;
	speed.y = y;
}
void Ball::move(Player* player)
{
	if (ballStatus == STAY)
	{
		position = { (player->playerPosition().x + player->playerSize().x / 2),(player->playerPosition().y - radius) };
	}
	if (ballStatus == MOVE)
	{
		position.x += speed.x * GetFrameTime();
		position.y += speed.y * GetFrameTime();

		angle.x = position.x - beforePosition.x;
		angle.y = position.y - beforePosition.y;

		if (CheckCollisionCircleRec(position,radius,{player->playerPosition().x, 
			player->playerPosition().y, player->playerSize().x, player->playerSize().y}))
		{
			if (speed.y > 0)
			{
				speed.x = ((position.x - (player->playerPosition().x + player->playerSize().x / 2)) / 
														(player->playerSize().x / 2) * multiplierAngel);
				speed.y *= -1;
			}
		}
		if (((position.x + radius) > GetScreenWidth()) || ((position.x - radius) < 0))
		{
			speed.x *= -1;
		}
		if ((position.y - radius -1) < 0)
		{
			revertToPositiveSpeedY();
		}
		if ((position.y + radius) > GetScreenHeight())
		{
			speed = {0,natualSpeed };
			if (cantBallsInvisible < 1)
			{
				ballStatus = STAY;
				player->setLife(player->getLife() - 1);
			}
			else
			{
				ballStatus = INVISIBLE;
				cantBallsInvisible--;
				if (cantBallsInvisible < 0)
				{
					cantBallsInvisible = 0;
				}
			}
		}
	}
	beforePosition = position;
}
void Ball::revertToNegativeSpeedX()
{
	if (speed.x < 0)
	{
		speed.x = speed.x *-1;
	}
}
void Ball::revertToPositiveSpeedX()
{
	if (speed.x > 0)
	{
		speed.x = speed.x *-1;
	}
}
void Ball::revertToPositiveSpeedY()
{
	if (speed.y < 0)
	{
		speed.y = speed.y *-1;
	}
}
void Ball::revertToNegativeSpeedY()
{
	if (speed.y > 0)
	{
		speed.y = speed.y *-1;
	}
}