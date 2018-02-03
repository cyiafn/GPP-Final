#pragma once
#ifndef _AGENT47WCOMPONENT_H               // Prevent multiple definitions if this 
#define _AGENT47WCOMPONENT_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"
#include "textureManager.h"
#include "constants.h"
#include "bullet.h"
#include "structure.h"

namespace Agent47WComponentNS
{
	const int WIDTH1 = 50;                   // image width
	const int HEIGHT1 = 50;                  // image height
	const int WIDTH2 = 50;                   // image width
	const int HEIGHT2 = 100;                  // image height
	const int TEXTURE_COLS = 1;           // texture has 1 columns
	const int WZAP_START_FRAME = 0;      // bullet starts at frame 0
	const int WZAP_END_FRAME = 0;       // bullet end at frame 0
	const int WSTONE_START_FRAME = 0;      // bullet starts at frame 0
	const int WSTONE_END_FRAME = 0;       // bullet end at frame 0
	const float WZAP_ANIMATION_DELAY = 0;
	const int WZAP_DURATION = 30;	// range by frametime
	const int WSTONE_DURATION = 150;	// range by frametime
	const int SPAWN_DISTANCE = 75;
	const float WZAP_DAMAGE = 10.0f;
}

class Agent47WComponent
{
private:
	TextureManager WzapTexture;
	TextureManager WstoneTexture;
	Bullet* Electrocute;
	Structure* tombstone;
	int current_Duration = 0;
	bool zap = false;

public:
	Agent47WComponent(Game *cipher);
	~Agent47WComponent();
	void update(float frameTime);
	void draw();
	void releaseAll();
	void resetAll();
	void activate(bool facingRight, float x, float y, Game *cipher);
	float hit();
	int getRange() { return Agent47WComponentNS::WIDTH1; }
	Bullet* getPunch() { return Electrocute; }
};
#endif