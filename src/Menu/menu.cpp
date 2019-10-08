#include "menu.h"
#include "raylib.h"
#include "ArkanoidGame/arkanoid_game.h"
bool Menu::inMenu = true;
using namespace arkanoid;
Menu::Menu()
{
	inMenu = true;
}
void Menu::loop()
{
	Player* player = new Player({ static_cast<float>(ArkanoidGame::getGameScreenWidth())/2,
								  static_cast<float>(ArkanoidGame::getGameScreenHeight())-15}, 
								{ 10,10 }, 1);
	init();
	while (inMenu)
	{
		update(player);
		draw(player);
	}
}
void Menu::init()
{

}
void Menu::update(Player* player)
{
	player->move();
}
void Menu::draw(Player* player)
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	player->drawMe();
	EndDrawing();
}