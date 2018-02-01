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
	const int QBULLET_START_FRAME = 0;      // bullet starts at frame 0
	const int QBULLET_END_FRAME = 0;       // bullet end at frame 0
	const int QBULLET_MAX_RANGE = 800;	// range by frametime
	const float QBULLET_SPEED = 80;		// velocity.x for Bullet speed
}

class NecridQComponent
{
private:
	TextureManager QbombTexture;
	std::vector<Bomb*> bombList;
	Bomb newBullet;

public:
	NecridQComponent(Game *cipher);
	~NecridQComponent();
	void update(float frameTime);
	void draw();
	void releaseAll();
	void resetAll();
	void activate(bool facingRight, VECTOR2 center, Game *cipher);
};
#endif