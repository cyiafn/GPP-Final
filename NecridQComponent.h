#pragma once
#ifndef _NECRIDQCOMPONENT_H               // Prevent multiple definitions if this 
#define _NECRIDQCOMPONENT_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"


namespace NecridQComponentNS
{

}

class NecridQComponent
{
private:


public:
	NecridQComponent();
	void update(float frameTime, Entity &ent);
};
#endif