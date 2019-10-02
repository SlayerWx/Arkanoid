#include "ball.h"
Ball::Ball(Vector2 initialPosition, Vector2 newSpeed, int newRadius, bool isActive)
{
	position = initialPosition;
	speed = newSpeed;
	radius = newRadius;
	active = isActive;
}