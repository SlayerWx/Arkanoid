#ifndef MENU_H
#define MENU_H
#include "Player/Player.h"
#include "ball/ball.h"
class Menu
{
public:
	Menu();
	void init();
	void update(Player* player,Ball* balls[]);
	void draw(Player* player);
private:
};
#endif