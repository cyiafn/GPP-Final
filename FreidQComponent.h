#pragma once
#ifndef _FREIDQCOMPONENT_H               // Prevent multiple definitions if this 
#define _FREIDQCOMPONENT_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"
#include <vector>
#include "textureManager.h"
#include "constants.h"
#include "bullet.h"

namespace FreidQComponentNS
{
	const int WIDTH = 30;                   // image width
	const int HEIGHT = 30;                  // image height
	const int TEXTURE_COLS = 3;           // texture has 1 columns
	const int QARROW_TOP_FRAME = 0;      // bullet starts at frame 0
	const int QARROW_MID_FRAME = 1;      // bullet starts at frame 1
	const int QARROW_BOT_FRAME = 2;      // bullet starts at frame 2
	const int QARROW_MAX_RANGE = 800;	// range by frametime
	const float QARROW_SPEED = 250;		// velocity.x for Bullet speed
	const float QARROW_DIAGONAL = 150;		// velocity.x for Bullet speed
}

class FreidQComponent
{
private:
	TextureManager QbulletTexture;
	std::vector<Bullet> *arrowList;

public:
	FreidQComponent(Game *cipher);
	~FreidQComponent();
	void update(float frameTime);
	void draw();
	void releaseAll();
	void resetAll();
	void activate(bool facingRight, float x, float y, Game *cipher);
};
#endif