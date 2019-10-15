#include "options.h"
namespace options
{
int distanceOfTheLeftEdgePlay = 20;
int distanceOfTheUpEdgeTitle = 50;
int distanceOfRGB = 200;
int distanceOfYRGB = 70;
int selectorRGB = 20;
int selectorPercentRGB = -1;
bool rgbOptionSwitchBool = false;
Options::Options(Texture2D newPlayTexture, Texture2D newBackTexture,Texture2D _RGB[], Texture2D newRGBPorcentTexture[],Texture2D newRGBtexture)
{
	playTexture = newPlayTexture;
	BackTexture = newBackTexture;
	IsPressedToGameplay = false;
	IsPressedToBack = false;
	playTexture.width = static_cast<int>(playTexture.width / 2.5f);
	playTexture.height = static_cast<int>(playTexture.height / 2);
	BackTexture.width = static_cast<int>(BackTexture.width / 2.5);
	BackTexture.height = static_cast<int>(BackTexture.height / 2);
	RGBtexture = newRGBtexture;
	RGBtexture.width = playTexture.width;
	RGBtexture.height = playTexture.height;
	for (int i = 0; i < countLetterRGB; i++)
	{
		RGB[i] = _RGB[i];
	}
	for (int i = 0; i < countPercentRGB; i++)
	{
		RGBPorcentTexture[i] = newRGBPorcentTexture[i];
		RGBPorcentTexture[i].width = static_cast<int>(RGBPorcentTexture[i].width /2.9f);
		RGBPorcentTexture[i].height = static_cast<int>(RGBPorcentTexture[i].width / 2);
	}
	customisedColor = RED;
	RGBPercentTurn = false;
	rgbOptionSwitchBool = false;
}
GameScreen Options::update(Player* player, Ball* ball)
{
	player->move();
	ball->ShotingMe(player->isShotBalls());
	colisionWithTexture(ball);
	ball->moveInMenu(player);
	player->customColor(RGBpercentSelector(player->getCustomColor()));
	if (IsPressedToGameplay)
	{
		IsPressedToGameplay = false;
		return GAMEPLAY;
	}
	if (IsPressedToBack)
	{
		IsPressedToBack = false;
		return MENU;
	}
	return OPTIONS;
}
void Options::draw(Player* player, Ball* ball)
{
	DrawTexture(playTexture, distanceOfTheLeftEdgePlay, GetScreenHeight() / 2, WHITE);
	switch (rgbOptionSwitchBool)
	{
	case false:
		DrawTexture(BackTexture, GetScreenWidth() - playTexture.width - distanceOfTheLeftEdgePlay, GetScreenHeight() / 2, WHITE);
		break;
	case true:
		DrawTexture(RGBtexture,GetScreenWidth() - RGBtexture.width- distanceOfTheLeftEdgePlay,GetScreenHeight()/2, RAYWHITE);
		break;
	}
	player->drawMe();
	ball->drawMe();
	for (int i = 0; i < countLetterRGB; i++)
	{
		DrawTexture(RGB[i], static_cast<int>((GetScreenWidth()/2 - distanceOfRGB * 1.20f)) + (distanceOfRGB * i), distanceOfYRGB,RAYWHITE);
	}
	if (RGBPercentTurn)
	{
		for (int i = 0; i < countPercentRGB; i++)
		{
			DrawTexture(RGBPorcentTexture[i], (distanceOfTheLeftEdgePlay + playTexture.width) +
				(RGBPorcentTexture[0].width * i), GetScreenHeight() / 2, RAYWHITE);
		}
	}


}
void Options::colisionWithTexture(Ball* ball)
{
	//play
	if (ball->getPosition().x > distanceOfTheLeftEdgePlay && ball->getPosition().x < distanceOfTheLeftEdgePlay + playTexture.width &&
		ball->getPosition().y < (GetScreenHeight() / 2) + playTexture.height)
	{
		ball->setStatus(STAY);
		IsPressedToGameplay = true;
	}
	switch (rgbOptionSwitchBool)
	{
	case false:
		//Back
		if (ball->getPosition().x > GetScreenWidth() - BackTexture.width - distanceOfTheLeftEdgePlay - 3 &&
			ball->getPosition().x < GetScreenWidth() - distanceOfTheLeftEdgePlay &&
			ball->getPosition().y < (GetScreenHeight() / 2) + BackTexture.height)
		{
			ball->setStatus(STAY);
			IsPressedToBack = true;
		}
		break;
	case true:
		//RGBoptionBack
		if (ball->getPosition().x > GetScreenWidth() - RGBtexture.width - distanceOfTheLeftEdgePlay - 3 &&
			ball->getPosition().x < GetScreenWidth() - distanceOfTheLeftEdgePlay &&
			ball->getPosition().y < (GetScreenHeight() / 2) + RGBtexture.height)
		{
			ball->setStatus(STAY);
			RGBPercentTurn = false;
			selectorRGB = -1;
			rgbOptionSwitchBool = false;
		}
		break;
	}
	//RGB
	for (int i = 0; i < countLetterRGB; i++)
	{
		if (ball->getPosition().x > (GetScreenWidth() / 2 - distanceOfRGB * 1.20) + (distanceOfRGB * i) 
			&& ball->getPosition().x < (GetScreenWidth() / 2 - distanceOfRGB * 1.20) + (distanceOfRGB * i) + RGB[i].width &&
			ball->getPosition().y < distanceOfYRGB + RGB[i].height)
		{
			ball->setStatus(STAY);
			selectorRGB = i;
			RGBPercentTurn = true;
			rgbOptionSwitchBool = true;
		}
	}
	//percentRGB
	if (RGBPercentTurn)
	{
		for (int i = 0; i < countPercentRGB; i++)
		{
			if (ball->getPosition().x > (distanceOfTheLeftEdgePlay + playTexture.width) + (RGBPorcentTexture[0].width * i)
				&& ball->getPosition().x < (distanceOfTheLeftEdgePlay * 1.9f + playTexture.width) + (RGBPorcentTexture[0].width * i) +
				RGBPorcentTexture[i].width && ball->getPosition().y < GetScreenHeight() / 2 + RGBPorcentTexture[i].height
				&& ball->getPosition().y > GetScreenHeight() / 2)
			{
				ball->setStatus(STAY);
				selectorPercentRGB = i * 10;
			}

		}
	}
	//nothing
	if (ball->getPosition().y < ball->getRadius() *-1.2)
	{
		ball->setStatus(STAY);
	}
}
Color Options::RGBpercentSelector(Color actualPlayerColor)
{
	switch (selectorRGB)
	{
	case RGBisR:
		if (selectorPercentRGB > -1) 
		{ 
			actualPlayerColor.r = GetpercentRGB();
		}
		break;
	case RGBisG:
		if (selectorPercentRGB > -1)
		{
			actualPlayerColor.g = GetpercentRGB();
		}
		break;
	case RGBisB:
		if (selectorPercentRGB > -1)
		{
			actualPlayerColor.b = GetpercentRGB();
		}
		break;
	default:
		break;
	}
	return actualPlayerColor;
}
int Options::GetpercentRGB()
{
	int aux = selectorPercentRGB;
	selectorPercentRGB = -1;
	return static_cast<int>(255 * (aux * 0.01f));
}
Options::~Options()
{
}
}