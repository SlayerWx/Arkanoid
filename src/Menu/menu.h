#ifndef MENU_H
#define MENU_H
#include "Player/Player.h"
class Menu
{
public:
	Menu();
	void loop();
	static bool inMenu;
private:
	void init();
	void update(Player* player);
	void draw(Player* player);
};
#endif