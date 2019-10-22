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
	DrawRectangle(static_cast<int>(position.x), static_cast<int>(position.y), static_cast<int>(size.x), 
		static_cast<int>(size.y), RED);
#endif
	DrawTexture(myTexture, static_cast<int>(position.x), static_cast<int>(position.y), myColor);
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
bool Player::backToMenu()
{
	if (IsKeyDown(KEY_B))
	{
		return true;
	}
	return false;
}
Vector2 Player::playerPosition()
{
	return position;
}
void Player::setPlayerPosition(float x,float y)
{
	position.x = x;
	position.y = y;
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
int Player::getLife()
{
	return life;
}
void Player::setLife(int newLife)
{
	life = newLife;
}
Texture2D Player::GetBody()
{
	return myTexture;
}