#pragma once
#ifndef _CYRAXWCOMPONENT_H               // Prevent multiple definitions if this 
#define _CYRAXWCOMPONENT_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"
#include <vector>
#include "textureManager.h"
#include "constants.h"
#include "bullet.h"

namespace CyraxWComponentNS
{
	const int WIDTH = 30;                   // image width
	const int HEIGHT = 30;                  // image height
	const int TEXTURE_COLS = 2;           // texture has 1 columns
	const int WBULLET_START_FRAME = 0;      // bullet starts at frame 0
	const int WBULLET_END_FRAME = 1;       // bullet end at frame 1
	const float WBULLET_ANIMATION_DELAY = 1.0f; // Delay timer
	const int WBULLET_MAX_RANGE = 230;	// range by frametime
	const float WBULLET_MIN_SPEED = 80;		// velocity.x for Bullet speed
	const float WBULLET_MAX_SPEED = 400;		// velocity.x for Bullet speed
}

class CyraxWComponent
{
private:
	TextureManager WbulletTexture;
	std::vector<Bullet*> bulletList;

public:
	CyraxWComponent(Game *cipher);
	~CyraxWComponent();
	void update(float frameTime);
	void draw();
	void releaseAll();
	void resetAll();
	void activate(bool facingRight, float x, float y, Game *cipher);
	std::vector<Bullet*>* getBulletList() { return &bulletList; }
};
#endif