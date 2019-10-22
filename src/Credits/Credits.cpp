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
	DrawTexture(backTexture, GetScreenWidth() - backTexture.width, GetScreenHeight() / 2, WHITE);
	DrawText("Option Texture: es.cooltext.com", GetScreenWidth() / 4, 15, 30, BLACK);
	DrawText("Programmer: Ruffo Maximiliano", GetScreenWidth() / 4, 45, 30, BLACK);
	DrawText("Assets: Kenney.nl", GetScreenWidth()/3, 85, 30, BLACK);
	if (player->getLife() > 0)
	{
		DrawText("YOU WIN!", GetScreenWidth() / 3, 105, 30, BLACK);
	}
	else
	{
		DrawText("YOU LOSE!", GetScreenWidth() / 3, 205, 30, BLACK);
	}
}
void Credits::colisionWithTexture(Ball* ball)
{
	//Back
	if (ball->getPosition().x > GetScreenWidth() - backTexture.width && GetScreenWidth() - distanceOfTheLeftEdgePlay
		&&ball->getPosition().y < (GetScreenHeight() / 2) + backTexture.height)
	{
		ball->setStatus(STAY);
		backIsPressed = true;
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