#include "Player.h"
Player::Player(Vector2 initialPosition, Vector2 newSize, int newLife,int newSpeed)
{
	position = initialPosition;
	size = newSize;
	life = newLife;
	speed = newSpeed;
}