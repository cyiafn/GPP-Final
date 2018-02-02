#pragma once
#ifndef _FREIDWCOMPONENT_H               // Prevent multiple definitions if this 
#define _FREIDWCOMPONENT_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"
#include <vector>
#include <math.h>
#include "textureManager.h"
#include "constants.h"
#include "bullet.h"

namespace FreidWComponentNS
{
	const int WIDTH = 40;                   // image width
	const int HEIGHT = 40;                  // image height
	const int TEXTURE_COLS = 1;           // texture has 1 columns
	const int WCOMET_START_FRAME = 0;      // bullet starts at frame 0
	const int WCOMET_END_FRAME = 0;       // bullet end at frame 0
	const float WCOMET_ANIMATION_DELAY = 0; // No delay
	const int WCOMET_MAX_DURATION = 300;	// range by frametime
	const float WCOMET_START = 300;		// velocity.x for Bullet speed
	const float WCOMET_RANGE = 300;
}

class FreidWComponent
{
private:
	TextureManager WcometTexture;
	std::vector<Bullet*> cometList;

public:
	FreidWComponent(Game *cipher);
	~FreidWComponent();
	void update(float frameTime);
	void draw();
	void releaseAll();
	void resetAll();
	void activate(bool facingRight, VECTOR2 center, Game *cipher);
	int getRange() { return FreidWComponentNS::WCOMET_RANGE; }
	std::vector<Bullet*> *getCometList() { return &cometList; }
};
#endif