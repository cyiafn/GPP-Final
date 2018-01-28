#pragma once
#ifndef _AGENT47ECOMPONENT_H               // Prevent multiple definitions if this 
#define _AGENT47ECOMPONENT_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"


namespace Agent47EComponentNS
{

}

class Agent47EComponent
{
private:
	

public:
	Agent47EComponent();
	void update(float frameTime, Entity &ent);
};
#endif