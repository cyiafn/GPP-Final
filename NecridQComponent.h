#pragma once
#ifndef _NECRIDQCOMPONENT_H               // Prevent multiple definitions if this 
#define _NECRIDQCOMPONENT_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"
#include <vector>
#include "textureManager.h"
#include "constants.h"
#include "bomb.h"

namespace NecridQComponentNS
{
	const int WIDTH = 30;                   // image width
	const int HEIGHT = 30;                  // image height
	const int TEXTURE_COLS = 1;           // texture has 1 columns
	const int QBOMB_START_FRAME = 0;      // bullet starts at frame 0
	const int QBOMB_END_FRAME = 0;       // bullet end at frame 0
	const int QBOMB_MAX_RANGE = 400;	// range by frametime
	const float QBOMB_DURATION = 180;	// velocity.x for Bullet speed
	const float QBOMB_ANGLE = 80.0f;
}

class NecridQComponent
{
private:
	TextureManager QbombTexture;
	std::vector<Bomb*> bombList;
	float angle = NecridQComponentNS::QBOMB_ANGLE * PI/180;

public:
	NecridQComponent(Game *cipher);
	~NecridQComponent();
	void update(float frameTime);
	void draw();
	void releaseAll();
	void resetAll();
	void activate(bool facingRight, VECTOR2 center, Game *cipher);
	int getRange() { return NecridQComponentNS::QBOMB_MAX_RANGE; }
	std::vector<Bomb*> *getBombList() { return &bombList; }
};
#endif