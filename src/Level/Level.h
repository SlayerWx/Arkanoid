#ifndef LEVEL_H
#define LEVEL_H
#include "Player/Player.h"
#include "ball/ball.h"
class Level
{
public:
	Level();
	~Level();
	void update(Player* player, Ball* ball);
	void draw(Player* player, Ball* ball);
private:

};
#endif