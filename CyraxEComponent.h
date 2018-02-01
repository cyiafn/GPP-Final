#pragma once
#ifndef _CYRAXECOMPONENT_H               // Prevent multiple definitions if this 
#define _CYRAXECOMPONENT_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"
#include "textureManager.h"
#include "constants.h"

namespace CyraxEComponentNS
{
	const float TELEPORT_RANGE = 200;
}

class CyraxEComponent
{
private:


public:
	CyraxEComponent(Game *cipher);
	~CyraxEComponent();
	void update(float frameTime);
	void draw();
	void releaseAll();
	void resetAll();
	float activate(bool facingRight);
};
#endif