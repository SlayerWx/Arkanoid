#include "menu.h"
#include "raylib.h"
#include "ArkanoidGame/arkanoid_game.h"
#include "ball/ball.h"
using namespace arkanoid;
Menu::Menu()
{
}
void Menu::init()
{

}
void Menu::update(Player* player,Ball* balls[])
{
	player->move();
	for (int i = 0; i < cantBalls; i++)
	{

	}
}
void Menu::draw(Player* player)
{
	player->drawMe();
	for (int i = 0; i < cantBalls; i++)
	{

	}
}