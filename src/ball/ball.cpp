#include "ball.h"
short Ball::cantBallsInvisible = 0;
Ball::Ball(Vector2 initialPosition, Vector2 newSpeed, int newRadius, ballState myStartStatus,Texture2D newTexture)
{
	position = initialPosition;
	speed = newSpeed;
	radius = newRadius;
	ballStatus = myStartStatus;
	cantBallsInvisible = cantBalls;
	myTexture = newTexture;
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
void Ball::drawMe() 
{
	DrawTexture(myTexture, position.x - radius -1 , position.y - radius -1 , WHITE);
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
int Ball::getRadius()
{
	return radius;
}