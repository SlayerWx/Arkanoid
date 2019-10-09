#include "ball.h"
Ball::Ball(Vector2 initialPosition, Vector2 newSpeed, int newRadius, ballState myStartStatus)
{
	position = initialPosition;
	speed = newSpeed;
	radius = newRadius;
	ballStatus = myStartStatus;
	cantBallsInvisible = cantBalls;
}
void Ball::moveInMenu()
{

}
void Ball::setInPlayerBar(Vector2 playerPosition, float playerWidthSize,float newDistanceOfBar)
{
	position = { playerPosition.x, (playerPosition.y - newDistanceOfBar) };
}