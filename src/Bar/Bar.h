#ifndef BAR_H
#define BAR_H
#include "raylib.h"
namespace Brick
{
enum BarState
{
	VISIBLE, INVISIBLE
};
class Bar
{
public:
	static int distanceBallIncideMe;
	static int getDistanceBallIncideBar();
	static float ratioReductionTexture;
	Bar(BarState newBarState);
	~Bar();
	void setPosition(int x, int y);
	Vector2 getPosition();
	BarState barStatus;
	void setStatus(BarState newStatus);
	BarState getStatus();
	int getWidth();
	int getHeigth();
	void showMe();
private:
	Texture2D mySkin;
	Vector2 position;
};
}
#endif