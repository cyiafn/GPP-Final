#pragma once
#ifndef _AGENT47QCOMPONENT_H               // Prevent multiple definitions if this 
#define _AGENT47QCOMPONENT_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"
#include "textureManager.h"
#include "constants.h"
#include "bullet.h"

namespace Agent47QComponentNS
{
	const int WIDTH = 60;                   // image width
	const int HEIGHT = 40;                  // image height
	const int TEXTURE_COLS = 1;           // texture has 1 columns
	const int QPUNCH_START_FRAME = 0;      // bullet starts at frame 0
	const int QPUNCH_END_FRAME = 0;       // bullet end at frame 0
	const float QPUNCH_ANIMATION_DELAY = 0;
	const int QPUNCH_DURATION = 20;	// range by frametime
	const float QPUNCH_DAMAGE = 2.0f;
}

class Agent47QComponent
{
private:
	TextureManager QpunchTexture;
	Bullet* Punch;
	int current_Duration = 0;
	bool pow = false;

public:
	Agent47QComponent(Game *cipher);
	~Agent47QComponent();
	void update(float frameTime);
	void draw();
	void releaseAll();
	void resetAll();
	void activate(bool facingRight, float x, float y, Game *cipher);
	float hit(); //return damage;
	int getRange() { return Agent47QComponentNS::WIDTH; }
	Bullet* getPunch() { return Punch; }
};
#endif