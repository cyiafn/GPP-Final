#pragma once
#ifndef _AGENT47WCOMPONENT_H               // Prevent multiple definitions if this 
#define _AGENT47WCOMPONENT_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"


namespace Agent47WComponentNS
{

}

class Agent47WComponent
{
private:


public:
	Agent47WComponent();
	void update(float frameTime, Entity &ent);
};
#endif