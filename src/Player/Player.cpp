#include "Player.h"
#include "raylib.h"
int Player::speed = 300;
Player::Player(Vector2 initialPosition, Vector2 newSize, int newLife,Texture2D newTexture)
{
	position = initialPosition;
	size = newSize;
	life = newLife;
	myTexture = newTexture;
	myColor = WHITE;
}

void Player::drawMe()
{
#if DEBUG
	//DrawRectangle(position.x, position.y, size.x, size.y, RED);
#endif
	DrawTexture(myTexture, position.x, position.y, myColor);
}

void Player::move()
{
	if(IsKeyDown(KEY_LEFT) && position.x> 0)
	{
		position.x -= speed * GetFrameTime();
	}
	if (IsKeyDown(KEY_RIGHT)&& position.x < GetScreenWidth() - size.x)
	{
		position.x += speed * GetFrameTime();
	}
}
Vector2 Player::playerPosition()
{
	return position;
}
Vector2 Player::playerSize()
{
	return size;
}
int Player::getSpeed()
{
	return speed;
}
bool Player::isShotBalls()
{
	if (IsKeyPressed(KEY_SPACE))
	{
		return true;
	}
	return false;
}
void Player::customColor(Color newCustom)
{
	myColor = newCustom;
}
Color Player::getCustomColor()
{
	return myColor;
}
