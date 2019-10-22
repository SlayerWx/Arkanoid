#include "Level.h"
int diferenceSpaceSideBar = 2;
Level::Level()
{
	visibleBarNumber = 0;
	for (int i = 0; i < countBarHeight;i++)
	{
		for (int t = 0; t < countBarWidth;t++)
		{
			map[i][t] = new Brick::Bar(Brick::INVISIBLE);
		}
	}
}
void Level::init(Player* player, Ball* ball[])
{
	player->setPlayerPosition(GetScreenWidth()/2.0f,player->playerPosition().y * 1.0f);
}
void Level::update(Player* player, Ball* ball[], int currentLevel, int cantLevelsInGame)
{
	player->move();
	for (int i = 0; i < Ball::getLength(); i++)
	{
		ball[i]->ShotingMe(player->isShotBalls());
		ball[i]->move(player);
	}
	CheckColisionBarWithBalls(ball,currentLevel, cantLevelsInGame);
}
void Level::draw(Player* player, Ball* ball[], int currentLevel, int cantLevelsInGame)
{
	if (currentLevel < cantLevelsInGame)
	{
		for (int i = 0; i < player->getLife(); i++)
		{
			DrawTexture(player->GetLifeBody(), i *player->GetLifeBody().width, GetScreenHeight()
				- player->GetLifeBody().height, player->getCustomColor());
		}
		player->drawMe();
		for (int i = 0; i < Ball::getLength(); i++)
		{
			ball[i]->drawMe();
		}
		for (int i = 0; i < countBarHeight; i++)
		{
			for (int t = 0; t < countBarWidth; t++)
			{
				if (map[i][t]->getStatus() == Brick::VISIBLE)
				{
					map[i][t]->showMe();
				}
			}
		}
	}
}
void Level::CheckColisionBarWithBalls(Ball* ball[], int currentLevel, int cantLevelsInGame)
{
	if (currentLevel < cantLevelsInGame)
	{
		for (int i = 0; i < countBarHeight; i++)
		{
			for (int t = 0; t < countBarWidth; t++)
			{
				for (int e = 0; e < Ball::getLength(); e++)
				{
					if (ball[e]->getStatus() == MOVE && map[i][t]->getStatus() == Brick::VISIBLE)
					{
						if (ball[e]->getPosition().y - ball[e]->getRadius() < map[i][t]->getPosition().y +
							map[i][t]->getHeigth() &&
							ball[e]->getPosition().y - ball[e]->getRadius() > map[i][t]->getPosition().y +
							map[i][t]->getHeigth() - map[i][t]->getDistanceBallIncideBar() &&
							ball[e]->getPosition().x + ball[e]->getRadius() > map[i][t]->getPosition().x &&
							ball[e]->getPosition().x - ball[e]->getRadius() < map[i][t]->getPosition().x +
							map[i][t]->getWidth())
						{
							ball[e]->revertToPositiveSpeedY();
							map[i][t]->setStatus(Brick::INVISIBLE);
							visibleBarNumber--;
						}
						if (ball[e]->getPosition().y + ball[e]->getRadius() > map[i][t]->getPosition().y &&
							ball[e]->getPosition().y + ball[e]->getRadius() < map[i][t]->getPosition().y
							+ map[i][t]->getDistanceBallIncideBar() &&
							ball[e]->getPosition().x + ball[e]->getRadius() > map[i][t]->getPosition().x &&
							ball[e]->getPosition().x - ball[e]->getRadius() < map[i][t]->getPosition().x +
							map[i][t]->getWidth())
						{
							ball[e]->revertToNegativeSpeedY();
							map[i][t]->setStatus(Brick::INVISIBLE);
							visibleBarNumber--;
						}
						//////////////////////////////////
						if (ball[e]->getPosition().x - ball[e]->getRadius() < map[i][t]->getPosition().x +
							map[i][t]->getWidth() &&
							ball[e]->getPosition().x - ball[e]->getRadius() > map[i][t]->getPosition().x +
							map[i][t]->getWidth() - map[i][t]->getDistanceBallIncideBar() &&
							ball[e]->getPosition().y + ball[e]->getRadius() > map[i][t]->getPosition().y &&
							ball[e]->getPosition().y - ball[e]->getRadius() < map[i][t]->getPosition().y +
							map[i][t]->getHeigth())
						{
							ball[e]->revertToNegativeSpeedX();
							map[i][t]->setStatus(Brick::INVISIBLE);
							visibleBarNumber--;
						}
						if (ball[e]->getPosition().x + ball[e]->getRadius() > map[i][t]->getPosition().x &&
							ball[e]->getPosition().x + ball[e]->getRadius() < map[i][t]->getPosition().x +
							map[i][t]->getDistanceBallIncideBar() &&
							ball[e]->getPosition().y - ball[e]->getRadius() < map[i][t]->getPosition().y &&
							ball[e]->getPosition().y + ball[e]->getRadius() > map[i][t]->getPosition().y)
						{
							ball[e]->revertToPositiveSpeedX();
							map[i][t]->setStatus(Brick::INVISIBLE);
							visibleBarNumber--;
						}

					}
				}
			}
		}
	}
}
void Level::setLevel(Brick::BarState newMapLogic[countBarHeight][countBarWidth])
{
	for (int i = 0; i < countBarHeight; i++)
	{
		for (int t = 0; t < countBarWidth; t++)
		{
			if (newMapLogic[i][t] == Brick::VISIBLE)
			{
				visibleBarNumber++;
			}
			map[i][t]->setStatus(newMapLogic[i][t]);
			map[i][t]->setPosition(diferenceSpaceSideBar+t*map[i][t]->getWidth(),i*map[i][t]->getHeigth());
		}
	}
}
Level::~Level()
{
	for (int i = 0; i < countBarHeight; i++)
	{
		for (int t = 0; t < countBarWidth; t++)
		{
			if(map[i][t])
			delete map[i][t];
		}
	}
}
bool Level::AllBarInvisible(Ball* ball[], int currentLevel, int cantLevelsInGame)
{
	if (currentLevel < cantLevelsInGame)
	{
		if (visibleBarNumber < 1)
		{
			for (int i = 0; i < ball[0]->getLength(); i++)
			{
				ball[i]->setStatus(INVISIBLE);
				if (i == 0)
				{
					ball[i]->setStatus(STAY);
				}
			}
			return true;
		}
	}
	return false;
}