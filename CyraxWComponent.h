#pragma once
#ifndef _CYRAXWCOMPONENT_H               // Prevent multiple definitions if this 
#define _CYRAXWCOMPONENT_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"


namespace CyraxWComponentNS
{
	const int X = GAME_WIDTH / 2;			// location on screen
	const int Y = GAME_HEIGHT / 2;			// location on screen
}

class CyraxWComponent
{
private:


public:
	CyraxWComponent();
	void update(float frameTime, Entity &ent);
};
#endif