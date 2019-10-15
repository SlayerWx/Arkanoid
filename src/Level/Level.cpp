#include "Level.h"
Level::Level()
{
}
void Level::update(Player* player, Ball* ball)
{

}
void Level::draw(Player* player, Ball* ball)
{
	player->drawMe();
	ball->drawMe();
}
Level::~Level()
{
}