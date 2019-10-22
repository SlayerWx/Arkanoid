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
	mySkin.width = static_cast<int>(ratioReductionTexture * 3);//mySkin.width / ratioReductionTexture;
	mySkin.height = static_cast<int>(ratioReductionTexture);//mySkin.height / ratioReductionTexture;
	position.x = 0;
	position.y = 0;
}
void Bar::setPosition(int x, int y)
{
	position.x = static_cast<float>(x);
	position.y = static_cast<float>(y);
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
		DrawTexture(mySkin, static_cast<int>(position.x), static_cast<int>(position.y), WHITE);
	}
}
int Bar::getDistanceBallIncideBar()
{
	return distanceBallIncideMe;
}
}