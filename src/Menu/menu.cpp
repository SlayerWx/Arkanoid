#include "menu.h"
namespace menu
{
int distanceOfTheLeftEdgePlay = 20;
int distanceOfTheUpEdgeTitle = 50;
Menu::Menu(Texture2D newTitleTexture, Texture2D newPlayTexture, Texture2D newExitTexture)
{
	titleTexture = newTitleTexture;
	playTexture = newPlayTexture;
	exitTexture = newExitTexture;
	playIsPressed = false;
	closeGame = false;
	firstFrame = true;
}
GameScreen Menu::update(Player* player, Ball* ball)
{
	menuInit(player,ball);
	player->move();
	ball->ShotingMe(player->isShotBalls());
	colisionWithTexture(ball);
	ball->moveInMenu(player);
	if (playIsPressed)
	{
		playIsPressed = false;
		firstFrame = true;
		return OPTIONS;
		player->setLife(player->getMaxLife());
	}
	return MENU;
}
void Menu::draw(Player* player, Ball* ball)
{
	DrawTexture(playTexture, distanceOfTheLeftEdgePlay, GetScreenHeight() / 2, WHITE);
	DrawTexture(exitTexture, GetScreenWidth() - playTexture.width, GetScreenHeight() / 2, WHITE);
	player->drawMe();
	ball->drawMe();
	DrawTexture(titleTexture, (GetScreenWidth() / 2) - (titleTexture.width / 2), 
		distanceOfTheUpEdgeTitle, WHITE);
	DrawText("Arrows To Move and SpaceBar to Shot! Press B while playing to return to the menu!"
		,0,GetScreenHeight()-20,15,BLACK);

}
void Menu::colisionWithTexture(Ball* ball)
{
	//play
	if (ball->getPosition().x > distanceOfTheLeftEdgePlay && ball->getPosition().x < distanceOfTheLeftEdgePlay + 
		playTexture.width && ball->getPosition().y < (GetScreenHeight() / 2) + playTexture.height)
	{
		ball->setStatus(STAY);
		playIsPressed = true;
	}
	//exit
	if (ball->getPosition().x > GetScreenWidth() - playTexture.width && GetScreenWidth() - distanceOfTheLeftEdgePlay
		&&ball->getPosition().y < (GetScreenHeight() / 2) + exitTexture.height)
	{
		ball->setStatus(STAY);
		closeGame = true;
		
	}
	//nothing
	if (ball->getPosition().y < ball->getRadius() *-1.2)
		{
		ball->setStatus(STAY);
	}
}
bool Menu::exitCloseGame()
{
	if(closeGame)
	{
		return true;
	}
	return false;
}
void Menu::menuInit(Player* player, Ball* ball)
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
}