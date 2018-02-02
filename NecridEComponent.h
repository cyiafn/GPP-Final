#pragma once
#ifndef _NECRIDECOMPONENT_H               // Prevent multiple definitions if this 
#define _NECRIDECOMPONENT_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"
#include "textureManager.h"
#include "constants.h"
#include "structure.h"

namespace NecridEComponentNS
{
	const int WIDTH = 50;                   // image width
	const int HEIGHT = 60;                  // image height
	const int TEXTURE_COLS = 5;           // texture has 1 columns
	const int EWALL_START_FRAME = 0;      // bullet starts at frame 0
	const int EWALL_END_FRAME = 9;       // bullet end at frame 9
	const int SPAWN_DISTANCE = 25;
	const float EWALL_ANIMATION_DELAY = 0.1; // No delay
	const int EWALL_DURATION = 300;	// range by frametime
}

class NecridEComponent
{
private:
	TextureManager EwallTexture;
	Structure *WaterWall;

public:
	NecridEComponent(Game *cipher);
	~NecridEComponent();
	void update(float frameTime);
	void draw();
	void releaseAll();
	void resetAll();
	int getDuration() { return NecridEComponentNS::EWALL_DURATION; }
	void activate(bool facingRight, float x, float y, Game *cipher);
};
#endif