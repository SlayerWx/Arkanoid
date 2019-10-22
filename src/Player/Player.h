#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
class Player
{
private:
	Vector2 position;
	Vector2 size;
	static int speed;
	Texture2D myTexture;
	Texture2D myLifeTexture;
	Color myColor;
	int life;
	int maxLife;
public:
	Player(Vector2 initialPosition,Vector2 newSize,int newLife,Texture2D newTexture);
	void drawMe();
	void move();
	Vector2 playerPosition();
	Vector2 playerSize();
	void setPlayerPosition(float x, float y);
	static int getSpeed();
	bool isShotBalls();
	void customColor(Color newCustom);
	Color getCustomColor();
	int getLife();
	void setLife(int newLife);
	bool backToMenu();
	Texture2D GetBody();
	Texture2D GetLifeBody();
	int getMaxLife();
};
#endif

