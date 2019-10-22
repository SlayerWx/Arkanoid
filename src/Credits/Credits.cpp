#include "Credits.h"
int distanceOfTheLeftEdgePlay = 20;
int distanceOfTheUpEdgeTitle = 50;
Credits::Credits(Texture2D newBackTexture)
{
	backTexture = newBackTexture;
	backIsPressed = false;
	firstFrame = true;
}
GameScreen Credits::update(Player* player, Ball* ball)
{
	creditInit(player,ball);
	player->move();
	ball->ShotingMe(player->isShotBalls());
	colisionWithTexture(ball);
	ball->moveInMenu(player);
	if (backIsPressed)
	{
		backIsPressed = false;
		firstFrame = true;
		return MENU;
	}
	return CREDITS;
}
void Credits::draw(Player* player, Ball* ball)
{
	player->drawMe();
	ball->drawMe();
	DrawText("a",0,GetScreenHeight()-20,15,BLACK);
}
void Credits::colisionWithTexture(Ball* ball)
{
	//Back
	if (ball->getPosition().x > GetScreenWidth() - backTexture.width && GetScreenWidth() - distanceOfTheLeftEdgePlay
		&&ball->getPosition().y < (GetScreenHeight() / 2) + backTexture.height)
	{
		ball->setStatus(STAY);
		
	}
	//nothing
	if (ball->getPosition().y < ball->getRadius() *-1.2)
		{
		ball->setStatus(STAY);
	}
}
void Credits::creditInit(Player* player, Ball* ball)
{
	if (firstFrame)
	{
		ball->setStatus(STAY);
		ball->revertToPositiveSpeedY();
		player->setPlayerPosition(static_cast<float>((GetScreenWidth()/2)- (player->GetBody().width / 2)),
			player->playerPosition().y);
		firstFrame = false;
	}
}