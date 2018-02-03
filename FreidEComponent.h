#pragma once
#ifndef _FREIDECOMPONENT_H               // Prevent multiple definitions if this 
#define _FREIDECOMPONENT_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"
#include <vector>
#include "textureManager.h"
#include "constants.h"
#include "platform.h"

namespace FreidEComponentNS
{
	const int WIDTH = 120;                   // image width
	const int HEIGHT = 20;                  // image height
	const int TEXTURE_COLS = 1;           // texture has 1 columns
	const int EPLATFORM_START_FRAME = 0;      // bullet starts at frame 0
	const int EPLATFORM_END_FRAME = 0;       // bullet end at frame 0
	const float EPLATFORM_ANIMATION_DELAY = 0; // No delay
	const int EPLATFORM_DURATION = 200;	// range by frametime
}

class FreidEComponent
{
private:
	TextureManager EplatformTexture;
	int platformTimer = 0;
	Platform *icePlatform;

public:
	FreidEComponent(Game *cipher);
	~FreidEComponent();
	void update(float frameTime);
	void draw();
	void releaseAll();
	void resetAll();
	int getDuration() { return FreidEComponentNS::EPLATFORM_DURATION; }
	void activate(bool facingRight, VECTOR2 center, Game *cipher);
};
#endif