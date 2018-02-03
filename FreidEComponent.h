#pragma once
#ifndef _FREIDECOMPONENT_H               // Prevent multiple definitions if this 
#define _FREIDECOMPONENT_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"
#include "constants.h"

namespace FreidEComponentNS
{
	const float TELEPORT_RANGE = 200;
}

class FreidEComponent
{
private:

public:
	FreidEComponent(Game *cipher);
	~FreidEComponent();
	void update(float frameTime);
	void draw();
	void releaseAll();
	void resetAll();
	int getRange() { return FreidEComponentNS::TELEPORT_RANGE; }
	float activate(bool facingRight);
};
#endif