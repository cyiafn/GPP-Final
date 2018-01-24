#pragma once
#ifndef _CYRAXQCOMPONENT_H               // Prevent multiple definitions if this 
#define _CYRAXQCOMPONENT_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"
#include <vector>
#include "textureManager.h"
#include "constants.h"
#include "bullet.h"

namespace CyraxQComponentNS
{
	const int WIDTH = 60;                   // image width
	const int HEIGHT = 20;                  // image height
	const int TEXTURE_COLS = 3;           // texture has 2 columns
	const int X = GAME_WIDTH / 2;			// location on screen
	const int Y = GAME_HEIGHT / 2;			// location on screen
	const int QBULLET_START_FRAME = 2;      // bullet starts at frame 2
	const int QBULLET_END_FRAME = 2;       // bullet end at frame 2
}

class CyraxQComponent
{
private:
	TextureManager QbulletTexture;
	std::vector<Bullet> *bulletList;
	Bullet *Qbullet;
	int MaxRange = 500;
	int CurRange = 0;

public:
	CyraxQComponent(Game *cipher);
	~CyraxQComponent();
	void update(float frameTime);
	void draw();
	void releaseAll();
	void resetAll();
};
#endif