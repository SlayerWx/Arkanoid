#include "Bar.h"
namespace Brick
{
int Bar::distanceBallIncideMe = 3;
float Bar::ratioReductionTexture = 17.8f;
Bar::Bar(BarState newBarState)
{
	mySkin = LoadTexture("resource/assets/img/Kenney.nl/png/bar.png");
	barStatus = newBarState;
	remberFirstStatus = newBarState;
	mySkin.width = ratioReductionTexture * 3;//mySkin.width / ratioReductionTexture;
	mySkin.height = ratioReductionTexture;//mySkin.height / ratioReductionTexture;
	position.x = 0;
	position.y = 0;
}
void Bar::setPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}
void Bar::setStatus(BarState newStatus)
{
	barStatus = newStatus;
}
BarState Bar::getStatus()
{
	return barStatus;
}
Vector2 Bar::getPosition()
{
	return position;
}
int Bar::getWidth()
{
	return mySkin.width;
}
int Bar::getHeigth()
{
	return mySkin.height;
}
Bar::~Bar()
{
}
void Bar::showMe()
{
	if (barStatus == VISIBLE)
	{
		DrawTexture(mySkin, position.x, position.y, WHITE);
	}
}
int Bar::getDistanceBallIncideBar()
{
	return distanceBallIncideMe;
}
}