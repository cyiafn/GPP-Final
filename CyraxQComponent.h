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
	const int WIDTH = 30;                   // image width
	const int HEIGHT = 30;                  // image height
	const int TEXTURE_COLS = 1;           // texture has 1 columns
	const int QBULLET_START_FRAME = 0;      // bullet starts at frame 0
	const int QBULLET_END_FRAME = 0;       // bullet end at frame 0
	const int QBULLET_MAX_RANGE = 800;	// range by frametime
	const float QBULLET_SPEED = 80;		// velocity.x for Bullet speed
}

class CyraxQComponent
{
private:
	TextureManager QbulletTexture;
	std::vector<Bullet> *bulletList;
	Bullet newBullet;
public:
	CyraxQComponent(Game *cipher);
	~CyraxQComponent();
	void update(float frameTime);
	void draw();
	void releaseAll();
	void resetAll();
	void activate(int facing, VECTOR2 center, Game *cipher);

};
#endif