#include "Player.h"
#include "raylib.h"
int Player::speed = 300;
Player::Player(Vector2 initialPosition, Vector2 newSize, int newLife)
{
	position = initialPosition;
	size = newSize;
	life = newLife;
}

void Player::drawMe()
{
	DrawRectangle(position.x, position.y, size.x, size.y, BLACK);
}

void Player::move()
{
	if(IsKeyDown(KEY_LEFT))
	{
		position.x -= speed * GetFrameTime();
	}
	if (IsKeyDown(KEY_RIGHT))
	{
		position.x += speed * GetFrameTime();
	}
	if (IsKeyPressed(KEY_SPACE))
	{
		
	}
}