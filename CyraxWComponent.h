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

namespace CyraxWComponentNS
{
	const int X = GAME_WIDTH / 2;			// location on screen
	const int Y = GAME_HEIGHT / 2;			// location on screen
}

class CyraxWComponent
{
private:


public:
	CyraxWComponent(Game *cipher);
	~CyraxWComponent();
	void update(float frameTime);
	void draw();
	void releaseAll();
	void resetAll();
	void activate(int facing, VECTOR2 center, Game *cipher);
};
#endif