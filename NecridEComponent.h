#ifndef _NECRIDECOMPONENT_H               // Prevent multiple definitions if this 
#define _NECRIDECOMPONENT_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"


namespace NecridEComponentNS
{

}

class NecridEComponent
{
private:


public:
	NecridEComponent();
	void update(float frameTime, Entity &ent);
};
#endif